🧊 Cube3D

A 42 Project – Raycasting Engine (Inspired by Wolfenstein 3D)

Cube3D is a small 3D raycasting engine built using MiniLibX.
Its purpose is to help you understand how early 3D engines work internally—especially the raycasting technique used in games like Wolfenstein 3D.
The program renders a 3D world from a 2D map, handles player movement, wall collisions, textures, and more.

🚀 Features
Mandatory

2D map parsing (.cub format)

Raycasting-based 3D rendering

Wall textures

Player movement (WASD)

Camera rotation (← →)

Collision detection

Basic minimap (if included in mandatory)

Bonus (if implemented)

Doors

Mouse rotation

Animations

Improved minimap

Additional textures / floor and ceiling casting

📦 Getting Started
🔹 Clone the repository
git clone https://github.com/<your-username>/<your-repo>.git
cd <your-repo>


Replace <your-username> and <your-repo> with your actual GitHub path.

🔨 Build the project (Mandatory)
make


This will generate the executable:

./cub3D maps/map.cub

🔧 Build Bonus
make bonus


Run it with:

./cub3D maps/map_bonus.cub

🎮 Controls
Key	Action
W	Move forward
S	Move backward
A	Move left
D	Move right
← →	Rotate camera
ESC	Exit program
📁 Project Structure
.
├── src/        # Source files
├── includes/   # Headers
├── textures/   # Texture files
├── maps/       # .cub maps
├── Makefile
└── README.md

🗺 Map Format (.cub)

Example:

NO textures/wall_north.xpm
SO textures/wall_south.xpm
WE textures/wall_west.xpm
EA textures/wall_east.xpm

F 220,100,0
C 225,30,0

111111111
100000001
101100001
100P00001
111111111

🧠 Learning Goals (42)

Math behind raycasting

Working with MiniLibX

Window handling & event hooks

Parsing and validating map data

Efficient rendering loops

🤝 Contributing

Pull requests are welcome if you’d like to improve documentation or add small features.

📜 License

This project is part of the 42 School curriculum.
Do not copy/paste without understanding the code.
