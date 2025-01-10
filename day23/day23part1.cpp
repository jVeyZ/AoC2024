#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

// Función para dividir una cadena por un delimitador
vector<string> dividirCadena(const string& str, char delimitador) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimitador)) {
        if (!token.empty()) {  // Ignorar tokens vacíos
            tokens.push_back(token);
        }
    }
    return tokens;
}

// Función para encontrar tripletas de computadoras conectadas
set<vector<string> > encontrarTripletasConectadas(const vector<string>& conexiones, char letraFiltro = '\0') {
    // Crear representación de lista de adyacencia del grafo
    map<string, set<string> > grafo;
    
    // Construir el grafo
    for (const string& conexion : conexiones) {
        vector<string> nodos = dividirCadena(conexion, '-');
        if (nodos.size() == 2) {  // Asegurar que la conexión es válida
            grafo[nodos[0]].insert(nodos[1]);
            grafo[nodos[1]].insert(nodos[0]);
        }
    }
    
    // Obtener todos los nodos
    vector<string> nodos;
    for (const auto& par : grafo) {
        nodos.push_back(par.first);
    }
    
    // Encontrar todas las tripletas
    set<vector<string> > tripletas;
    
    // Verificar todas las combinaciones posibles de tres nodos
    for (size_t i = 0; i < nodos.size(); i++) {
        for (size_t j = i + 1; j < nodos.size(); j++) {
            for (size_t k = j + 1; k < nodos.size(); k++) {
                const string& a = nodos[i];
                const string& b = nodos[j];
                const string& c = nodos[k];
                
                // Verificar si los tres nodos están conectados entre sí
                if (grafo[a].count(b) && grafo[a].count(c) && grafo[b].count(c)) {
                    vector<string> tripleta = {a, b, c};
                    sort(tripleta.begin(), tripleta.end());
                    
                    // Si se proporciona una letra de filtro, verificar si algún nodo comienza con ella
                    if (letraFiltro == '\0' || 
                        tripleta[0][0] == letraFiltro || 
                        tripleta[1][0] == letraFiltro || 
                        tripleta[2][0] == letraFiltro) {
                        tripletas.insert(tripleta);
                    }
                }
            }
        }
    }
    
    return tripletas;
}

int main() {
    // Leer entrada desde archivo
    ifstream archivoEntrada("input23");
    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir input23" << endl;
        return 1;
    }
    
    // Leer todas las conexiones del archivo
    vector<string> conexiones;
    string linea;
    while (getline(archivoEntrada, linea)) {  // Leer línea por línea
        // Eliminar espacios en blanco al inicio y final si los hay
        linea.erase(0, linea.find_first_not_of(" \t\r\n"));
        linea.erase(linea.find_last_not_of(" \t\r\n") + 1);
        
        if (!linea.empty()) {  // Ignorar líneas vacías
            conexiones.push_back(linea);
        }
    }
    archivoEntrada.close();
    
    cout << "Se leyeron " << conexiones.size() << " conexiones del archivo." << endl;
    
    // Encontrar todas las tripletas
    auto todasLasTripletas = encontrarTripletasConectadas(conexiones);
    cout << "Número total de tripletas: " << todasLasTripletas.size() << endl;
    
    // Encontrar tripletas con computadoras que comienzan con 't'
    auto tripletasConT = encontrarTripletasConectadas(conexiones, 't');
    cout << "\nNúmero de tripletas que contienen una computadora que comienza con 't': " 
         << tripletasConT.size() << endl;
    
    return 0;
}