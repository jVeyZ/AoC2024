#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>

using namespace std;

// Possible directions for searching: right, left, down, up, diagonals
const vector<pair<int, int> > directions = {
    {0, 1},   // right
    {0, -1},  // left
    {1, 0},   // down
    {-1, 0},  // up
    {1, 1},   // diagonal down-right
    {-1, -1}, // diagonal up-left
    {1, -1},  // diagonal down-left
    {-1, 1}   // diagonal up-right
};

int countWordInDirection(const vector<string>& grid, int x, int y, const string& word, int dx, int dy) {
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    int len = word.length();

    for (int i = 0; i < len; ++i) {
        int nx = x + i * dx;
        int ny = y + i * dy;

        // Check boundaries
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != word[i]) {
            return 0;
        }
    }
    return 1; // Found one occurrence
}

int countOccurrences(const vector<string>& grid, const string& word) {
    int totalCount = 0;
    int n = grid.size();
    int m = grid[0].size();

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (auto [dx, dy] : directions) {
                totalCount += countWordInDirection(grid, x, y, word, dx, dy);
            }
        }
    }
    return totalCount;
}

int main() {
     std::ifstream file("input4");
    if (!file.is_open())
    {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    vector<string> grid;
    string line;
    while (std::getline(file, line))
    {
        grid.push_back(line);
    }
    file.close();

    string word = "XMAS";
    int occurrences = countOccurrences(grid, word);
    cout << "Total occurrences of " << word << ": " << occurrences << endl;

    return 0;
}
