/*
 * eventlog.h - Persistent event log on internal flash (LittleFS)
 *
 * For power-only field tests without a serial cable: state changes, button
 * edges and every WARN/ERROR log line are written to /events.log and can be
 * read back later with the serial 'logfile dump' command.
 *
 * Lines are buffered in RAM (callable from either core, never blocks) and
 * flushed from loop(). While driving, flushing waits until the buffer is
 * mostly full, so flash writes don't stall input handling.
 * When the file exceeds EVENTLOG_MAX_BYTES it becomes /events.old and the
 * previous .old is dropped.
 */

#ifndef EVENTLOG_H
#define EVENTLOG_H

#include <Arduino.h>
#include <LittleFS.h>
#include <esp_system.h>
#include "button.h"
#include "nvs_config.h"
#include "version.h"
#include "Logger.h"

#define EVENTLOG_FILE       "/events.log"
#define EVENTLOG_OLD        "/events.old"
#define EVENTLOG_MAX_BYTES  (400 * 1024)
#define EVENTLOG_BUF_BYTES  4096
#define EVENTLOG_FLUSH_MS   1000

static char         _elBuf[EVENTLOG_BUF_BYTES];
static size_t       _elLen = 0;
static uint32_t     _elDropped = 0;
static bool         _elReady = false;
static uint16_t     _elBoot = 0;
static uint32_t     _elLastFlushMs = 0;
static portMUX_TYPE _elMux = portMUX_INITIALIZER_UNLOCKED;

inline void eventLogf(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
inline void eventLogf(const char* fmt, ...) {
    char line[300];
    uint32_t ms = millis();
    int n = snprintf(line, sizeof(line), "[%u %lu.%03lu] ", _elBoot,
        (unsigned long)(ms / 1000), (unsigned long)(ms % 1000));
    va_list args;
    va_start(args, fmt);
    n += vsnprintf(line + n, sizeof(line) - n - 1, fmt, args);
    va_end(args);
    if (n > (int)sizeof(line) - 2) n = sizeof(line) - 2;
    line[n++] = '\n';

    portENTER_CRITICAL(&_elMux);
    if (_elLen + n <= sizeof(_elBuf)) {
        memcpy(_elBuf + _elLen, line, n);
        _elLen += n;
    }
    else {
        _elDropped++;
    }
    portEXIT_CRITICAL(&_elMux);
}

inline void _eventLogSink(LogLevel level, uint32_t tag, const char* msg) {
    eventLogf("%s %s %s", Logger::levelString(level), Logger::tagString(tag), msg);
}

inline void eventLogFlush() {
    if (!_elReady) return;
    static char out[EVENTLOG_BUF_BYTES];
    size_t len;
    uint32_t dropped;
    portENTER_CRITICAL(&_elMux);
    len = _elLen;
    memcpy(out, _elBuf, len);
    _elLen = 0;
    dropped = _elDropped;
    _elDropped = 0;
    portEXIT_CRITICAL(&_elMux);
    _elLastFlushMs = millis();
    if (len == 0 && dropped == 0) return;

    File f = LittleFS.open(EVENTLOG_FILE, FILE_APPEND);
    if (!f) return;
    f.write((const uint8_t*)out, len);
    if (dropped) f.printf("[%u] %lu lines dropped (buffer full)\n", _elBoot, (unsigned long)dropped);
    size_t size = f.size();
    f.close();

    if (size > EVENTLOG_MAX_BYTES) {
        LittleFS.remove(EVENTLOG_OLD);
        LittleFS.rename(EVENTLOG_FILE, EVENTLOG_OLD);
    }
}

// Call early in setup(), before anything worth logging
inline void eventLogInit() {
    Logger::instance().setSink(_eventLogSink, LogLevel::WARN);
    if (!LittleFS.begin(/*formatOnFail=*/true)) {
        Logger::instance().logForced(LogLevel::WARN, TAG_SYSTEM, __FILE__, __LINE__,
            "Event log: LittleFS mount failed, logging to RAM only");
        return;
    }
    uint16_t boot = 0;
    nvsLoadU16("boot_cnt", &boot);
    _elBoot = boot + 1;
    nvsSaveU16("boot_cnt", _elBoot);
    _elReady = true;
    eventLogf("BOOT %s reset=%d", FW_VERSION_STRING, (int)esp_reset_reason());
}

// Call every loop(); flushing is deferred while driving unless the buffer fills up
inline void eventLogTick(uint32_t nowMs, bool driving) {
    static Button* const btns[] = { &btnEstop, &btnHillHold, &btnAssist, &btnPower };
    static const char* const names[] = { "E-stop", "Hill-Hold", "Assist", "Power" };
    static bool held[4] = { false, false, false, false };
    static uint32_t downMs[4] = { 0, 0, 0, 0 };
    for (int i = 0; i < 4; i++) {
        bool h = btns[i]->isHeld();
        if (h == held[i]) continue;
        held[i] = h;
        if (h) {
            downMs[i] = nowMs;
            eventLogf("BTN %s down", names[i]);
        }
        else {
            eventLogf("BTN %s up %lums", names[i], (unsigned long)(nowMs - downMs[i]));
        }
    }

    size_t len = _elLen;
    bool due = (nowMs - _elLastFlushMs >= EVENTLOG_FLUSH_MS) && !driving;
    if (len > 0 && (due || len > sizeof(_elBuf) * 3 / 4)) eventLogFlush();
}

inline void eventLogDump() {
    eventLogFlush();
    const char* files[] = { EVENTLOG_OLD, EVENTLOG_FILE };
    for (const char* name : files) {
        File f = LittleFS.open(name, FILE_READ);
        if (!f) continue;
        Serial.printf("----- %s (%u bytes) -----\n", name, (unsigned)f.size());
        uint8_t chunk[256];
        while (f.available()) {
            size_t n = f.read(chunk, sizeof(chunk));
            Serial.write(chunk, n);
        }
        f.close();
    }
    Serial.println("----- end -----");
}

inline void eventLogClear() {
    portENTER_CRITICAL(&_elMux);
    _elLen = 0;
    _elDropped = 0;
    portEXIT_CRITICAL(&_elMux);
    if (!_elReady) return;
    LittleFS.remove(EVENTLOG_FILE);
    LittleFS.remove(EVENTLOG_OLD);
}

inline void eventLogStatus(size_t* curBytes, size_t* oldBytes, size_t* freeBytes, uint16_t* boot) {
    *curBytes = *oldBytes = *freeBytes = 0;
    *boot = _elBoot;
    if (!_elReady) return;
    File f = LittleFS.open(EVENTLOG_FILE, FILE_READ);
    if (f) { *curBytes = f.size(); f.close(); }
    f = LittleFS.open(EVENTLOG_OLD, FILE_READ);
    if (f) { *oldBytes = f.size(); f.close(); }
    *freeBytes = LittleFS.totalBytes() - LittleFS.usedBytes();
}

#endif // EVENTLOG_H
