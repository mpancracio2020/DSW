#include <iostream>
#include "poker_structs.h"
#include "p_structs.h"

using namespace std;

int main()
{
    tCarta cartaRandom;

    int lista[4][52];
    int k = 0;
    //lista[2][5] = 5;

    tCarta carta;
    carta.valor = 5;
    carta.palo = 2;

    getCarta(lista,carta);

    /*repartirCarta(cartaRandom);
    mostrarCarta(cartaRandom);
    mostrarPalo(cartaRandom);*/
    return 0;
}
