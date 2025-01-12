#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int saif = 0, unsaif = 0;

int check(const vector<int>& list, int flag, int index, bool init) {
    if (index + 1 == list.size()) {
        return 1;
    }

    int res = list[index] - list[index + 1];
    if (init) {
        if (res <= 3 && res >= 1) {
            flag = 1;
            return check(list, flag, index + 1, false);
        } else if (res >= -3 && res <= -1) {
            flag = -1;
            return check(list, flag, index + 1, false);
        }
        return 0;
    }

    if (res <= 3 && res >= 1 && flag == 1) {
        return check(list, flag, index + 1, false);
    } else if (res >= -3 && res <= -1 && flag == -1) {
        return check(list, flag, index + 1, false);
    }
    return 0;
}

void damp(vector<int>& list) {
    if (check(list, 0, 0, true) == 1) {
        saif++;
        return;
    }

    for (int i = 0; i < list.size(); i++) {
        vector<int> temp = list;
        temp.erase(temp.begin() + i);
        if (check(temp, 0, 0, true) == 1) {
            saif++;
            return;
        }
    }
    unsaif++;
}

int main() {
    int num;
    vector<int> list;
    string line;
    ifstream file;

    // Input reading
    file.open("input2.txt");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    while (getline(file, line)) {
        list.clear();
        istringstream word(line);
        while (word >> num) {
            list.push_back(num);
        }
        damp(list);
    }
    file.close();

    cout << "Safe: " << saif << endl;
    cout << "Unsafe: " << unsaif << endl;

    return 0;
}