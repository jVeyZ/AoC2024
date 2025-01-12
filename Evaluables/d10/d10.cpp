#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <queue>

struct PATHS { // Estructura para almacenar los caminos encontrados (programación dinámica)
    std::pair<int, int> coords;
    int counter;
    std::vector<std::pair<int,int>> end;
};
std::vector<PATHS> paths;
std::vector<std::vector<int>> map;
std::vector<std::pair<int, int>> stack;
int start_x, start_y;


// Explora caminos desde una posición inicial
void check_path(const std::vector<std::vector<int>>& map, int i, int j) {
    static int dy[4] = {-1, 1, 0, 0};
    static int dx[4] = {0, 0, -1, 1};

    // Si se encuentra un destino y es camino único se actualizan los caminos en `paths`
    if (map[i][j] == 9) {
        bool found = false;
        for (auto& path : paths) {
            if (path.coords.first == start_y && path.coords.second == start_x) {
            bool unique_end = true;
            for (const auto& end : path.end) {
                if (end.first == i && end.second == j) {
                unique_end = false;
                break;
                }
            }
            if (unique_end) {
                path.end.push_back({i, j});
                path.counter++;
            }
            found = true;
            break;
            }
        }
        if (!found) {
            PATHS newP = {{start_y, start_x}, 1, {{i, j}}};
            paths.push_back(newP);
        }
        if(stack.empty()){return;}
    }
    
    // Se exploran posiciones adyacentes válidas
    for (int n = 0; n < 4; n++) {
        int ny = i + dy[n];
        int nx = j + dx[n];
        if (ny >= 0 && ny < map.size() && nx >= 0 && nx < map[0].size() && map[ny][nx] == map[i][j] + 1) {
            stack.push_back({ny, nx});
        }
    }

    // Continua la exploración con la última posición de la pila
    if (!stack.empty()) {
        int y = stack.back().first;
        int x = stack.back().second;
        stack.pop_back();
        return check_path(map, y, x);
    }
}

int main(int argc, char const *argv[]) {
    std::string line;
    std::ifstream file;
    int total = 0;

    // Input reading
    file.open("input");
    while (getline(file, line)) {
        std::vector<int> row;
        for (char c : line) {
            row.push_back(c - '0');
        }
        map.push_back(row);
    }
    file.close();

    // LLamada a la función dinámica que encuentra los caminos y los guarda en memoria
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            if (map[i][j] != 0) {
                continue;
            }
            start_y = i;
            start_x = j;
            check_path(map, i, j);
        }
    }

    // Suma total de los caminos
    for (const auto& elem : paths) {
        printf("Origin {%d,%d}:%d \n",elem.coords.second, elem.coords.first, elem.counter);
        total += elem.counter;
    }
    std::cout << "Total sum of paths: " << total << std::endl;
    return 0;
}
