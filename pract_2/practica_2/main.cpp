#include <iostream>
#include "mmind_basic.h"
#include "mmind.h"

using namespace std;

int main()
{
    string level = get_level(); // pregunta al usuario que nivel quiere jugar y lo almacena en una variable tipo string.
    string election_user = get_election(); // pregunta al usuario si quiere jugar con números que contengan dígitos repetidos
                                           // y lo almacena en una variable de tipo string.

    int num_elem = get_length(level); // creamos unas variables de tipo int que contienen el valor de la longitud del número secreto
    int interval = get_interval(level);// y el intervalo de los dígitos. Éstos serán equivalentes al "level" que elija el usurio,
                                       // además de imprimir en pantalla dichos valores.

    int intento = get_intento(); // solicitamos al usuario el primer intento.

    unsigned int intentoDigitos[num_elem]; // creamos las arrays que contendrán los intentos del jugador y el número secreto, respectivamente.
    unsigned int numSecreto[num_elem];


    intentos(level,numSecreto,intentoDigitos,num_elem,intento,interval,election_user);
    //dentro de esta función se ejecutarán el número de "intentos" que tenga el jugador dependiendo del nivel.
    //Por cada intento se compararán los aciertos y semiaciertos de cada intento.


    return 0;
}
