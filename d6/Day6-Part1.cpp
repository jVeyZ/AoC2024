#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int getPositionsVisited(vector<vector<char>> &grid)
{
    // Find the starting position (^)
    int startX = -1, startY = -1;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '^')
            {
                // Swap the ^ with a .
                grid[i][j] = '.';
                startX = i;
                startY = j;
                break;
            }
        }
        if (startX != -1)
        {
            break;
        }
    }

    // Create a secondary grid to track visited positions
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
    int totalPositions = 0;

    // Current position and direction
    int x = startX, y = startY;
    // Directions: 0 - up, 1 - right, 2 - down, 3 - left
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int currentDir = 0; // Start moving up

    // Mark start position
    visited[x][y] = 1;
    totalPositions++;

    while (true)
    {
        // Try to move in the current direction
        int nextX = x + directions[currentDir].first;
        int nextY = y + directions[currentDir].second;

        // Check if next move would be out of bounds
        if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
        {
            break;
        }

        // Check if the next position is a wall
        if (grid[nextX][nextY] == '#')
        {
            // Turn right
            currentDir = (currentDir + 1) % 4;
            continue;
        }

        // Move to the next position
        x = nextX;
        y = nextY;

        // Check if the next position has already been visited
        if (visited[x][y] == 0)
        {
            visited[x][y] = 1;
            totalPositions++;
        }

        // Print out the current position
        cout << "Current position: " << x << ", " << y << endl;
    }

    return totalPositions;
}

int main()
{
    std::ifstream file("input6");
    if (!file.is_open())
    {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    // Make a 2D vector to store the grid, where each element is a character
    vector<vector<char>> grid;
    string line;
    while (std::getline(file, line))
    {
        vector<char> row(line.begin(), line.end());
        grid.push_back(row);
    }
    file.close();

    // Get the number of positions visited
    int totalVisited = getPositionsVisited(grid);
    cout << "Total positions visited: " << totalVisited << endl;

    return 0;
}