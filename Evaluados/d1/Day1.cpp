#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::ifstream file("input");
    if (!file.is_open())
    {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    std::vector<std::string> column1;
    std::vector<std::string> column2;
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string col1, col2;
        if (!(iss >> col1 >> col2))
        {
            std::cerr << "Error reading line: " << line << std::endl;
            continue;
        }
        column1.push_back(col1);
        column2.push_back(col2);
    }

    file.close();

    // Sort the columns
    std::sort(column1.begin(), column1.end());
    std::sort(column2.begin(), column2.end());

    // Loop through the columns and compare
    int total = 0;
    for (int i = 0; i < column1.size(); i++)
    {
        int num1 = std::stoi(column1[i]);
        int num2 = std::stoi(column2[i]);
        if (num1 > num2)
        {
            total += num1 - num2;
        }
        else if (num1 < num2)
        {
            total += num2 - num1;
        }
    }

    std::cout << "Total: " << total << std::endl;

    return 0;
}