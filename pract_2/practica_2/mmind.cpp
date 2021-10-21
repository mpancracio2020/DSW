//Author: Marvin Pancracio Manso.
//File: mmind.cpp .
//This file provides the mmind functionality.

#include "mmind.h"
#include <iostream>
#include <vector>
using namespace std;


int get_level()
{
    int level;

    bool sentinel = true;

    while (sentinel)
    {

        cout << "Enter the level you want to play: "<< endl;
        cin >> level;

        if (level > 0 && level <= 3)
        {
            sentinel = false;

        }
    }

    return level;
}

bool get_repeted_num()
{
    bool repeted = true;

    string answer = "";

    cout<< "Do you want repeted numbers?: "<< endl;

    cin>> answer;

    if (answer == "yes")
    {
        cout << "You choose repeted numbers "<< endl;
        return repeted;

    }
    cout << "You choose no repeted numbers "<< endl;
    repeted = false;

    return repeted;


}

void get_array_value(unsigned int arr[])
{
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i <= arrSize; i++)
    {
        cout <<"Pos "<<i<<": "<<arr[i]<<endl;

    }

}


vector<int> rellenar_num_secreto(unsigned const int l)
{

    int num_secreto[l];

    for (int i = 0; i<l; i++)
    {
        int n = 1+rand()%l;
        num_secreto[i] = n;

        cout <<"Num secret: "<<n<< endl;

    }

    return num_secreto;



}

