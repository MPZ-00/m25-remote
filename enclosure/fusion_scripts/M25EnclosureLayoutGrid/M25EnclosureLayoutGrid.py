"""
M25 Remote Enclosure - VARIANT A, 2x2 button cluster
====================================================
125 x 85 x 70 mm. Four 19 mm illuminated buttons in a 2x2 cluster on the right,
joystick on the left, two indicator LEDs above the joystick.

Superseded by variant B (m25_enclosure_row.py) after dev feedback that the
cluster felt crowded. Kept for comparison - it is 10 mm narrower, but has no
room for a display and only 2.0 mm clearance between the charge module and the
battery, versus 7.0 mm in variant B.

Builds four sketches in a fresh Fusion design:
    Base Plate Profile          outer profile, wall face, corner bosses, part footprints
    Base Underside Tie Channels interim zip-tie mount, sub-flush
    Top Plate Layout            control face
    Left Wall Ports             charge port

Run via Fusion > Utilities > Add-Ins > Scripts, or through the Fusion MCP.
Safe to re-run: wipes every sketch and construction plane in the root component.
Dimensions here are mm; Fusion's internal unit is cm, hence MM = 0.1.

Placeholders, echoed in the audit output:
  - JOY_HOLE / JOY_DEPTH until the joystick base is measured.
  - LED_HOLE assumes bare 5 mm LEDs; panel holders need 8.0.
  - MOD_* is a generic charge-module envelope; charge path not decided.
  - Tie channels are interim; revisit once the slide-in armrest mount is measured.
  - BTN_HOLE is nominal. For FDM, open to ~19.3 or ream - thread OD is 18.85.
"""

import adsk.core
import adsk.fusion
import math

MM = 0.1

NEW_DOCUMENT = True     # False = rebuild in the active design

# ---------------- shell ----------------
OUT_W, OUT_H, TOTAL_H = 125.0, 85.0, 70.0
WALL, BASE_T, TOP_T, CORNER_R = 2.5, 5.0, 3.0, 10.0
BOSS_OD, BOSS_ID = 7.0, 2.6

# ---------------- interim zip-tie mount ----------------
TIE_X, TIE_W, TIE_D = 40.0, 6.0, 2.5

# ---------------- internals ----------------
BAT_W, BAT_D, BAT_H = 80.0, 40.0, 15.0
ESP_W, ESP_D, ESP_H = 75.0, 30.0, 22.0   # board + headers + socket allowance
BAT_Y0, ESP_Y0 = -37.5, 7.5

# ---------------- control face ----------------
BTN_HOLE, BTN_FLATS, BTN_ENV, BTN_DEPTH = 19.0, 22.0, 25.0, 30.0
BTN_PITCH = 30.0
LED_HOLE = 5.0
JOY_ENV, JOY_HOLE, JOY_DEPTH = 40.0, 30.0, 30.0
JOY = (-35.0, 0.0)

BUTTONS = [('E-stop rot', 40.0, 15.0), ('Hill-hold gruen', 10.0, 15.0),
           ('Assist gelb', 10.0, -15.0), ('Power lila', 40.0, -15.0)]
LEDS = [('BLE weiss', -45.0, 31.0), ('Status rot', -25.0, 31.0)]

# ---------------- charge port, left short wall ----------------
PORT_Y, PORT_Z, PORT_W, PORT_H = 0.0, 16.0, 13.0, 8.0
MOD_W, MOD_H, MOD_DEPTH = 25.0, 15.0, 18.0

P = adsk.core.Point3D.create


def run(_context: str):
    app = adsk.core.Application.get()
    if NEW_DOCUMENT or app.activeProduct is None:
        app.documents.add(adsk.core.DocumentTypes.FusionDesignDocumentType)
    design = adsk.fusion.Design.cast(app.activeProduct)
    design.designType = adsk.fusion.DesignTypes.ParametricDesignType
    design.unitsManager.distanceDisplayUnits = adsk.fusion.DistanceUnits.MillimeterDistanceUnits
    root = design.rootComponent
    for s in list(root.sketches):
        s.deleteMe()
    for p in list(root.constructionPlanes):
        p.deleteMe()

    def new_sketch(plane, name):
        sk = root.sketches.add(plane)
        sk.name = name
        sk.isComputeDeferred = True
        return sk

    def offset_plane(base, dist, name):
        pin = root.constructionPlanes.createInput()
        pin.setByOffset(base, adsk.core.ValueInput.createByReal(dist * MM))
        pl = root.constructionPlanes.add(pin)
        pl.name = name
        return pl

    def rrect(sk, w, h, r, construction=False):
        a, b, rr = w / 2 * MM, h / 2 * MM, r * MM
        cx, cy = a - rr, b - rr
        L, A = sk.sketchCurves.sketchLines, sk.sketchCurves.sketchArcs
        e = [L.addByTwoPoints(P(-cx, -b, 0), P(cx, -b, 0)),
             A.addByCenterStartSweep(P(cx, -cy, 0), P(cx, -b, 0), math.pi / 2),
             L.addByTwoPoints(P(a, -cy, 0), P(a, cy, 0)),
             A.addByCenterStartSweep(P(cx, cy, 0), P(a, cy, 0), math.pi / 2),
             L.addByTwoPoints(P(cx, b, 0), P(-cx, b, 0)),
             A.addByCenterStartSweep(P(-cx, cy, 0), P(-cx, b, 0), math.pi / 2),
             L.addByTwoPoints(P(-a, cy, 0), P(-a, -cy, 0)),
             A.addByCenterStartSweep(P(-cx, -cy, 0), P(-a, -cy, 0), math.pi / 2)]
        if construction:
            for c in e:
                c.isConstruction = True

    def rect(sk, x1, y1, x2, y2, construction=False):
        r = sk.sketchCurves.sketchLines.addTwoPointRectangle(
            P(x1 * MM, y1 * MM, 0), P(x2 * MM, y2 * MM, 0))
        if construction:
            for ln in r:
                ln.isConstruction = True

    def circle(sk, x, y, dia, construction=False):
        c = sk.sketchCurves.sketchCircles.addByCenterRadius(
            P(x * MM, y * MM, 0), dia / 2 * MM)
        c.isConstruction = construction

    def hexagon(sk, cx, cy, flats):
        r = flats / 2.0 / math.cos(math.pi / 6) * MM
        pts = [P(cx * MM + r * math.cos(math.pi / 6 + i * math.pi / 3),
                 cy * MM + r * math.sin(math.pi / 6 + i * math.pi / 3), 0)
               for i in range(6)]
        for i in range(6):
            ln = sk.sketchCurves.sketchLines.addByTwoPoints(pts[i], pts[(i + 1) % 6])
            ln.isConstruction = True

    # ---- 1. base plate
    sk = new_sketch(root.xYConstructionPlane, 'Base Plate Profile')
    rrect(sk, OUT_W, OUT_H, CORNER_R)
    rrect(sk, OUT_W - 2 * WALL, OUT_H - 2 * WALL, CORNER_R - WALL)
    for sx in (-1, 1):
        for sy in (-1, 1):
            circle(sk, sx * (OUT_W / 2 - CORNER_R), sy * (OUT_H / 2 - CORNER_R), BOSS_OD)
            circle(sk, sx * (OUT_W / 2 - CORNER_R), sy * (OUT_H / 2 - CORNER_R), BOSS_ID)
    rect(sk, -BAT_W / 2, BAT_Y0, BAT_W / 2, BAT_Y0 + BAT_D, True)
    rect(sk, -ESP_W / 2, ESP_Y0, ESP_W / 2, ESP_Y0 + ESP_D, True)
    sk.isComputeDeferred = False

    # ---- 2. zip-tie channels (cut TIE_D deep, do not break through)
    sk = new_sketch(root.xYConstructionPlane, 'Base Underside Tie Channels')
    for sx in (-1, 1):
        rect(sk, sx * TIE_X - TIE_W / 2, -OUT_H / 2, sx * TIE_X + TIE_W / 2, OUT_H / 2)
    sk.isComputeDeferred = False

    # ---- 3. top plate control layout
    top_z = TOTAL_H - TOP_T
    pl = offset_plane(root.xYConstructionPlane, top_z, 'Top Plate Underside')
    sk = new_sketch(pl, 'Top Plate Layout')
    rrect(sk, OUT_W, OUT_H, CORNER_R)
    rrect(sk, OUT_W - 2 * WALL, OUT_H - 2 * WALL, CORNER_R - WALL, True)
    for _, x, y in BUTTONS:
        circle(sk, x, y, BTN_HOLE)
        hexagon(sk, x, y, BTN_FLATS)
        circle(sk, x, y, BTN_ENV, True)
    for _, x, y in LEDS:
        circle(sk, x, y, LED_HOLE)
    circle(sk, JOY[0], JOY[1], JOY_HOLE)
    rect(sk, JOY[0] - JOY_ENV / 2, JOY[1] - JOY_ENV / 2,
         JOY[0] + JOY_ENV / 2, JOY[1] + JOY_ENV / 2, True)
    sk.isComputeDeferred = False

    # ---- 4. charge port on the left short wall
    pl = offset_plane(root.yZConstructionPlane, -OUT_W / 2, 'Left Wall Outer')
    org = pl.geometry.origin
    sk = new_sketch(pl, 'Left Wall Ports')
    for w, h, con in ((PORT_W, PORT_H, False), (MOD_W, MOD_H, True)):
        p1 = sk.modelToSketchSpace(P(org.x, (PORT_Y - w / 2) * MM, (PORT_Z - h / 2) * MM))
        p2 = sk.modelToSketchSpace(P(org.x, (PORT_Y + w / 2) * MM, (PORT_Z + h / 2) * MM))
        p1.z = p2.z = 0
        r = sk.sketchCurves.sketchLines.addTwoPointRectangle(p1, p2)
        if con:
            for ln in r:
                ln.isConstruction = True
    sk.isComputeDeferred = False

    _audit(top_z)


def _audit(top_z):
    floor = BASE_T
    tall = floor + max(BAT_H, ESP_H)
    ctrl_bot = top_z - max(BTN_DEPTH, JOY_DEPTH)
    inner_x, inner_y = OUT_W / 2 - WALL, OUT_H / 2 - WALL

    print('=== VARIANT A, 2x2 cluster - %.0f x %.0f x %.0f mm ===' % (OUT_W, OUT_H, TOTAL_H))

    print('-- vertical stack --')
    print('base plate      %5.1f .. %5.1f' % (0.0, BASE_T))
    print('battery         %5.1f .. %5.1f' % (floor, floor + BAT_H))
    print('esp32 allowance %5.1f .. %5.1f' % (floor, floor + ESP_H))
    print('control bodies  %5.1f .. %5.1f' % (ctrl_bot, top_z))
    print('top plate       %5.1f .. %5.1f' % (top_z, TOTAL_H))
    print('HEADROOM board -> control bodies: %.1f mm' % (ctrl_bot - tall))

    print('-- control clearances --')
    worst = 999.0
    for i, (_, x1, y1) in enumerate(BUTTONS):
        for _, x2, y2 in BUTTONS[i + 1:]:
            worst = min(worst, math.hypot(x1 - x2, y1 - y2) - BTN_ENV)
    print('min bezel-to-bezel gap: %.1f mm (pitch %.1f)' % (worst, BTN_PITCH))
    for n, x, y in BUTTONS:
        print('%-16s to wall: %5.1f x / %5.1f y' %
              (n, inner_x - abs(x) - BTN_ENV / 2, inner_y - abs(y) - BTN_ENV / 2))
    print('joystick cap to walls:  %.1f x / %.1f y' %
          (inner_x - abs(JOY[0]) - JOY_ENV / 2, inner_y - abs(JOY[1]) - JOY_ENV / 2))
    print('joystick cap to nearest bezel: %.1f mm' %
          (min(x for _, x, _ in BUTTONS) - BTN_ENV / 2 - (JOY[0] + JOY_ENV / 2)))

    print('-- interim tie mount --')
    print('2 channels at x = +/-%.1f, %.1f wide x %.1f deep, %.1f mm material left'
          % (TIE_X, TIE_W, TIE_D, BASE_T - TIE_D))

    print('-- left wall charge port --')
    print('module z %.1f..%.1f, floor %.1f -> margin %.1f mm' %
          (PORT_Z - MOD_H / 2, PORT_Z + MOD_H / 2, floor, PORT_Z - MOD_H / 2 - floor))
    print('module reaches x %.1f, battery at %.1f -> clear %.1f mm' %
          (-inner_x + MOD_DEPTH, -BAT_W / 2, -BAT_W / 2 - (-inner_x + MOD_DEPTH)))
    print('side channel width: %.1f mm' % (inner_x - BAT_W / 2))
