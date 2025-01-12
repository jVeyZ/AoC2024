#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
using namespace std;

// Structure to represent state (position + direction)
struct State {
    int x, y, dir;
    bool operator<(const State& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return dir < other.dir;
    }
};

bool checksLoop(vector<vector<char>> grid, int startX, int startY) {
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    set<State> visited;
    int x = startX, y = startY;
    int currentDir = 0; // Start moving up

    while (true) {
        // Add current state to visited
        State current{x, y, currentDir};
        if (visited.find(current) != visited.end()) {
            return true; // Found a loop
        }
        visited.insert(current);

        // Try to move in the current direction
        int nextX = x + directions[currentDir].first;
        int nextY = y + directions[currentDir].second;

        // Check if next move would be out of bounds
        if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) {
            return false; // Escapes the grid
        }

        // Check if the next position is a wall
        if (grid[nextX][nextY] == '#') {
            currentDir = (currentDir + 1) % 4;
            continue;
        }

        // Move to the next position
        x = nextX;
        y = nextY;
    }
}

int countLoopingPositions(vector<vector<char>> originalGrid) {
    int loopCount = 0;
    int startX = -1, startY = -1;

    // Find starting position
    for (int i = 0; i < originalGrid.size(); i++) {
        for (int j = 0; j < originalGrid[i].size(); j++) {
            if (originalGrid[i][j] == '^') {
                startX = i;
                startY = j;
                originalGrid[i][j] = '.';
                break;
            }
        }
        if (startX != -1) break;
    }

    // Try placing # at each empty position
    for (int i = 0; i < originalGrid.size(); i++) {
        for (int j = 0; j < originalGrid[i].size(); j++) {
            if (originalGrid[i][j] == '.') {
                vector<vector<char>> testGrid = originalGrid;
                testGrid[i][j] = '#';
                if (checksLoop(testGrid, startX, startY)) {
                    loopCount++;
                    cout << "Loop found with # at position: " << i << ", " << j << endl;
                }
            }
        }
    }

    return loopCount;
}

int main() {
    ifstream file("input6");
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    vector<vector<char>> grid;
    string line;
    while (getline(file, line)) {
        vector<char> row(line.begin(), line.end());
        grid.push_back(row);
    }
    file.close();

    int loopingPositions = countLoopingPositions(grid);
    cout << "Number of positions that create loops: " << loopingPositions << endl;

    return 0;
}