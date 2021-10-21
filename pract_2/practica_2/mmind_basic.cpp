//Author: Marvin Pancracio Manso.
//File: mmind_basic.cpp .
//This file provides the mmind_basic functionality.

#include "mmind_basic.h"
#include <iostream>

using namespace std;

bool comprobarDigitosRepetidos(const unsigned int numero[], const int num_elem)
{

}

void rellenarIntento(unsigned int intento, unsigned int intentoDigitos[], const int num_elem)
{
        int n = num_elem-1;

        for (int i = n; i >=0; i--)
        {
            intentoDigitos[i] = intento % 10;
            intento /= 10;
        }

        /*for(int i = n; i >= 0; i--)
        {
            cout <<"Pos "<<i<<": "<<intentoDigitos[i]<<endl;
        }*/
}

unsigned int calcularAciertos(const unsigned int numSecreto[],
                              const unsigned int intentoDigitos[],
                              const int num_elem)
{}


unsigned int calcularSemiaciertos(const unsigned int numSecreto[],
                                  const unsigned int intentoDigitos[],
                                  const int num_elem)

{}





