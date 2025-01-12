#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class GrafoRutasSenderismo {
private:
    vector<vector<int>> terreno;  // Matriz que representa el terreno
    int filas, columnas;

    // Cache para Programación Dinámica (DP)
    // Clave: tupla(fila, columna, altura)
    // Valor: conjunto de posiciones alcanzables de altura 9
    map<tuple<int, int, int>, set<pair<int, int>>> cachePD;

    // Verifica si una posición está dentro de los límites
    bool esPosicionValida(int fila, int col) const {
        return fila >= 0 && fila < filas && col >= 0 && col < columnas;
    }

    // Función recursiva con DP para encontrar posiciones alcanzables de altura 9
    set<pair<int, int>> obtenerNuevesAlcanzables(int fila, int col, int alturaActual, 
                                                set<pair<int, int>>& visitados) {
        // Estado actual para la cache
        tuple<int, int, int> estado(fila, col, alturaActual);

        // DP: Verificar si ya calculamos este estado
        if (cachePD.count(estado)) {
            return cachePD[estado];  // Retornar resultado cacheado
        }

        set<pair<int, int>> resultado;

        // Caso base: encontramos altura 9
        if (terreno[fila][col] == 9) {
            resultado.insert({fila, col});
            cachePD[estado] = resultado;  // Guardar en cache
            return resultado;
        }

        // Vectores de dirección: arriba, derecha, abajo, izquierda
        const vector<pair<int, int>> direcciones = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        // Explorar cada dirección posible (implementación de grafo)
        // Miramos arriba, derecha, abajo, izquierda
        for (const auto& dir : direcciones) {
            int nuevaFila = fila + dir.first;
            int nuevaCol = col + dir.second;
            pair<int, int> nuevaPos = {nuevaFila, nuevaCol};

            // Verificar si podemos movernos a esta posición
            // Si la posición no se sale de los límites y no la hemos visitado
            if (esPosicionValida(nuevaFila, nuevaCol) && !visitados.count(nuevaPos)) {
                int siguienteAltura = terreno[nuevaFila][nuevaCol];

                // Verificar si es un paso válido (incremento de 1 en altura)
                if (siguienteAltura == alturaActual + 1) {
                    visitados.insert(nuevaPos);
                    // DP: Llamada recursiva para explorar este nuevo camino
                    auto nueves = obtenerNuevesAlcanzables(nuevaFila, nuevaCol, 
                                                         siguienteAltura, visitados);
                    // Eliminar la posición actual de los visitados
                    visitados.erase(nuevaPos);

                    // Añadir todas las posiciones (9s) alcanzables desde aquí
                    resultado.insert(nueves.begin(), nueves.end());
                }
            }
        }

        // DP: Guardar resultado en cache antes de volver
        cachePD[estado] = resultado;
        return resultado;
    }

public:
    // Método constructor que recibe una matriz de enteros "inputGrid"
    GrafoRutasSenderismo(const vector<vector<int>> &inputGrid)
        : terreno(inputGrid), filas(inputGrid.size()), columnas(inputGrid[0].size()) {}

    int calcularPuntuacionTotal()
    {
        int puntuacionTotal = 0;
        cachePD.clear(); // Limpiar cache para un cálculo nuevo

        // Encontrar todos los puntos de inicio (altura 0)
        for (int r = 0; r < filas; r++)
        {
            for (int c = 0; c < columnas; c++)
            {
                if (terreno[r][c] == 0)
                { // Encontramos un punto de inicio
                    set<pair<int, int>> visitados;
                    visitados.insert({r, c});

                    // Obtener todos los nueves alcanzables desde este punto de inicio
                    auto nueves = obtenerNuevesAlcanzables(r, c, 0, visitados);
                    puntuacionTotal += nueves.size();
                }
            }
        }

        return puntuacionTotal;
    }

    // Función de utilidad para parsear la entrada
    static vector<vector<int>> parsearEntrada(const vector<string> &lineas)
    {
        vector<vector<int>> resultado;
        for (const string &linea : lineas)
        {
            vector<int> fila;
            for (char c : linea)
            {
                if (c != '\r' && c != '\n')
                { // Omitir caracteres de nueva línea
                    fila.push_back(c - '0');
                }
            }
            if (!fila.empty())
            { // Solo agregar filas no vacías
                resultado.push_back(fila);
            }
        }
        return resultado;
    }
};

int main() {
    // Leer archivo de entrada
    ifstream archivo("input10");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir input10" << endl;
        return 1;
    }

    // Almacenar líneas del archivo
    vector<string> lineasEntrada;
    string linea;
    while (getline(archivo, linea)) {
        lineasEntrada.push_back(linea);
    }
    archivo.close();

    // Procesar entrada y resolver
    auto grid = GrafoRutasSenderismo::parsearEntrada(lineasEntrada);
    GrafoRutasSenderismo solver(grid);
    int result = solver.calcularPuntuacionTotal();

    cout << "Puntuación total: " << result << endl;
    return 0;
}