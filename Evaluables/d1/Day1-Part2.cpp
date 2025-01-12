#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int calculateSimilarityScore(const vector<string>& leftCol, const vector<string>& rightCol) {
    // DP Step 1: Memoization - Build frequency table of right column
    // This is DP because we're storing computed results (frequencies)
    // to avoid recounting the same numbers multiple times
    unordered_map<string, int> rightFreq;
    for (const string& num : rightCol) {
        rightFreq[num]++;
    }

    // DP Step 2: Use memoized results to calculate final score
    // Instead of rechecking right column for each left number,
    // we use our stored frequencies (avoiding repeated work)
    int totalScore = 0;
    for (const string& leftNum : leftCol) {
        // Use memoized frequency directly
        totalScore += stoi(leftNum) * rightFreq[leftNum];
    }

    return totalScore;
}

int main() {
    ifstream file("input");
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    vector<string> column1;
    vector<string> column2;
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        string col1, col2;
        if (!(iss >> col1 >> col2)) {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        column1.push_back(col1);
        column2.push_back(col2);
    }

    file.close();

    int score = calculateSimilarityScore(column1, column2);
    cout << "Similarity score: " << score << endl;

    return 0;
}