#ifndef P_STRUCTS_H_INCLUDED
#define P_STRUCTS_H_INCLUDED
#include "poker_structs.h"
#include <iostream>

using namespace std;
void mostrarCarta(tCarta carta);//Muestra el palo y valor de la carta que se le pase como paŕametro.
string mostrarPalo(tCarta carta); //Devuelve el string del palo correspondiente.
void mostrarMenu(); //Muestra en pantalla el menú.
void repartirCarta(tCarta &carta);
void mostrarBaraja(tBaraja* baraja,int valor, int palo);//muestra una carta de la la baraja.
//void mostrarBaraja(tBaraja baraja);
tBaraja* inicializarBaraja();
void setCarta(int listCartas[4][52],tCarta carta);
bool getCarta(int listaCartas[][52],tCarta carta);//Esta función nos permite saber si ya hemos repartido esa carta.

#endif // P_STRUCTS_H_INCLUDED
