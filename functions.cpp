#include <vector>
#include <cstdlib>
#include <ctime>
#include "functions.h"

using namespace std;

struct Point
{
    int x, y;
};

// Function to generate maze
void generateMaze(vector<vector<char>> &maze)
{
    int n = maze.size();
    // Start with all 'B's
    for (int i = 0; i < n; ++i)
    {
        fill(maze[i].begin(), maze[i].end(), 'B');
    }

    // Randomly place 'H' ensuring at least one valid path
    int x = 0, y = 0;
    vector<Point> path;
    maze[x][y] = 'H'; // Ensure starting point is 'H'
    path.push_back({x, y});
    while (x < n - 1 || y < n - 1)
    {
        if (rand() % 2 == 0)
        {
            if (y + 1 < n)
                y++;
            else
                x++;
        }
        else
        {
            if (x + 1 < n)
                x++;
            else
                y++;
        }
        maze[x][y] = 'H';
        path.push_back({x, y});
    }

    // Add random walls and paths
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (maze[i][j] != 'H')
            {                                          // Only modify unmarked cells
                maze[i][j] = (rand() % 4) ? 'B' : 'H'; // Higher chance for walls
            }
        }
    }

    // Ensure the main path is clear
    for (const auto &p : path)
    {
        maze[p.x][p.y] = 'H';
    }
}