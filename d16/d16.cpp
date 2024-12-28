#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <queue>

std::vector<std::vector<char>> map;
std::vector<std::pair<int, int>> temp_coords;


struct PATHS {
    std::vector<std::pair<int, int>> coords;
    int counter;
};
std::vector<PATHS> paths;
std::vector<std::pair<int, int>> stack;
int start_x, start_y, total;


void check_path(std::vector<std::vector<char>>&map, int i, int j) {
    static int dy[4] = {-1, 1, 0, 0};
    static int dx[4] = {0, 0, -1, 1};
    int options = 0;
    if (i==1 && j == 138) {
        bool found = false;
        for (auto& path : paths) {
            if (total == path.counter) {
            found = true;
            break;
            }
        }
        if (!found) {
            PATHS newP = {temp_coords, total};
            paths.push_back(newP);
        }
        if(stack.empty()){return;}
    }

    for (int n = 0; n < 4; n++) {
        int ny = i + dy[n];
        int nx = j + dx[n];
        if (ny >= 0 && ny < map.size() && nx >= 0 && nx < map[0].size() && map[ny][nx] == '.') {
            options++;
            total++;
            temp_coords.push_back({ny, nx});
            stack.push_back({ny, nx});
            map[ny][nx] = '/';
        }
    }
    if(options==0){
        
        return;}

    if (!stack.empty()) {
        int y = stack.back().first;
        int x = stack.back().second;
        stack.pop_back();
        return check_path(map, y, x);
    }
}


int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file;
    int total = 0;

    // Input reading
    file.open("input");
    while (getline(file, line)) {
        std::vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        map.push_back(row);
    }
    file.close();

    check_path(map, 139, 1);


    for (const auto& coord : paths[0].coords) {
        map[coord.first][coord.second] = 'X';
    }
    
    for (const auto& row : map) {
        for (const auto& c : row) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    std::cout <<paths.size()<< std::endl;
    
    return 0;
}
