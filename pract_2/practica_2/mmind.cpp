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
    cout<<"Your try lenght must be : "<<length<<endl;

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

void rellenar_num_secreto(unsigned int numSecretoArray[],unsigned  int l,unsigned const elem,string election)
{
    //es semejante a la función de rellenarIntento con la diferencia de digitos repetidos o no.
    if(election == "n")
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
    else if (election == "y")
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
    cout << "Numero que contiene la array: " << array_string<<endl;
}
string get_election()
{
    string chose;
    cout << "Do you want repeted numbers?(Y/n): "<<endl;
    cin>>chose;
    return chose;
}

void comprobarDigitosRepetidos_Secretos(const unsigned int numero[], const int num_elem,string chose)
{
    bool repeted = false; //en cuanto el bucle anidado de abajo detecte algún nº repetido el valor de repeted cambiará
                          //y se sabrá que hay valores repetidos.
    int i = 0;

    while (!repeted)
    {
        int k = numero[i];
        for(int j = (i+1); j <(num_elem);j++)
        {
            if(k == numero[j])
            {
                repeted = true;
                cout<<"Numeros repetidos en: "<< i <<" pos y en: "<<j<<endl;
            }
        }
        i++;
    }
    cout<<"repeted value: "<< repeted<< endl;

}
void intentos(string nivel, unsigned int numSecreto[], unsigned int intentoDigitos[],const int num_elem,unsigned int intento,int interval,string election_user)
{

    //array_to_string(numSecreto,num_elem);
    rellenar_num_secreto(numSecreto,interval,num_elem,election_user);
    rellenarIntento(intento,intentoDigitos, num_elem);
    array_to_string(numSecreto,num_elem);
    array_to_string(intentoDigitos,num_elem);
    int n_aciertos = calcularAciertos(numSecreto,intentoDigitos,num_elem);
    calcularSemiaciertos(numSecreto,intentoDigitos,num_elem);

    if(nivel == "básico")
    {

        for(int i = 0; i < 6;i++)
        {
            cout<<"You have "<< 5-i<<" more attempts"<<endl;

            int intento = get_intento();

            rellenarIntento(intento,intentoDigitos, num_elem);
            array_to_string(numSecreto,num_elem);
            array_to_string(intentoDigitos,num_elem);
            int n_aciertos = calcularAciertos(numSecreto,intentoDigitos,num_elem);
            calcularSemiaciertos(numSecreto,intentoDigitos,num_elem);
            //comprobarDigitosRepetidos(intentoDigitos,num_elem);
            if(n_aciertos == 3)
            {
                i = 5;
                cout<<"You win!!! "<<endl;
            }
        }

    }

    else if(nivel == "clásico")
    {
        for(int i = 0; i < 8;i++)
        {
            cout<<"You have "<< 7-i<<" more attempts"<<endl;

            int intento = get_intento();

            rellenarIntento(intento,intentoDigitos, num_elem);
            array_to_string(numSecreto,num_elem);
            array_to_string(intentoDigitos,num_elem);
            int n_aciertos = calcularAciertos(numSecreto,intentoDigitos,num_elem);
            calcularSemiaciertos(numSecreto,intentoDigitos,num_elem);
            //comprobarDigitosRepetidos(intentoDigitos,num_elem);

            if(n_aciertos == 4)
            {
                i = 8;
                cout<<"You win!!! "<<endl;
            }

        }

    }

    else if(nivel == "difícil")

    {
        for(int i = 0; i < 10;i++)
        {
            cout<<"You have "<< 9-i<<" more attempts"<<endl;

            int intento = get_intento();

            rellenarIntento(intento,intentoDigitos, num_elem);
            array_to_string(numSecreto,num_elem);
            array_to_string(intentoDigitos,num_elem);
            int n_aciertos = calcularAciertos(numSecreto,intentoDigitos,num_elem);
            calcularSemiaciertos(numSecreto,intentoDigitos,num_elem);
            //comprobarDigitosRepetidos(intentoDigitos,num_elem);
            if(n_aciertos == 5)
            {
                i = 10;
                cout<<"You win!!! "<<endl;
            }
        }
    }
}
