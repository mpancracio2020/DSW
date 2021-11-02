//Author: Marvin Pancracio Manso.
//File: mmind.cpp .
//This file provides the mmind functionality.

#include "mmind.h"
#include "mmind_basic.h"
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
        //Hemos sido flexibles y le damos al jugador varias opciones "correctas" de que introduzca el nivel,
        //en función de su gramática.

        if ((level == "básico")| ( level == "basico")| ( level == "Basico")| ( level == "Básico"))
        {
            sentinel = false;
            level = "básico";
        }
        else if ((level == "clásico") | (level == "clasico")| ( level == "Clasico")| ( level == "Clásico"))
        {
            sentinel = false;
            level = "clásico";
        }
        else if ((level == "difícil") | (level == "dificil")| ( level == "Dificil")| ( level == "Difícil"))
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
    cout<<"Your try lenght must be : "<<length<<endl;

    return length;
}

void rellenar_num_secreto(unsigned int numSecretoArray[],unsigned  int l,unsigned const elem,string election)
{
    //es semejante a la función de rellenarIntento con la diferencia de digitos repetidos o no.
    if((election == "n")|(election == "N"))
    {
        bool repeted = true;
        int sent = 1; // index
        while (repeted)
        {
            srand(time(NULL));
            for(int i = 0; i < elem;i++)
            {
                numSecretoArray[i] = rand()% (l) +1;
            }
            repeted = comprobarDigitosRepetidos(numSecretoArray,elem); //utilizamos esta funcion para comprobar
            //si hay números repetidos, este bucle no acabará hasta que el valor de repeted sea false, lo que
            // equivale a que no tenga números repetidos.
        }
    }
    else if ((election == "y")|(election == "Y"))
    {
        srand(time(NULL));
        for(int i = 0; i < elem;i++)
        {
            numSecretoArray[i] = rand()% (l) +1;
        }
    }
}
int get_interval(string level)
{
    int interval;

    if(level == "básico") interval = 4;
    else if(level =="clásico") interval = 6;
    else if(level =="difícil") interval = 8;
    cout<<"Your interval: "<<interval<<endl;

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
    cout <<array_string<<endl;
}
string get_election()
{
    string chose;
    cout << "Do you want repeted numbers?(Y/n): "<<endl;
    cin>>chose;
    return chose;
}
void play(string nivel, unsigned int numSecreto[], unsigned int intentoDigitos[],const int num_elem,unsigned int intento,int interval,string election_user)
{
    int num_max;
    int attempts;
    int aciertos;

    rellenar_num_secreto(numSecreto,interval,num_elem,election_user);
    rellenarIntento(intento,intentoDigitos, num_elem);
    int n_aciertos = calcularAciertos(numSecreto,intentoDigitos,num_elem);
    calcularSemiaciertos(numSecreto,intentoDigitos,num_elem);

    if(nivel == "básico"){num_max = 6;attempts = 5;aciertos = 3;}
    else if(nivel == "clásico"){num_max = 8;attempts = 7;aciertos = 4;}
    else if(nivel == "difícil"){num_max = 10;attempts = 9;aciertos = 5;}

    for(int i = 0; i < num_max;i++)
    {
        cout<<"You have "<< attempts-i<<" more attempts"<<endl;
        int intento = get_intento();
        rellenarIntento(intento,intentoDigitos, num_elem);
        int n_aciertos = calcularAciertos(numSecreto,intentoDigitos,num_elem);
        calcularSemiaciertos(numSecreto,intentoDigitos,num_elem);
        if(n_aciertos == aciertos)
        {
            i = num_max;
            cout<<"You win!!! "<<endl;
        }
        else if ((n_aciertos != aciertos) & ((i+1) == num_max)) {loser(numSecreto,num_elem);}
    }
}
void loser(unsigned int numSecreto[],const int num_elem)
{
    cout<< "The number was: ";
    array_to_string(numSecreto,num_elem);
    cout<<"Try again!"<<endl;
}

