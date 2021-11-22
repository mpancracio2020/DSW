#ifndef P_STRUCTS_H_INCLUDED
#define P_STRUCTS_H_INCLUDED
#include "poker_structs.h"
#include <iostream>

using namespace std;
void mostrarMenu(); //Muestra en pantalla el menú.
void calcularPuntosMano(tMano& mano);// Función para calcular los puntos de una mano.

void encontrarManoGanadora();
void jugar(tMano manos[],int num_jug,int election);
int pedirJugadores();
void juegan2(tMano manos[],int num_jug,int election);//Función que se realiza cuando juegan 2 personas.
void juegan3(tMano manos[],int num_jug,int election); //Función para jugar con 3 jugadores.
void juegan4(tMano manos[],int num_jug,int election);

void compiten2(tMano manos[], int num_jug);
void compiten3(tMano manos[],int num_jug);
void compiten4(tMano manos[], int num_jug);
#endif // P_STRUCTS_H_INCLUDED
