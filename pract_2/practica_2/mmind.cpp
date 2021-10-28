//Author: Marvin Pancracio Manso.
//File: mmind.cpp .
//This file provides the mmind functionality.

#include "mmind.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

string get_level()
{
    string level;
    string level_value;
    bool sentinel = true;

    while (sentinel)
    {

        cout << "Enter the level you want to play: "<< endl;
        cin >> level;

        if ((level == "básico")| ( level == "basico"))
        {
            sentinel = false;
            level = "básico";


        }
        else if ((level == "clásico") | (level == "clasico"))
        {
            sentinel = false;
            level = "clásico";

        }
        else if ((level == "difícil") | (level == "dificil"))
        {
            sentinel = false;
            level= "difícil";

        }
    }
    cout<<"You choose: "<<level<<" level."<< endl;
    return level;
}
int get_intento()
{
    int intento;
    cout<<"Enter your try: "<<endl;
    cin>>intento;
    return intento;
}
int get_length(string level)
{
    int length;

    if(level == "básico") length = 3;
    else if(level =="clásico") length = 4;
    else if(level =="difícil") length = 5;

    return length;
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


void rellenar_num_secreto(unsigned int numSecretoArray[],unsigned  int l,unsigned const elem)
{


    srand(time(NULL));

    for(int i = 0; i < elem;i++)
    {

        int s_num = rand()% (l+1) +1;

        numSecretoArray[i] = rand()% (l+1) +1;

    }

}
int get_interval(string level)
{
    int interval;

    if(level == "básico") interval = 4;
    else if(level =="clásico") interval = 6;
    else if(level =="difícil") interval = 8;

    return interval;
}

void array_to_string(unsigned int arr[],int n)
{
    string array_string;
    for(int i = 0; i < n; i++)
    {
        array_string += to_string(arr[i]);
        //cout<< "Array position"<< i <<": "<<numSecreto[i]<<endl; //traza para comprobar si la array se rellena bien.
    }
    cout << "Numero que contiene la array: " << array_string<<endl;
}


