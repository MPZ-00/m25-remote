"""
PlatformIO pre-build script: version.py

Injects the short git commit hash as a compiler build flag (FW_GIT_HASH),
consumed by version.h to build the full firmware version string reported
at boot and via the 'sysinfo' serial command.
"""

import subprocess
import pathlib

Import("env")  # type: ignore # noqa: F821

try:
    _script_dir = pathlib.Path(__file__).resolve().parent
except NameError:
    _script_dir = pathlib.Path.cwd()

try:
    git_hash = subprocess.check_output(
        ["git", "rev-parse", "--short", "HEAD"],
        cwd=_script_dir,
        stderr=subprocess.DEVNULL,
    ).decode().strip()
except Exception:
    git_hash = "unknown"
else:
    try:
        dirty = subprocess.call(
            ["git", "diff", "--quiet", "--ignore-submodules", "HEAD"],
            cwd=_script_dir,
            stderr=subprocess.DEVNULL,
        ) != 0
    except Exception:
        dirty = False
    if dirty:
        git_hash += "-dirty"

env.Append(BUILD_FLAGS=[f'-DFW_GIT_HASH=\\"{git_hash}\\"'])  # type: ignore # noqa: F821
print(f"[version] FW_GIT_HASH={git_hash}")
