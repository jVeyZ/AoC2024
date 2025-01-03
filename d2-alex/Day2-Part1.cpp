#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

// Function declaration
int checkSafety(std::vector<int> row, int increment, int pass);

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
        if (!(iss >> col1))
        {
            std::cerr << "Error reading line: " << line << std::endl;
            continue;
        }
        row.push_back(col1);
        
        while (iss >> col1)
        {
            row.push_back(col1);
        }

        // Print the row
        for (int i = 0; i < row.size(); i++)
        {
            std::cout << row[i] << " ";
        }
        
        entireTotal ++;
        total += checkSafety(row, 0, 0); // 0 means unknown increment
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

    if (pass == 0)
    {
        // If element 0 is greater than element 1 and the difference is less than or equal to 3
        if (row[pass] > row[pass + 1] && row[pass] != row[pass + 1] && row[pass]-row[pass+1] <= 3)
        {
            increment = -1; // Decremental
            std::cout << "Decremental";
            // We know we must be checking for strictly decremental
            return checkSafety(row, increment, pass + 1);
        }
        else if (row[pass] < row[pass + 1] && row[pass] != row[pass + 1] && row[pass+1]-row[pass] <= 3)
        {
            increment = 1; // Incremental
            std::cout << "Incremental";
            // We know we must be checking for strictly incremental
            return checkSafety(row, increment, pass + 1);
        }
        else
        {
            std::cout << "Immediate verification failure" << std::endl;
            return 0; // Unsafe area
        }
    }
    else
    {
        if (increment == 1)
        {
            // If the current element is greater than the next element or the difference is greater than 3
            if (row[pass] > row[pass + 1] || row[pass] == row[pass + 1] || row[pass+1]-row[pass] > 3)
            {
                std::cout << "(" << row[pass] << ") " << row[pass+1]-row[pass] << " UNSAFE " << std::endl;
                return 0; // Unsafe area
            }
            else
            {
                std::cout << row[pass] << " -> ";
                return checkSafety(row, 1, pass + 1);
            }
        }
        else if (increment == -1)
        {
            if (row[pass] < row[pass + 1] || row[pass] == row[pass + 1] || row[pass]-row[pass+1] > 3)
            {
                std::cout << "(" << row[pass] << ") " << row[pass]-row[pass+1] << " UNSAFE " << std::endl;
                return 0; // Unsafe area
            }
            else
            {
                std::cout << row[pass] << " -> ";
                return checkSafety(row, -1, pass + 1);
            }
        }
    }
    return 0;
}
