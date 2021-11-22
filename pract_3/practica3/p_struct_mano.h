#ifndef P_STRUCT_MANO_H_INCLUDED
#define P_STRUCT_MANO_H_INCLUDED

void repartirMano(tBaraja& baraja,tMano& mano);
void ordenarMano(tMano& mano);//Función para ordenar las cartas de una mano, de forma ascencendente en función de su valor.
void mostrarMano(tMano& mano);//Función que simplemente muestra las cartas que contiene una mano.
void inicializarManos(tMano manos[]);// Función para inicializar una mano.

#endif // P_STRUCT_MANO_H_INCLUDED
