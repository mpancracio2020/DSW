//Author: Marvin Pancracio Manso.
//File: mmind.h .
//This file contains prototype info for  mmind program.


#ifndef MMIND_H_INCLUDED
#define MMIND_H_INCLUDED
#include <iostream>
using namespace std;

string get_level();//Pregunta al jugador el nivel que quiere jugar, y lo devuelve como string.
string get_election();//Pregunta al jugador si quiere jugar con números repetidos, y lo devuelve como string.
int get_intento();//Pregunta al jugador el número que cree que es, y lo devuelve como int.
int get_length(string level);//Devuelve el valor de la longitud de las arrays dependiendo del nivel que se quiere jugar.
int get_interval(string level);//Devuelve el valor del intervalo que comprenderán los dígitos del numero a adivinar,
                               //dependiendo del nivel que se quiere jugar.

//Esta funcíon rellena el array numScreto que contiene el valor del número a adivinar, teniendo en cuenta si los dígitos
//pueden ser repetidos o no.
void rellenar_num_secreto(unsigned int numSecretoArray[],unsigned const int l,unsigned const elem, string election);

void array_to_string(unsigned int arr[],int n);//Pasa de una array de int a string y lo imprime en pantalla.

//Esta función ejecuta el resto de funciones el número de veces que corresponden por intento, hasta que bien ganes, o bien pierdas.
void play(string nivel, unsigned int numSecreto[], unsigned int intentoDigitos[],const int num_elem,unsigned int intento,int interval,string election_user);

void loser(unsigned int numSecreto[],const int num_elem);//Esta función imprime en pantalla el numero secreto.
#endif // MMIND_H_INCLUDED
