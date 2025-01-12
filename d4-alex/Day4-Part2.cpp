#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Check if the diagonals coincide with MAS or SAM (in any order)
bool checkDiag(const vector<string>& m, int i, int j) {
    string diag1 = string() + m[i-1][j-1] + m[i][j] + m[i+1][j+1];
    string diag2 = string() + m[i-1][j+1] + m[i][j] + m[i+1][j-1];
    return (diag1 == "MAS" || diag1 == "SAM") && (diag2 == "MAS" || diag2 == "SAM");
}

// Loop through all elements in the matrix, find "A" (center of X), and check diagonals
int findA(const vector<string>& matrix) {
    int count = 0;
    for (int i = 1; i < matrix.size() - 1; i++) {
        for (int j = 1; j < matrix[0].size() - 1; j++) {
            if (matrix[i][j] == 'A' && checkDiag(matrix, i, j)) {
                count++;
            }
        }
    }
    return count;
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

    int count = findA(grid);
    cout << count << endl;
    return 0;
}