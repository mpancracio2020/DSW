#ifndef P_STRUCT_COMPROBACIONES_H_INCLUDED
#define P_STRUCT_COMPROBACIONES_H_INCLUDED

//Este fichero contiene la información del módulo comprobación.

bool comprobarMismoPalo(tMano& mano);// Comprueba si las cartas de una mano son todas del mismo palo, devolviendo
                                     // true si lo fuesen o false si no lo fuesen.

void comprobarEscaleraReal(tMano& mano);//Este método comprueba si en una mano hay Escalera real o no, asignando la puntuación
                                        // correspondiente en el caso de tener.

void comprobarEscaleraColor(tMano& mano);//Este método comprueba si en una mano hay Escalera de color o no, asignando la puntuación
                                        // correspondiente en el caso de tener.

void comprobarPoker(tMano& mano);//Este método comprueba si en una mano hay Poker o no, asignando la puntuación
                                        // correspondiente en el caso de tener.

void comprobarFull(tMano& mano);//Este método comprueba si en una mano hay Full  o no, asignando la puntuación
                                        // correspondiente en el caso de tener.

void comprobarColor(tMano& mano);//Este método comprueba si en una mano hay Color o no, asignando la puntuación
                                        // correspondiente en el caso de tener.

void comprobarEscalera(tMano& mano);//Este método comprueba si en una mano hay Escalera o no, asignando la puntuación
                                        // correspondiente en el caso de tener.

void comprobarTrio(tMano& mano);//Este método comprueba si en una mano hay Trio  o no, asignando la puntuación
                                        // correspondiente en el caso de tener.

void comprobarPareja(tMano& mano);//Este método comprueba si en una mano hay Pareja/Doble Pareja o no, asignando la puntuación
                                        // correspondiente en el caso de tener.

void comprobarCartaAlta(tMano& mano);//Este método comprueba si en una mano hay Carta alta o no, asignando la puntuación
                                        // correspondiente en el caso de tener.


void comprobarGanador(tMano manos[],int num_jug);// Compara la puntuación de las manos, contenidas en la array de manos, devolviendo
                                                 // un ganador o empate.

void compiten2(tMano manos[], int num_jug); //Función que compara los puntos de las manos de los 2 jugadores y determina el ganador.
void compiten3(tMano manos[],int num_jug);//Función que compara los puntos de las manos de los 3 jugadores y determina el ganador.
void compiten4(tMano manos[], int num_jug);//Función que compara los puntos de las manos de los 4 jugadores y determina el ganador.

void calcularPuntosMano(tMano& mano);// Función para calcular los puntos de una mano.

#endif // P_STRUCT_COMPROBACIONES_H_INCLUDED
