#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int safe=0, unsafe=0;
bool init=true;

void check(vector<int> list, int flag, int index){

    if(index+1 == list.size()){
        safe++;
        return;
        }

    int res = list[index] - list[index+1];
    if (init == true)
    {   
        init=false;
        if(res<=3 && res>=1){
            flag = 1;
            return check(list, flag, index+1);
        }
        else if(res>=-3 && res<=-1){
            flag = -1;
            return check(list, flag, index+1);
        }
        unsafe++;
        return;
    }

    if(res<=3 && res>=1 && flag==1){
        return check(list, flag, index+1);
    }
    else if(res>=-3 && res<=-1 && flag ==-1){
        return check(list, flag, index+1);
    }
    unsafe++;
    return;

} 

int main()
{   
    //variable declaration
    int num;
    vector<int> list;
    string line;
    ifstream file;

    //input reading
    file.open("input2.txt");
    while (getline(file, line))
    {
        init=true; 
        list.clear();
        istringstream word(line);
        while(word>>num){
            list.push_back(num);
        }   
        check(list, 0, 0);
        }
    file.close();
     

    cout << "Safe: " << safe <<endl;
    cout << "Unsafe: " << unsafe << endl;
   


    return 0;
}

