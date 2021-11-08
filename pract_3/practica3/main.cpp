#include <iostream>
#include "poker_structs.h"
#include "p_structs.h"

using namespace std;

int main()
{
    /*tCarta cartaRandom;

    int lista[4][52];
    int k = 0;
    lista[2][5] = 5;

    tCarta carta;
    carta.valor = 5;
    carta.palo = 2;

    setCarta(lista,carta);

    /*repartirCarta(cartaRandom);
    mostrarCarta(cartaRandom);
    mostrarPalo(cartaRandom);*/

    tBaraja* baraja = inicializarBaraja();
    tCarta c = (*baraja).carta[45];

 //   mostrarCarta(c);
    mostrarBaraja(baraja,3,10);

    return 0;
}
