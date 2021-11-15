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
    tBaraja baraja;
    inicializarBaraja(baraja);
    //mostrarBaraja(baraja);

    //tCarta carta;
    //sacarCarta(baraja,carta);
    //mostrarCarta(carta);

    tMano mano;//nueva mano del jugador 1

    repartirMano(baraja,mano);

    //mostrarCarta(mano.carta[1]);
    //repartirCarta(carta)


    //mostrarBaraja(baraja);


    return 0;
}
