#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

struct TreeNode {
    string value;
    vector<TreeNode*> children;

    TreeNode(const string& val) : value(val) {}
};

// Cache for memoization
unordered_map<string, vector<string>> transformCache;

// Helper function to check if a number has even digits
bool hasEvenDigits(const string &num) {
    return num.length() % 2 == 0;
}

// Helper function to split a number with even digits
pair<string, string> splitNumber(const string &num) {
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
string multiplyBy2024(const string &num) {
    vector<int> result(num.length() + 4, 0); // Max possible length

    // Multiply each digit
    for (int i = num.length() - 1; i >= 0; i--) {
        int n = num[i] - '0';
        int carry = 0;
        int pos = result.size() - 1 - (num.length() - 1 - i);

        int product = n * 2024 + carry;
        for (int j = 0; j < 4 || product > 0; j++) {
            if (product > 0) {
                result[pos - j] += product % 10;
                product /= 10;
            }
            if (result[pos - j] >= 10) {
                result[pos - j - 1] += result[pos - j] / 10;
                result[pos - j] %= 10;
            }
        }
    }

    // Convert to string and remove leading zeros
    string str;
    bool leadingZero = true;
    for (int digit : result) {
        if (digit != 0)
            leadingZero = false;
        if (!leadingZero)
            str += to_string(digit);
    }
    return str.empty() ? "0" : str;
}

// Function to transform a stone and add children to the tree node
void transformStone(TreeNode* node) {
    // Check cache first
    if (transformCache.find(node->value) != transformCache.end()) {
        for (const string& transformed : transformCache[node->value]) {
            node->children.push_back(new TreeNode(transformed));
        }
        return;
    }

    vector<string> result;

    // Rule 1: If stone is 0, replace with 1
    if (node->value == "0") {
        result.push_back("1");
    }
    // Rule 2: If stone has even number of digits, split it
    else if (hasEvenDigits(node->value)) {
        auto [left, right] = splitNumber(node->value);
        result.push_back(left);
        result.push_back(right);
    }
    // Rule 3: Multiply by 2024
    else {
        result.push_back(multiplyBy2024(node->value));
    }

    // Store in cache and add children
    transformCache[node->value] = result;
    for (const string& transformed : result) {
        node->children.push_back(new TreeNode(transformed));
    }
}

// Function to simulate blinks using a tree structure
long long simulateBlinks(vector<TreeNode*>& roots, int blinks) {
    queue<TreeNode*> q;
    for (TreeNode* root : roots) {
        q.push(root);
    }

    for (int i = 0; i < blinks; i++) {
        int size = q.size();
        for (int j = 0; j < size; j++) {
            TreeNode* node = q.front();
            q.pop();
            transformStone(node);
            for (TreeNode* child : node->children) {
                q.push(child);
            }
        }
        cout << "Number of stones after blink " << (i + 1) << ": " << q.size() << endl;
    }

    return q.size();
}

int main() {
    vector<string> stones = {"28591", "78", "0", "3159881", "4254", "524155", "598", "1"}; // Initial arrangement
    int blinks = 25;

    // Create the root nodes for the initial stones
    vector<TreeNode*> roots;
    for (const string &stone : stones) {
        roots.push_back(new TreeNode(stone));
    }

    // Simulate blinks for all root nodes together
    long long totalStones = simulateBlinks(roots, blinks);

    cout << "Number of stones after " << blinks << " blinks: " << totalStones << endl;

    // Clean up dynamically allocated memory
    for (TreeNode* root : roots) {
        delete root;
    }

    return 0;
}