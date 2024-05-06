# Custom Maze Game - Project 3

## Overview
This project is a web-based maze game where users can generate a random maze, input their own maze configuration, or upload a maze file to play. The game is developed using HTML, CSS, and JavaScript for the frontend, and C++ with CGI for the backend maze generation.

## Features
- Generate a random maze with a specified size.
- Input maze data in a specified format to create a custom maze.
- Upload a maze file to play the game.
- Navigate through the maze using keyboard arrow keys.
- Visual feedback for walls, paths, and the cursor.

## How to Play
1. Enter the size of the maze you wish to generate or input/upload your maze data.
2. Use the arrow keys to move the red cursor through the maze.
3. Reach the end point to win the game.

## Maze Format
- The maze is represented by a grid of characters where 'B' is a wall and 'H' is a path.
- The starting point is marked with 's' and the ending point with 'e'.
- Example format: `s(y1,x1) e(y2,x2)\nMaze...`

## Backend Details
- The backend is implemented in C++ using the CGI method to interact with the web frontend.
- The `generateMaze` function creates a random maze with at least one valid path from start to finish.
- The maze size is validated to be 20x20 or smaller.

## File Structure
- `project3.html`: The main HTML file for the game interface.
- `main.cpp`: The C++ file that contains the CGI script for maze generation.
- `get_validate_inputs.h/cpp`: Contains functions to validate user inputs.
- `functions.h/cpp`: Contains the `generateMaze` function and other utility functions.

## How to Set Up
1. Place the HTML file on a web server with CGI enabled.
2. Compile the C++ files and place the executable in the CGI-bin directory.
3. Access the `project3.html` file through the server to start the game.

## Dependencies
- A web server with CGI support.
- A C++ compiler to build the backend executable.

## License
This project is open-source and free to use. Feel free to contribute or modify the code as per your requirements.
