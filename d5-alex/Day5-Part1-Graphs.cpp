#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <queue>
using namespace std;

class GraphPageValidator {
private:
    // Adjacency list representation of the graph
    unordered_map<int, vector<int>> graph;
    // Keep track of incoming edges count for each node
    unordered_map<int, int> inDegree;
    
    // Set of all nodes in the graph
    unordered_set<int> allNodes;

    bool hasValidOrder(const vector<int>& sequence) {
        // Create a temporary copy of inDegree for this validation
        auto tempInDegree = inDegree;
        
        // Keep track of processed nodes to ensure sequence contains valid nodes
        unordered_set<int> seenNodes;
        
        // For each number in the sequence
        for (int current : sequence) {
            // If this node has predecessors that haven't been processed, sequence is invalid
            if (tempInDegree[current] > 0) {
                return false;
            }
            
            // Mark this node as seen
            seenNodes.insert(current);
            
            // Reduce inDegree for all nodes that depend on current node
            for (int neighbor : graph[current]) {
                tempInDegree[neighbor]--;
            }
        }
        
        // Check if all nodes in the sequence are valid nodes from our rules
        for (int node : sequence) {
            if (allNodes.find(node) == allNodes.end()) {
                return false;
            }
        }
        
        return true;
    }

public:
    void addRule(int first, int second) {
        // Add directed edge: first -> second
        graph[first].push_back(second);
        // Increase incoming edge count for second
        inDegree[second]++;
        // Add both nodes to our set of all nodes
        allNodes.insert(first);
        allNodes.insert(second);
    }

    int validateAndGetMiddle(const vector<int>& sequence) {
        if (sequence.empty()) return 0;
        
        // Check if sequence follows topological ordering rules
        if (!hasValidOrder(sequence)) {
            return 0;
        }
        
        // If valid, return middle element
        return sequence[sequence.size() / 2];
    }
};

// Helper function remains the same
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

    GraphPageValidator validator;
    vector<vector<int>> pageLists;
    bool parsingRules = true;

    while (getline(inputFile, line)) {
        if (line.empty()) {
            parsingRules = false;
            continue;
        }

        if (parsingRules) {
            auto parts = split(line, '|');
            if (parts.size() == 2) {
                int first = stoi(parts[0]);
                int second = stoi(parts[1]);
                validator.addRule(first, second);
            }
        } else {
            auto parts = split(line, ',');
            vector<int> pageList;
            for (const auto& part : parts) {
                pageList.push_back(stoi(part));
            }
            pageLists.push_back(pageList);
        }
    }

    inputFile.close();

    int total = 0;
    for (const auto& sequence : pageLists) {
        int isValid = validator.validateAndGetMiddle(sequence);
        total += isValid;
        cout << isValid << endl;
    }

    cout << "Total: " << total << endl;
    return 0;
}
