# cub3D

A 3D graphical project developed as part of the **42 School curriculum**.

The goal of **cub3D** is to create a simple 3D game engine inspired by the classic **Wolfenstein 3D**, using **raycasting** and the **MiniLibX** graphics library.

The project focuses on understanding how 2D maps can be transformed into a 3D perspective using mathematical calculations, while handling graphics, textures, player movement, collisions, and keyboard events.

---

## 📖 Project Overview

**cub3D** is a first-person 3D maze application.

The player moves inside a 2D map, while the program uses a **raycasting algorithm** to render the environment as a 3D scene.

The project includes:

- Raycasting
- 3D rendering from a 2D map
- Wall collision detection
- Player movement
- Camera rotation
- Texture mapping
- Keyboard event handling
- Map parsing and validation
- RGB floor and ceiling colors
- Error handling
- MiniLibX graphics

---

## 🎯 Objectives

The main objectives of this project are to learn and understand:

- How raycasting works
- Basic 3D graphics concepts
- Vector and geometric calculations
- Coordinate systems
- Angles and trigonometry
- Texture mapping
- Event-driven programming
- Graphics rendering
- Parsing and validating configuration files
- Memory management

---

## 🛠️ Technologies

| Technology  | Usage                              |
| ----------- | ---------------------------------- |
| C           | Main programming language          |
| MiniLibX    | Graphics and window management     |
| Makefile    | Compilation and project management |
| Mathematics | Raycasting and camera calculations |

---

## 🎮 Controls

| Key   | Action              |
| ----- | ------------------- |
| `W`   | Move forward        |
| `S`   | Move backward       |
| `A`   | Move left           |
| `D`   | Move right          |
| `←`   | Rotate camera left  |
| `→`   | Rotate camera right |
| `ESC` | Exit the game       |

---

## 🗺️ Map Format

The game map is provided through a `.cub` file.

Example:

```text
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 135,206,235

111111111111
100000000001
1000N0000001
100000000001
111111111111
```

### Texture identifiers

```text
NO  North texture
SO  South texture
WE  West texture
EA  East texture
```

### Colors

```text
F   Floor color
C   Ceiling color
```

RGB values must be between `0` and `255`.

### Map characters

```text
1   Wall
0   Empty space
N   Player facing North
S   Player facing South
E   Player facing East
W   Player facing West
```

The map must contain **exactly one player starting position** and must be properly enclosed by walls.

---

## 🧠 How Raycasting Works

The core of cub3D is the **raycasting algorithm**.

The player has a position and a viewing direction.

For every vertical column of pixels on the screen:

1. A ray is created from the player's position.
2. The ray is sent into the map.
3. The algorithm determines where the ray hits a wall.
4. The distance to the wall is calculated.
5. The wall height on the screen is calculated from that distance.
6. The correct wall texture is selected.
7. The corresponding texture column is rendered.

Conceptually:

```text
Player
   |
   |\
   | \
   |  \
   |   \
   |    \
   |     X  <- Wall hit
   |
```

Closer walls appear larger, while farther walls appear smaller, creating the illusion of a 3D environment.

---

## 📐 DDA Algorithm

To efficiently determine where a ray hits a wall, the project uses the **DDA (Digital Differential Analyzer)** algorithm.

Instead of checking every pixel along the ray, DDA moves from one map grid intersection to another.

For example:

```text
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
| P |   |   | 1 |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
```

The ray travels through the map grid until it reaches a wall cell.

This makes wall detection significantly more efficient.

---

## 🖼️ Rendering Pipeline

The general rendering process is:

```text
                 Player
                    │
                    ▼
              Create Rays
                    │
                    ▼
              DDA Raycasting
                    │
                    ▼
              Wall Detection
                    │
                    ▼
             Calculate Distance
                    │
                    ▼
             Calculate Wall Height
                    │
                    ▼
             Select Texture
                    │
                    ▼
             Draw Vertical Line
                    │
                    ▼
                 Screen
```

---

## 🔨 Compilation

Clone the repository:

```bash
git clone <repository-url>
cd cub3D
```

Compile the project:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove the executable and object files:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

---

## 🚀 Usage

Run the program with a valid `.cub` map:

```bash
./cub3D maps/map.cub
```

Example:

```bash
./cub3D maps/example.cub
```

---

## ⚠️ Error Handling

The program must detect invalid input and terminate cleanly.

Examples of invalid input include:

- Invalid file extension
- Missing texture
- Invalid texture path
- Invalid RGB values
- Invalid map characters
- Multiple player positions
- Missing player position
- Map not surrounded by walls
- Invalid or inaccessible map file
- Incorrect map configuration

Errors are reported clearly and the program exits without crashing.

---

## 🧩 Main Concepts

### Raycasting

Transforms the 2D representation of the map into a pseudo-3D first-person view.

### DDA

Efficiently finds the first wall encountered by each ray.

### Texture Mapping

Maps different textures onto the four wall directions:

```text
        North
          ↑
          │
West ← Player → East
          │
          ↓
        South
```

### Collision Detection

Prevents the player from moving through walls.

### Event Handling

Handles keyboard input and window events through MiniLibX.

---

## 🧪 Testing

Different types of maps should be tested:

### Valid maps

```text
- Small maps
- Large maps
- Different player orientations
- Different textures
- Different colors
- Irregular map shapes
```

### Invalid maps

```text
- Open maps
- Missing player
- Multiple players
- Invalid characters
- Invalid textures
- Invalid RGB values
- Missing configuration
- Invalid file extension
```

Testing edge cases is important to ensure that the parser and renderer behave correctly.

---

## 📚 What I Learned

Through cub3D, I learned how to:

- Implement a raycasting engine
- Work with 2D vectors and directions
- Use trigonometry for graphics calculations
- Implement the DDA algorithm
- Handle textures and images
- Work with MiniLibX
- Parse and validate complex input
- Implement player movement and collisions
- Manage graphical resources
- Debug mathematical and rendering problems
- Structure a larger C project

---

## 👤 Author

**Abd El Karim**

42 / 1337 Coding School

---