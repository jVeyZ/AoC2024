#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int main(int argc, char const *argv[])
{   
    //variable declaration
    int num;
    vector<int> listA, listB;
    string line;
    ifstream file;

    //input reading
    file.open("input.txt");
    while (getline(file, line))
    {
        istringstream word(line);
        for (int i = 0; i < 2; i++)
        {
            word >> num;
            if (i==0)
            {
                listA.push_back(num);
            }
            else{
                listB.push_back(num);
            }
            
        }   
    }
    file.close();

    //sort lists
    sort(listA.begin(), listA.end());
    sort(listB.begin(), listB.end());

    //get val diff
    num = 0;
    for(int i = 0; i < 1000; i++){
        num += abs(listA[i] - listB[i]);
    }
    cout << num;

    return 0;
}
