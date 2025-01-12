#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

int main(int argc, char const *argv[])
{
    // Variable declaration
    vector<string> list;
    string line;
    ifstream file;
    int num = 0;
    bool mulEnabled = true; // At the beginning, mul instructions are enabled

    // Input reading
    file.open("input.txt");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    while (getline(file, line))
    {
        list.push_back(line);
    }
    file.close();

    // Regular expression to match the patterns
    regex pattern(R"(mul\((\d+),(\d+)\))");
    regex doPattern(R"(do\(\))");
    regex dontPattern(R"(don't\(\))");

    for (const string& str : list) {
        if (regex_search(str, doPattern)) {
            mulEnabled = true;
        } else if (regex_search(str, dontPattern)) {
            mulEnabled = false;
        }else if (mulEnabled && regex_search(str, pattern)) {
            smatch match;
            if (regex_match(str, match, pattern) && match.size() == 3) {
                int x = stoi(match[1].str());
                int y = stoi(match[2].str());
                num = num + x * y;
                cout << "Found: " << match[0].str() << " with x = " << x << " and y = " << y << endl;
            }
        }
    }
    cout << "Total: " << num << endl;

    return 0;
}