# 🧊 Cub3D

Cub3D is a simplified 3D graphics engine based on raycasting, inspired by *Wolfenstein 3D*. This project aims to deepen our understanding of 3D rendering, vector math, and event-driven programming using the **MLX** graphics library.
<img width="1792" alt="Screenshot 2025-07-07 at 1 07 24 PM" src="https://github.com/user-attachments/assets/ff28eda2-a427-4295-bbd0-5c61ea6ef4ea" />

![Cub3D Screenshot](./[screenshot.png](https://github.com/user-attachments/assets/ff28eda2-a427-4295-bbd0-5c61ea6ef4ea))

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

# Door mechanics
Open/close door (press spacebar). Doors are visible in the minimap as black tiles if opened and as white if closed. In the config they are set as 2 if closed and as 3 if opened.

# Mouse support
Activate/deactivate mouse (press v). Check out the incredible message that's printed in your terminal after pressing "v". While activated you can turn left/right with your mouse.

# Sprite rendering
Use gif files in the config file to check out moving walls and doors. If the gif is very big the program will be a bit slow (rickgif is the slowest).

# Customizable settings
Press G to activate a settings selection in the terminal of the running program. To select one press left Shift and scroll with your mouse. The selected setting will be light green and can be customized using the mouse wheel.

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
The map file must follow a specific format:
DO for door is optional.
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

DO for door is optional. NO, SO, WE, EA are mandatory.
Map must be surrounded by walls (1).
Player start position: N, S, E, or W.
Floor/Ceiling RGB colors and wall textures are mandatory.
2 for a closed door, 3 for an open door.
