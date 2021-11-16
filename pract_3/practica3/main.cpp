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

    mano.carta[0].valor = 9;
    mano.carta[0].palo = 1;

    mano.carta[1].valor = 10;
    mano.carta[1].palo = 1;

    mano.carta[2].valor = 5;
    mano.carta[2].palo = 2;

    mano.carta[3].valor = 5;
    mano.carta[3].palo = 1;

    mano.carta[4].valor = 12;
    mano.carta[4].palo = 1;

    //ordenarMano(mano);

    int jugar = 1;
    while(jugar == 1)
    {
        ordenarMano(mano);
        //repartirMano(baraja,mano);
        calcularPuntosMano(mano);
        cout<<"Quieres seguir jugando??(1/0)";
        cin>>jugar;
    }

    //mostrarCarta(mano.carta[1]);
    //repartirCarta(carta)


    //mostrarBaraja(baraja);


    return 0;
}
