# Cub3D

Cub3D is a 3D raycasting project inspired by **Wolfenstein 3D**, implemented in **C** using **MinilibX** for graphics rendering. This project demonstrates raycasting, texture mapping, and simple game mechanics.

---

## Features

- Raycasting engine for 3D wall rendering
- Player movement and rotation
- Collision detection with walls
- Texture mapping on walls
- Map parsing from `.cub` files
- Adjustable screen resolution

---

## Installation

1. Clone the repository:
git clone [<repo-url>](https://github.com/VacheZohrabyan/cub3d)
cd cub3d

2. Compile the project using Makefile:
make
3. Run the game with a map:
./cub3D cub3d.cub

## Controls

| Key            | Action                     |
|----------------|---------------------------|
| W / S          | Move forward / backward    |
| A / D          | Strafe left / right        |
| Left/Right Arrow | Rotate player            |
| ESC            | Exit the game             |

---

## Map Format

The map is loaded from `.cub` files.

- **Walls** are represented by `1`  
- **Empty space** is `0`  
- **Player start position**: `N`, `S`, `E`, or `W` (facing direction)

**Example:**
111111
100001
10N001
100001
111111

---

## Dependencies

- **MinilibX**: Simple X11 graphics library ([minilibx-linux](https://github.com/42Paris/minilibx-linux))  
- **libft**: Custom C library ([libft](https://github.com/42School/libft))  
- Linux OS recommended

---

## Author

**Vache Zohrabyan** – Creator & Developer




