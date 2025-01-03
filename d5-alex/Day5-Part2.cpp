#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to split a string by a delimiter (ChatGPT function)
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to rearrange a page list to satisfy the rules
void fixOrder(const vector<pair<int, int>>& rules, vector<int>& pageList) {
    bool changed;
    //Iterate until it is correct (fix for only being able to move one page at a time)
    do {
        changed = false;
        for (const auto& rule : rules) {
            int a = rule.first, b = rule.second;
            auto itA = find(pageList.begin(), pageList.end(), a);
            auto itB = find(pageList.begin(), pageList.end(), b);
            if (itA != pageList.end() && itB != pageList.end() && itA > itB) {
                // Move `a` to appear before `b`
                pageList.erase(itA);
                itB = find(pageList.begin(), pageList.end(), b); // Recalculate position of `b`
                pageList.insert(itB, a);
                changed = true;
            }
        }
    } while (changed);
}

// Function to check if a page list adheres to the rules
bool checkOrder(const vector<pair<int, int>>& rules, const vector<int>& pageList) {
    for (const auto& rule : rules) {
        int a = rule.first, b = rule.second;
        auto posA = find(pageList.begin(), pageList.end(), a);
        auto posB = find(pageList.begin(), pageList.end(), b);
        if (posA != pageList.end() && posB != pageList.end() && posA > posB) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream inputFile("input5");
    string line;

    vector<pair<int, int>> rules;
    vector<vector<int>> pageLists;

    bool parsingRules = true;

    // Parser
    while (getline(inputFile, line)) {
        if (line.empty()) {
            parsingRules = false;
            continue;
        }

        if (parsingRules) {
            // Parse rules
            auto parts = split(line, '|');
            if (parts.size() == 2) {
                int first = stoi(parts[0]);
                int second = stoi(parts[1]);
                rules.emplace_back(first, second);
            }
        } else {
            // Parse page lists
            auto parts = split(line, ',');
            vector<int> pageList;
            for (const auto& part : parts) {
                pageList.push_back(stoi(part));
            }
            pageLists.push_back(pageList);
        }
    }

    inputFile.close();

    // Check each page list and fix if invalid
    int total = 0;
    for (size_t i = 0; i < pageLists.size(); ++i) {
        if (checkOrder(rules, pageLists[i])) {
            cout << "Page list " << i + 1 << ": Valid" << endl;
        } else {
            cout << "Page list " << i + 1 << ": Invalid. Fixing..." << endl;
            fixOrder(rules, pageLists[i]);
            cout << "Fixed page list " << i + 1 << ": ";
            for (size_t j = 0; j < pageLists[i].size(); ++j) {
                cout << pageLists[i][j];
                if (j < pageLists[i].size() - 1) cout << ",";
            }
            cout << endl;
            cout << "Page added to total with: " << pageLists[i][pageLists[i].size() / 2] << endl;
            total += pageLists[i][pageLists[i].size() / 2];
        }
    }

    cout << "Total: " << total << endl;

    return 0;
}
