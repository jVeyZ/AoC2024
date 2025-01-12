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

struct player_info {
  int orientation;
  std::pair<int, int> coords;
};

player_info guard;

bool out_of_bounds(int y, int x) {
  return y < 0 || y >= map.size() || x < 0 || x >= map[0].size();
}

void turn() {
  guard.orientation = (guard.orientation + 1) % 4;
}

int main(int argc, char *argv[]) {
  std::string line;
  std::ifstream file;

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
        guard.coords = {i, j};
        guard.orientation = 0;
        std::cout << "Guard found at position (" << i << ", " << j << ")" << std::endl;
        goto break_l;
      }
    }
  }
  std::cout << "Guard not found at any given position" << std::endl;
  return 0;

break_l:


// Guard movement
  while (true) {
    int y = guard.coords.first;
    int x = guard.coords.second;
    int new_x = x;
    int new_y = y;

    switch (guard.orientation) {
      case 0: // up
        new_y = y - 1;
        break;
      case 1: // right
        new_x = x + 1;
        break;
      case 2: // down
        new_y = y + 1;
        break;
      case 3: // left
        new_x = x - 1;
        break;
    }

    if (out_of_bounds(new_y, new_x)) {
      break;
    }

    for (const auto& tile : tiles) {
      if (tile.first == y && tile.second == x) {
        goto skip;
      }
    }
    tiles.push_back({y, x});
    skip:

    if (map[new_y][new_x] != WALL) {
      guard.coords = {new_y, new_x};
    } else {
      turn();  
    }

  }

  std::cout << "Guard visited " << tiles.size() + 1 << " distinct tiles." << std::endl;

  return 0;
}
