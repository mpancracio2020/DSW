#ifndef P_STRUCTS_H_INCLUDED
#define P_STRUCTS_H_INCLUDED
#include "poker_structs.h"
#include <iostream>

using namespace std;
void mostrarCarta(tCarta& carta);//Muestra el palo y valor de la carta que se le pase como paŕametro.
string mostrarPalo(int indice); //Devuelve el string del palo correspondiente.
void mostrarMenu(); //Muestra en pantalla el menú.
void repartirCarta(tCarta& carta, tBaraja& baraja,tMano& mano);
void mostrarBaraja(tBaraja& baraja);//Función para mostrar las cartas de la baraja.
void inicializarBaraja(tBaraja& baraja);//Función para inicializar las cartas de la baraja.
void sacarCarta(tBaraja& baraja,tCarta& carta);

#endif // P_STRUCTS_H_INCLUDED
