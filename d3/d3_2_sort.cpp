#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Input data
    vector<pair<string, int>> entries = {
        {"do()", 143}, {"do()", 382}, {"do()", 613}, {"do()", 1019}, {"do()", 1215},
        {"do()", 2284}, {"don't()", 313}, {"don't()", 776}, {"don't()", 936}, {"don't()", 1713},
        {"do()", 207}, {"do()", 1620}, {"do()", 2239}, {"do()", 2673}, {"do()", 2778},
        {"do()", 3065}, {"do()", 3104}, {"don't()", 15}, {"don't()", 274}, {"don't()", 420},
        {"don't()", 552}, {"don't()", 1399}, {"don't()", 1540}, {"don't()", 1734}, {"don't()", 2058},
        {"don't()", 2168}, {"don't()", 2274}, {"don't()", 2398}, {"do()", 2635}, {"do()", 2701},
        {"do()", 2927}, {"don't()", 245}, {"don't()", 769}, {"don't()", 811}, {"don't()", 879},
        {"don't()", 1376}, {"don't()", 2514}, {"don't()", 2975}, {"do()", 625}, {"do()", 1492},
        {"do()", 2929}, {"don't()", 537}, {"don't()", 713}, {"don't()", 780}, {"don't()", 1404},
        {"don't()", 1609}, {"don't()", 3093}, {"don't()", 3233}, {"do()", 339}, {"do()", 1635},
        {"do()", 1788}, {"do()", 1875}, {"do()", 2284}, {"do()", 3086}, {"don't()", 208},
        {"don't()", 306}, {"don't()", 588}, {"don't()", 1255}, {"don't()", 1945}, {"don't()", 2371},
        {"don't()", 2887}, {"don't()", 3312}, {"do()", 1180}, {"do()", 1326}, {"do()", 1687},
        {"do()", 2583}, {"do()", 2686}, {"do()", 2880}, {"don't()", 714}, {"don't()", 787},
        {"don't()", 866}, {"don't()", 1217}, {"don't()", 1405}, {"don't()", 2030}, {"don't()", 2527},
        {"don't()", 2926}
    };

    // Sort the entries based on the index
    sort(entries.begin(), entries.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    });

    // Output the sorted entries
    for (const auto& entry : entries) {
        cout << entry.first << " " << entry.second << endl;
    }

    return 0;
}
