#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

// PageValidator: Class to validate sequences of pages against ordering rules
class PageValidator {
private:
    // Store rules as pairs of (before, after) numbers
    // Example: (5,3) means 5 must come before 3 in any valid sequence
    vector<pair<int, int>> rules;

    // Cache to store previously validated sequences (Dynamic Programming)
    // Key: string representation of sequence, Value: whether sequence is valid
    unordered_map<string, bool> memo;

    // Helper function to create a unique string key for a sequence
    // Used for memoization in the DP approach
    string createKey(const vector<int>& sequence) {
        stringstream ss;
        for (int num : sequence) ss << num << ",";
        return ss.str();
    }

    // Core validation function that checks if a sequence follows all rules
    bool validateAgainstRules(const vector<int>& sequence) {
        // Check each rule against the sequence
        for (const auto& rule : rules) {
            bool foundFirst = false;    // Found the first number in rule
            bool foundSecond = false;   // Found the second number in rule
            int firstPos = -1;          // Position of first number
            int secondPos = -1;         // Position of second number
            
            // Scan sequence to find positions of both numbers in current rule
            for (size_t i = 0; i < sequence.size(); i++) {
                if (sequence[i] == rule.first) {
                    foundFirst = true;
                    firstPos = i;
                }
                if (sequence[i] == rule.second) {
                    foundSecond = true;
                    secondPos = i;
                }
                // If both numbers found and they're in wrong order, sequence is invalid
                if (foundFirst && foundSecond && firstPos > secondPos) {
                    return false;
                }
            }
        }
        // If we get here, sequence follows all rules
        return true;
    }

public:
    // Add a new ordering rule to the validator
    void addRule(int first, int second) {
        rules.push_back({first, second});
    }

    // Validate sequence and return its middle number if valid (0 if invalid)
    // Uses Dynamic Programming through memoization to avoid recomputing
    int validateAndGetMiddle(const vector<int>& sequence) {
        // Check if we've already validated this sequence (DP lookup)
        string key = createKey(sequence);
        if (memo.find(key) != memo.end()) {
            return memo[key] ? sequence[sequence.size() / 2] : 0;
        }
        
        // If not in cache, validate and store result (DP memoization)
        bool isValid = validateAgainstRules(sequence);
        memo[key] = isValid;
        return isValid ? sequence[sequence.size() / 2] : 0;
    }
};

// Helper function to split input string by delimiter
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
    // Open input file
    ifstream inputFile("input5");
    string line;

    PageValidator validator;
    vector<vector<int>> pageLists;  // Store all sequences to validate

    // Flag to track which part of input we're reading
    bool parsingRules = true;  // true = reading rules, false = reading sequences

    // Process input file line by line
    while (getline(inputFile, line)) {
        // Empty line separates rules from sequences
        if (line.empty()) {
            parsingRules = false;
            continue;
        }

        if (parsingRules) {
            // Parse rule: "first|second"
            auto parts = split(line, '|');
            if (parts.size() == 2) {
                int first = stoi(parts[0]);
                int second = stoi(parts[1]);
                validator.addRule(first, second);
            }
        } else {
            // Parse sequence: "num1,num2,num3,..."
            auto parts = split(line, ',');
            vector<int> pageList;
            for (const auto& part : parts) {
                pageList.push_back(stoi(part));
            }
            pageLists.push_back(pageList);
        }
    }

    inputFile.close();

    // Process all sequences and sum middle numbers of valid ones
    int total = 0;
    for (size_t i = 0; i < pageLists.size(); ++i) {
        int isValid = validator.validateAndGetMiddle(pageLists[i]);
        total += isValid;
        cout << isValid << endl;
    }

    cout << "Total: " << total << endl;
    return 0;
}