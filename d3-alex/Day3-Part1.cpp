#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>

int main()
{
    std::ifstream file("input3");
    if (!file.is_open())
    {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    std::string line;
    int grandTotal = 0;
    std::regex regexPattern("mul\\((\\d+),(\\d+)\\)");

    while (std::getline(file, line)) {
        int total = 0;
        std::smatch match;

        auto searchStart = line.cbegin();
        while (std::regex_search(searchStart, line.cend(), match, regexPattern)) {
            int x = std::stoi(match[1].str());
            int y = std::stoi(match[2].str());
            std::cout << "X: " << x << " Y: " << y << std::endl;

            // Do the multiplication
            int result = x * y;
            total += result;

            // Move past the current match
            searchStart = match.suffix().first;
        }
        grandTotal += total;
    }

    std::cout << "Grand Total: " << grandTotal << std::endl;

    file.close();

    return 0;
}