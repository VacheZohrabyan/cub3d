cub3D
📌 Description

cub3D is a 3D graphical project inspired by the famous game Wolfenstein 3D, developed as part of the 42 school curriculum.
The goal of this project is to create a simple raycasting engine using MiniLibX, allowing the player to explore a maze from a first-person perspective.

This project helps to understand:

. Raycasting principles
. Basic 3D rendering
. Event handling
. Texture mapping
. Memory management in C

🛠 Technologies Used

. C
. MiniLibX
. Math library (-lm)
. Linux (X11)

🎮 Features

. First-person 3D view using raycasting
. Textured walls (North, South, East, West)
. Player movement:
    . Move forward / backward
    . Rotate left / right
. Collision detection with walls
. Map parsing from .cub configuration file
. Floor and ceiling color support
. Clean exit using ESC key or window close button

🗺 Map Format (.cub)

Example:

NO ./xpm/north.xpm
SO ./xpm/south.xpm
WE ./xpm/west.xpm
EA ./xpm/east.xpm

F 220,100,0
C 225,30,0

111111
100001
101101
1000N1
111111

Map Rules:

. 1 → Wall
. 0 → Empty space
. N, S, E, W → Player starting position and orientation
. Map must be closed/surrounded by walls

🎮 Controls
Key	            Action
W	            Move forward
S	            Move backward
A	            Rotate left
D	            Rotate right
ESC	            Exit program
Window ❌	   Exit program

⚙️ Installation & Usage
1. Clone the repository
git clone https://github.com/yourusername/cub3D.git
cd cub3D

2. Compile
make

3. Run
./cub3D maps/example.cub

🧪 Debugging

You can check for memory leaks using Valgrind:

valgrind --leak-check=full ./cub3D maps/example.cub

📁 Project Structure
cub3D/
|── get_next_line/
├── inc/
│   └── cub3d.h
├── libft/
├── minilibx-linux/
├── src/
│   └── destroy  
|   └── free
|   └── parsing 
|   └── run_game
|   └── main.c
├── maps/
├── Makefile
|── cub3d.cub
└── README.md

❗ Error Handling

. Invalid map format
. Missing or invalid textures
. Multiple or missing player positions
. Open maps (not surrounded by walls)
. Invalid RGB values

📚 Learning Outcomes

. Understanding raycasting and basic 3D engines
. Working with low-level graphics
. Parsing complex input files
. Event-driven programming
. Robust memory management in C

👤 Author

Vache Zohrabyan
42 Yerevan / National Polytechnic University of Armenia