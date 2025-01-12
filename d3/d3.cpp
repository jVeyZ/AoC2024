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
        auto words_begin = sregex_iterator(str.begin(), str.end(), pattern);
        auto words_end = sregex_iterator();

        for (sregex_iterator i = words_begin; i != words_end; ++i) {
            smatch match = *i;
            cout << match.str() << " " << match.position()<<endl;
            if (match.size() == 3) {
                int x = stoi(match[1].str());
                int y = stoi(match[2].str());
                num += x * y;
                cout << "Found: " << match.str() << " with x = " << x << " and y = " << y << endl;
            } 
        }
    }
    cout << "Total: " << num << endl;

    return 0;
}