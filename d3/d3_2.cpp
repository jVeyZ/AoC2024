#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

using namespace std;
int num=0;
void findAllPatternsInIntervals(const std::string& mainString, 
                                const std::regex& pattern, 
                                const std::vector<std::pair<size_t, size_t>>& intervals) {
    for (const auto& interval : intervals) {
        size_t start = interval.first;
        size_t end = interval.second;

        // Ensure the interval is valid
        if (start >= mainString.size() || end > mainString.size() || start > end) {
            std::cerr << "Invalid interval: [" << start << ", " << end << "]\n";
            continue;
        }

        // Extract the substring for the given interval
        std::string subString = mainString.substr(start, end - start);

        // Use std::sregex_iterator to find all matches in the substring
        auto begin = std::sregex_iterator(subString.begin(), subString.end(), pattern);
        auto endIter = std::sregex_iterator();

        if (begin == endIter) {
            std::cout << "\nNo matches found in interval [" << start << ", " << end << "]\n";
            cout << num<<endl;
        } else {
            std::cout << "\nMatches found in interval [" << start << ", " << end << "]: ";
            for (auto it = begin; it != endIter; ++it) {
                std::cout << it->str() << " ";
                std::smatch match = *it;
                
                // Access the captured groups for the two numbers
                if (match.size() == 3) {
                int x = stoi(match[1].str());
                int y = stoi(match[2].str());
                num += x * y;
                cout << num<<endl;
            }
            std::cout << "\n";
        }
    }
}}


int main(int argc, char const *argv[]) {
    string main;
    vector<pair<size_t, size_t>> intervals ={ //
        {0, 15}, {143, 208}, {339, 420}, {613, 713}, {1019, 1217}, {1326, 1376},
        {1492, 1540}, {1620, 1713}, {1788, 1945}, {2239, 2274}, {2284, 2371},
        {2583, 2887}, {2927, 2975}, {3065, 3093}, {3104, 3233}
    };
    string line;
    ifstream file;

    // Input reading
    file.open("input.txt");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    while (getline(file, line)) {
        main += line;
    }
    file.close();

    //Patern
    regex pattern(R"(mul\((\d+),(\d+)\))");
    findAllPatternsInIntervals(main, pattern, intervals);

    cout << "Total: " << num << endl;

    return 0;
}
