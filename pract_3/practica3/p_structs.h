#ifndef P_STRUCTS_H_INCLUDED
#define P_STRUCTS_H_INCLUDED
#include "poker_structs.h"
#include <iostream>

using namespace std;
void mostrarCarta(tCarta& carta);//Muestra el palo y valor de la carta que se le pase como paŕametro.
string mostrarPalo(int indice); //Devuelve el string del palo correspondiente.
void mostrarMenu(); //Muestra en pantalla el menú.
void repartirMano(tBaraja& baraja,tMano& mano);
void mostrarBaraja(tBaraja& baraja);//Función para mostrar las cartas de la baraja.
void inicializarBaraja(tBaraja& baraja);//Función para inicializar las cartas de la baraja.
void sacarCarta(tBaraja& baraja,tCarta& carta);
void ordenarMano(tMano& mano);//Función para ordenar las cartas de una mano, de forma ascencendente en función de su valor.
void calcularPuntosMano(tMano& mano);// Función para calcular los puntos de una mano.
void mostrarMano(tMano& mano);//Función que simplemente muestra las cartas que contiene una mano.

bool comprobarMismoPalo(tMano& mano);

void comprobarEscaleraReal(tMano& mano);
void comprobarEscaleraColor(tMano& mano);
void comprobarPoker(tMano& mano);
void comprobarFull(tMano& mano);
void comprobarColor(tMano& mano);
void comprobarEscalera(tMano& mano);
void comprobarTrio(tMano& mano);
void comprobarDoblePareja(tMano& mano);
void comprobarPareja(tMano& mano);
void comprobarCartaAlta(tMano& mano);
void encontrarManoGanadora();
void jugar(tMano manos[],int num_jug,int election);
int pedirJugadores();
void anadirMano(tJuego& juego,int num_jug);
void juegan2(tMano manos[],int num_jug,int election);//Función que se realiza cuando juegan 2 personas.
//void añadirMano(int num_jugadores,tJuego juego);
void comprobarGanador(tMano manos1,tMano manos2,int num_jug);

#endif // P_STRUCTS_H_INCLUDED
