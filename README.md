cub3D
📌 Description

cub3D is a graphical project inspired by Wolfenstein 3D.
The goal is to create a real-time 3D view inside a maze using raycasting, based on a configuration file (.cub).

This project introduces:

Raycasting math

Basic game engine concepts

Event handling (keyboard, window)

MiniLibX graphics library

Parsing and validation

🎯 Objectives

Render a 3D environment from a 2D map

Implement raycasting

Handle textures, colors, and player movement

Respect strict memory management

Follow 42 Norm

🛠️ Technologies
    Language: C
    Graphics: MiniLibX (Linux)
    Libraries: libft
    OS: Linux

📁 Project Structure
cub3D/
├── inc/                # Header files
├── src/                # Source files
├── libft/              # Libft library
├── minilibx-linux/     # MiniLibX
├── xpm/                # Wall textures (.xpm)
├── Makefile
└── README.md

🗺️ Map Format (.cub)

Example:

NO textures/wall_north.xpm
SO textures/wall_south.xpm
WE textures/wall_west.xpm
EA textures/wall_east.xpm

F 220,100,0
C 225,30,0

111111
100001
1000N1
100001
111111

Rules:

Map must be closed by walls (1)

One player position only: N, S, E, W

Colors are RGB values

Textures must be valid .xpm files

🎮 Controls
Key	Action
W	Move forward
S	Move backward
A	Move left
D	Move right
← →	Rotate camera
ESC	Exit game
❌ (Window)	Exit game
▶️ Compilation & Run
make
./cub3D maps/map.cub


To clean:

make clean
make fclean
make re

🚨 Error Handling

The program exits with an error message if:

The map is invalid

Textures are missing or incorrect

Colors are malformed

Memory allocation fails

Arguments are incorrect

🧠 Raycasting Overview

Cast one ray per screen column

Calculate wall distance

Choose texture based on hit direction

Draw vertical stripes

Apply floor and ceiling colors

📏 Norm & Memory

Fully compliant with 42 Norm

No memory leaks (checked with valgrind)

Proper resource cleanup on exit

🏁 Result

This project provides a solid foundation in:

Graphics programming

Game loop logic

Mathematical problem solving

Low-level memory management

👤 Author

Vache Zohrabyan
42 Student
