# 🧊 Cub3D

Cub3D is the second team project in the 42 core curriculum (partner->[Clemens](https://github.com/c8p2d01). It is a simplified 3D graphics engine based on raycasting, inspired by *Wolfenstein 3D*. This project aims to deepen our understanding of 3D rendering, vector math, and event-driven programming using the **MLX** graphics library.
<img width="1792" alt="Screenshot 2025-07-07 at 1 07 24 PM" src="https://github.com/user-attachments/assets/ff28eda2-a427-4295-bbd0-5c61ea6ef4ea" />

---

## 📌 Table of Contents

- [🧠 Project Overview](#-project-overview)
- [🧩 Features](#-features)
- [🚀 Getting Started](#-getting-started)
- [🕹 Controls](#-controls)
- [🗂 Map Format](#-map-format)
- [📸 Screenshots](#-screenshots)
- [📚 Resources](#-resources)

---

## 🧠 Project Overview

Cub3D is a raycasting-based first-person 3D engine. It renders a 2D map in a pseudo-3D view using minimal graphical primitives. The player can navigate through a maze with textures applied to walls and floors, mimicking depth and perspective.

This project teaches:
- Basics of raycasting (DDA algorithm)
- Vector math and trigonometry
- Real-time rendering and game loops
- Handling player input and collisions
- Texture mapping

---

## 🧩 Features

- ✅ Raycasting engine (DDA algorithm)
- ✅ Player movement & rotation
- ✅ Wall collision detection
- ✅ Texture rendering for walls
- ✅ Minimap
- ✅ Door mechanics
- ✅ Mouse support
- ✅ Sprite rendering (gif walls and doors)
- ✅ Customizable settings

# Minimap
Activate/deactivate minimap (press m). Some settings are visible in the minimap so make sure to have it activated when you check them out for the first time.
<img width="440" alt="Screenshot 2025-07-07 at 1 24 52 PM" src="https://github.com/user-attachments/assets/db173fbf-8963-460c-b75a-a828cf1da346" />

# Door mechanics
Open/close door (press spacebar). Doors are visible in the minimap as black tiles if opened and as white if closed. In the config they are set as 2 if closed and as 3 if opened.
Door on the right is closed.
<img width="1786" alt="Screenshot 2025-07-07 at 1 15 51 PM" src="https://github.com/user-attachments/assets/de3f040a-6cde-4482-8374-3beedcf5d0c5" />
Door on the right is open.
<img width="1787" alt="Screenshot 2025-07-07 at 1 16 11 PM" src="https://github.com/user-attachments/assets/6510971b-554c-4ccc-ae80-d2c052914bd6" />

# Mouse support
Activate/deactivate mouse (press v). Check out the incredible message that's printed in your terminal after pressing "v". While activated you can turn left/right with your mouse.
<img width="903" alt="Screenshot 2025-07-07 at 1 34 59 PM" src="https://github.com/user-attachments/assets/60411848-5885-498f-9849-94a28b680102" />
<img width="903" alt="Screenshot 2025-07-07 at 1 35 07 PM" src="https://github.com/user-attachments/assets/3fcdb18c-2475-46aa-814f-523feff56e14" />

# Sprite rendering
Use gif files in the config file to check out moving walls and doors. If the gif is very big the program will be a bit slow (rickgif is the slowest).

# Customizable settings
Press G to activate a settings selection in the terminal of the running program. To select one press left Shift and scroll with your mouse. The selected setting will be light green and can be customized using the mouse wheel.
<img width="1137" alt="Screenshot 2025-07-07 at 1 24 48 PM" src="https://github.com/user-attachments/assets/b2ccc2af-027a-47cb-832f-24b6e9945e4a" />
<img width="453" alt="Screenshot 2025-07-07 at 1 25 05 PM" src="https://github.com/user-attachments/assets/898981a5-6f0b-49eb-85e3-fd432faafe36" />
<img width="436" alt="Screenshot 2025-07-07 at 1 25 11 PM" src="https://github.com/user-attachments/assets/22479bde-a9af-4a3e-b0d0-4e132566e32b" />
<img width="1141" alt="Screenshot 2025-07-07 at 1 25 43 PM copy" src="https://github.com/user-attachments/assets/cdb51c48-2554-41b7-8782-c54ad2f50c56" />
<img width="449" alt="Screenshot 2025-07-07 at 1 25 41 PM" src="https://github.com/user-attachments/assets/0ee06054-ad17-4a96-9ac1-1d02f5b043ea" />
<img width="445" alt="Screenshot 2025-07-07 at 1 25 43 PM" src="https://github.com/user-attachments/assets/0b20c061-b981-4295-85d7-9eee6415eae6" />

---

## 🚀 Getting Started

### 🛠 Compile

```bash
make
```

### 🏃🏽‍♀️ Run the game

```bash
./cub3D maps/select_a_map.cub
```

You can find the valid maps inside the maps directory. You can also attempt making your own map.

## 🕹 Controls
Key	Action
W / ↑	Move forward
S / ↓	Move backward
A	Strafe left
D	Strafe right
← / →	Turn left/right
ESC	Exit game
Mouse look if enabled with v during play.

## 🗂 Map Format
- The map **must be surrounded by walls** (`1`).
- Player start position must be one of the following:
  - `N`, `S`, `E`, or `W`.
- The following identifiers are **mandatory**:
  - `NO`, `SO`, `WE`, `EA` – Wall textures
  - Floor and Ceiling RGB colors
- `DO` for door is **optional**.
- Use `2` for a **closed door**, `3` for an **open door**.

---

# Legend:

| Symbol | Meaning        |
|--------|----------------|
| ` `    | Nothing/Space  |
| `1`    | Wall           |
| `0`    | Empty space    |
| `2`    | Closed door    |
| `3`    | Open door      |
| `N`/`S`/`E`/`W` | Player starting position |

```bash
NO images/DEBUG/North.png
SO images/DEBUG/South.png
WE images/DEBUG/Westh.png
EA images/DEBUG/Easth.png
DO images/DEBUG/Doorh.png
F 220,100,0
C 225,30,0

111111
100001
1000N1
100001
111111
```

-DO for door is optional. NO, SO, WE, EA are mandatory.
-Map must be surrounded by walls (1).
-Player start position: N, S, E, or W.
-Floor/Ceiling RGB colors and wall textures are mandatory.
-2 for a closed door, 3 for an open door.
