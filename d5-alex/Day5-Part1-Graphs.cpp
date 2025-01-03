#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class PageValidator {
private:
    // DP: Cache valid sequences to avoid recomputing
    unordered_map<string, bool> memo;
    
    // Graph: Store rules as adjacency list
    unordered_map<int, vector<int>> graph;
    
    // DP: Cache node positions in topological order
    unordered_map<int, int> positions;

    string createKey(const vector<int>& sequence) {
        stringstream ss;
        for (int num : sequence) ss << num << ",";
        return ss.str();
    }

    bool isValidSequenceMemoized(const vector<int>& sequence) {
        // DP Step 1: Check if result is cached
        string key = createKey(sequence);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // DP Step 2: Validate using cached positions
        for (size_t i = 0; i < sequence.size() - 1; i++) {
            if (positions[sequence[i]] > positions[sequence[i + 1]]) {
                memo[key] = false;
                return false;
            }
        }

        memo[key] = true;
        return true;
    }

public:
    void addRule(int from, int to) {
        graph[from].push_back(to);
    }

    bool topologicalSort() {
        // DP Step 3: Build position cache for O(1) lookups
        vector<int> sortedOrder;
        unordered_map<int, int> inDegree;
        
        // Initialize in-degree
        for (const auto& edge : graph) {
            if (inDegree.find(edge.first) == inDegree.end()) {
                inDegree[edge.first] = 0;
            }
            for (int to : edge.second) {
                inDegree[to]++;
            }
        }

        // Find nodes with zero in-degree
        vector<int> zeroInDegree;
        for (const auto& node : inDegree) {
            if (node.second == 0) {
                zeroInDegree.push_back(node.first);
            }
        }

        // Process nodes
        while (!zeroInDegree.empty()) {
            int node = zeroInDegree.back();
            zeroInDegree.pop_back();
            sortedOrder.push_back(node);

            if (graph.find(node) != graph.end()) {
                for (int neighbor : graph[node]) {
                    inDegree[neighbor]--;
                    if (inDegree[neighbor] == 0) {
                        zeroInDegree.push_back(neighbor);
                    }
                }
            }
        }

        // Cache positions for O(1) lookup
        for (size_t i = 0; i < sortedOrder.size(); i++) {
            positions[sortedOrder[i]] = i;
        }

        return sortedOrder.size() == inDegree.size();
    }

    int validateAndGetMiddle(const vector<int>& sequence) {
        if (isValidSequenceMemoized(sequence)) {
            return sequence[sequence.size() / 2];
        }
        return 0;
    }
};

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    ifstream inputFile("input5");
    string line;

    PageValidator validator;
    vector<vector<int>> pageLists; // Lista de listas de páginas

    bool parsingRules = true; // Bandera para saber si estamos leyendo reglas o listas de páginas

    while (getline(inputFile, line)) {
        if (line.empty()) {
            parsingRules = false; // Cambiar a leer listas de páginas
            continue;
        }

        if (parsingRules) {
            auto parts = split(line, '|');
            if (parts.size() == 2) {
                int first = stoi(parts[0]);
                int second = stoi(parts[1]);
                validator.addRule(first, second); // Agregar arista al grafo
            }
        } else {
            auto parts = split(line, ',');
            vector<int> pageList;
            for (const auto& part : parts) {
                pageList.push_back(stoi(part)); // Agregar página a la lista
            }
            pageLists.push_back(pageList); // Agregar lista de páginas a la colección
        }
    }

    inputFile.close();

    // Realizar el ordenamiento topológico
    if (!validator.topologicalSort()) {
        cerr << "Se detectó un ciclo en el grafo. No es posible realizar el ordenamiento topológico." << endl;
        return 1;
    }

    // Verificar cada lista de páginas
    int total = 0;
    for (const auto& pageList : pageLists) {
        int isValid = validator.validateAndGetMiddle(pageList);
        total += isValid;
        cout << isValid << endl;
    }

    cout << "Total: " << total << endl;
    return 0;
}