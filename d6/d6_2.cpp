#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

#define EMPTY 0x2E // '.'
#define WALL 0x23  // '#'
#define GUARD 0x5E // '^'

std::vector<std::vector<char>> map;
std::vector<std::pair<int, int>> tiles;
std::pair<int, int> spawn;
int obstructions=0;
int counter = 0;



struct player_info
{
  int orientation;
  std::pair<int, int> coords;
};
  player_info guard;


bool out_of_bounds(int y, int x)
{
  return y < 0 || y >= map.size() || x < 0 || x >= map[0].size();
}


void turn()
{
  guard.orientation = (guard.orientation + 1) % 4;
}

bool paradox() {
    std::vector<std::tuple<int, int, int>> turn_states; // x, y, orientation
    int max_steps = map.size() * map[0].size();
    int steps = 0;
    
    while (steps < max_steps) {
        int y = guard.coords.first;
        int x = guard.coords.second;
        int new_x = x;
        int new_y = y;

        switch (guard.orientation) {
            case 0: new_y = y - 1; break;
            case 1: new_x = x + 1; break;
            case 2: new_y = y + 1; break;
            case 3: new_x = x - 1; break;
        }

        if (out_of_bounds(new_y, new_x)) {
            return false;
        }

        if (map[new_y][new_x] != WALL) {
            guard.coords = {new_y, new_x};
        } else {
            turn();
        }
        steps++;
    }
    return true;
}

int main(int argc, char *argv[]) {
    std::string line;
    std::ifstream file;
    char save;
    int infinite_loops = 0;

    // Input reading
    file.open("input");
    while (getline(file, line)) {
        std::vector<char> row(line.begin(), line.end());
        map.push_back(row);
    }
    file.close();

    // Locate guard
    for (size_t i = 0; i < map.size(); ++i) {
        for (size_t j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == GUARD) {
                spawn = {i, j};
                guard.coords = spawn;
                guard.orientation = 0;
                std::cout << "Guard found at position (" << i << ", " << j << ")" << std::endl;
                goto break_l;
            }
        }
    }
    std::cout << "Guard not found at any given position" << std::endl;
    return 0;

break_l:

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            guard.coords = spawn;
            guard.orientation=0;
            if ( map[i][j] == WALL) {
                continue;
            }
            map[i][j] = WALL;
            if (paradox()) {
                infinite_loops++;
            }
            map[i][j] = EMPTY;
        }
    }
    std::cout << "Number of infinite loops possible: " << infinite_loops << std::endl;

    return 0;
}