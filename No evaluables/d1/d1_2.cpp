#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int sum=0;

int check(vector<int> list, int number, int index){
    if (list[index]==number)
    {
        sum++;
    }
    if (index == list.size())
    {
        return sum;
    }
    return check(list, number, index+1);
}

int main(int argc, char const *argv[])
{   
    //variable declaration
    int num, total=0;
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

    //search for duplicated numbers
    for(int elem:listA){
        sum = 0;
        int n = check(listB, elem, 0);
        total += elem*n;
    }    
    cout << total <<endl;

    return 0;
}
