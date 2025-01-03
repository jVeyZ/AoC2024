#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

// Function declaration
int checkSafety(std::vector<int> row, int increment, int pass);
bool isSafeWithDampener(std::vector<int> row);

int main()
{
    std::ifstream file("input2");
    if (!file.is_open())
    {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    std::string line;
    int total = 0;
    int entireTotal = 0;

    // Divide the lines separated by a space
    while (std::getline(file, line))
    {
        std::vector<int> row;
        std::istringstream iss(line);
        int col1;
        while (iss >> col1)
        {
            row.push_back(col1);
        }

        // Print the row
        for (int i = 0; i < row.size(); i++)
        {
            std::cout << row[i] << " ";
        }

        std::cout << std::endl;

        entireTotal++;
        if (isSafeWithDampener(row))
        {
            total++;
        }
    }

    std::cout << "Total: " << total << std::endl;
    std::cout << "Entire Total: " << entireTotal << std::endl;

    file.close();

    return 0;
}

// Function definition
int checkSafety(std::vector<int> row, int increment, int pass)
{
    if (pass == row.size() - 1)
    {
        std::cout << row[pass] << " SAFE " << std::endl;
        return 1; // Safe area
    }

    int diff = row[pass + 1] - row[pass];

    if (pass == 0)
    {
        if (diff > 0 && diff <= 3)
        {
            increment = 1; // Incremental
            std::cout << "Incremental";
            return checkSafety(row, increment, pass + 1);
        }
        else if (diff < 0 && std::abs(diff) <= 3)
        {
            increment = -1; // Decremental
            std::cout << "Decremental";
            return checkSafety(row, increment, pass + 1);
        }
        else
        {
            std::cout << "Immediate verification failure" << std::endl;
            return 0; // Unsafe
        }
    }
    else
    {
        if (increment == 1)
        {
            if (diff <= 0 || diff > 3)
            {
                std::cout << "(" << row[pass] << ") " << diff << " UNSAFE " << std::endl;
                return 0; // Unsafe
            }
            else
            {
                std::cout << row[pass] << " -> ";
                return checkSafety(row, increment, pass + 1);
            }
        }
        else if (increment == -1)
        {
            if (diff >= 0 || std::abs(diff) > 3)
            {
                std::cout << "(" << row[pass] << ") " << diff << " UNSAFE " << std::endl;
                return 0; // Unsafe
            }
            else
            {
                std::cout << row[pass] << " -> ";
                return checkSafety(row, increment, pass + 1);
            }
        }
    }

    return 0; // Fallback
}

// New function to check safety with Problem Dampener
bool isSafeWithDampener(std::vector<int> row)
{
    // Directly check if the row is safe
    if (checkSafety(row, 0, 0))
    {
        return true;
    }

    // Test removing each level
    for (size_t i = 0; i < row.size(); i++)
    {
        std::vector<int> modifiedRow = row;
        modifiedRow.erase(modifiedRow.begin() + i);

        if (checkSafety(modifiedRow, 0, 0))
        {
            return true;
        }
    }

    return false;
}
