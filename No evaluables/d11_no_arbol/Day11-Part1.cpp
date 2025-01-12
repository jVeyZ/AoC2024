#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

// Cache for memoization
unordered_map<string, vector<string>> transformCache;

// Helper function to check if a number has even digits
bool hasEvenDigits(const string &num)
{
    return num.length() % 2 == 0;
}

// Helper function to split a number with even digits
pair<string, string> splitNumber(const string &num)
{
    int mid = num.length() / 2;
    string left = num.substr(0, mid);
    string right = num.substr(mid);

    // Remove leading zeros
    while (left.length() > 1 && left[0] == '0')
        left = left.substr(1);
    while (right.length() > 1 && right[0] == '0')
        right = right.substr(1);

    return {left, right};
}

// Helper function to multiply a string number by 2024
string multiplyBy2024(const string &num)
{
    vector<int> result(num.length() + 4, 0); // Max possible length

    // Multiply each digit
    for (int i = num.length() - 1; i >= 0; i--)
    {
        int n = num[i] - '0';
        int carry = 0;
        int pos = result.size() - 1 - (num.length() - 1 - i);

        int product = n * 2024 + carry;
        for (int j = 0; j < 4 || product > 0; j++)
        {
            if (product > 0)
            {
                result[pos - j] += product % 10;
                product /= 10;
            }
            if (result[pos - j] >= 10)
            {
                result[pos - j - 1] += result[pos - j] / 10;
                result[pos - j] %= 10;
            }
        }
    }

    // Convert to string and remove leading zeros
    string str;
    bool leadingZero = true;
    for (int digit : result)
    {
        if (digit != 0)
            leadingZero = false;
        if (!leadingZero)
            str += to_string(digit);
    }
    return str.empty() ? "0" : str;
}

// Transform a single stone according to the rules
vector<string> transformStone(const string &stone)
{
    // Check cache first
    if (transformCache.find(stone) != transformCache.end())
    {
        return transformCache[stone];
    }

    vector<string> result;

    // Rule 1: If stone is 0, replace with 1
    if (stone == "0")
    {
        result.push_back("1");
    }
    // Rule 2: If stone has even number of digits, split it
    else if (hasEvenDigits(stone))
    {
        auto [left, right] = splitNumber(stone);
        result.push_back(left);
        result.push_back(right);
    }
    // Rule 3: Multiply by 2024
    else
    {
        result.push_back(multiplyBy2024(stone));
    }

    // Store in cache and return
    transformCache[stone] = result;
    return result;
}

// Transform all stones for one blink
vector<string> transformAllStones(const vector<string> &stones)
{
    vector<string> result;
    for (const string &stone : stones)
    {
        vector<string> transformed = transformStone(stone);
        result.insert(result.end(), transformed.begin(), transformed.end());
    }
    return result;
}

// Main function to simulate multiple blinks
long long simulateBlinks(vector<string> initialStones, int blinks)
{
    vector<string> stones = initialStones;

    for (int i = 0; i < blinks; i++)
    {
        stones = transformAllStones(stones);
        cout << "After blink " << (i + 1) << ": " << stones.size() << " stones" << endl;
    }

    return stones.size();
}

int main()
{
    // Your specific input
    vector<string> initialStones = {
        "1950139", "0", "3", "837", "6116", "18472", "228700", "45"};
    int blinks = 25;

    cout << "Initial stones: " << initialStones.size() << endl;
    long long result = simulateBlinks(initialStones, blinks);
    cout << "After " << blinks << " blinks, there will be " << result << " stones." << endl;

    return 0;
}