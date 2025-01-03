#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    // Open the file
    std::ifstream file("input3");
    if (!file.is_open()) {
        std::cerr << "Could not open file\n";
        return 1;
    }

    // Read the file content into a string
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    // Define the regex pattern
    std::regex pattern("(mul\\((\\d+),(\\d+)\\)|do\\(\\)|don't\\(\\))");
    std::smatch match;
    int res = 0;
    bool flag = true;

    std::string::const_iterator searchStart(content.cbegin());
    while (std::regex_search(searchStart, content.cend(), match, pattern)) {
        if (match[0] == "do()") {
            flag = true;
        } else if (match[0] == "don't()") {
            flag = false;
        } else if (flag && match[1].matched && match[2].matched) {
            // Extract and multiply the numbers
            try {
                std::cout << "Match: " << match[2] << '\n';
                int x = std::stoi(match[2].str());
                int y = std::stoi(match[3].str());
                res += x * y;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid number in mul(): " << e.what() << '\n';
            } catch (const std::out_of_range& e) {
                std::cerr << "Number out of range in mul(): " << e.what() << '\n';
            }
        }

        // Move the search start position past this match
        searchStart = match.suffix().first;
    }

    // Print the result
    std::cout << "Result: " << res << std::endl;

    return 0;
}