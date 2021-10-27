//Author: Marvin Pancracio Manso.
//File: mmind_basic.cpp .
//This file provides the mmind_basic functionality.

#include "mmind_basic.h"
#include <iostream>

using namespace std;

bool comprobarDigitosRepetidos(const unsigned int numero[], const int num_elem)
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
    return repeted;

}

void rellenarIntento(unsigned int intento, unsigned int intentoDigitos[], const int num_elem)
{
        int n = num_elem-1; //indice máximo de la array.

        for (int i = n; i >=0; i--)
        {
            intentoDigitos[i] = intento % 10;
            intento /= 10;
        }
}

unsigned int calcularAciertos(const unsigned int numSecreto[],
                              const unsigned int intentoDigitos[],
                              const int num_elem)
{
    int n_aciertos = 0;

    for(int i = 0; i < num_elem; i++)
    {
        if(numSecreto[i] == intentoDigitos[i]) n_aciertos++;
    }
    cout<<"Número de aciertos: "<<n_aciertos<<endl;

}


unsigned int calcularSemiaciertos(const unsigned int numSecreto[],
                                  const unsigned int intentoDigitos[],
                                  const int num_elem)

{
    int n_semi_aciertos = 0;

    for(int i = 0; i < num_elem; i++)
    {
        for(int j = 0;j < num_elem; j++)
        {
            if(numSecreto[i] == intentoDigitos[j]&& i !=j) n_semi_aciertos++;
        }
    }
    cout<<"Número de semiaciertos: "<<n_semi_aciertos<<endl;



}





