#include <iostream>
#include "poker_structs.h"
#include "p_structs.h"

using namespace std;

int main()
{
    tJuego juego;
    /*tMano mano;//nueva mano del jugador 1

    mano.carta[0].valor = 6;
    mano.carta[0].palo = 1;

    mano.carta[1].valor = 10;
    mano.carta[1].palo = 1;

    mano.carta[2].valor = 5;
    mano.carta[2].palo = 2;

    mano.carta[3].valor = 5;
    mano.carta[3].palo = 1;

    mano.carta[4].valor = 12;
    mano.carta[4].palo = 1;*/

    //ordenarMano(mano);

    int continuar = 1;

    tMano manos[4];
    int jugadores = 2;

    jugar(manos,jugadores,continuar);


    /*tMano mano_jug_1;
    tMano mano_jug_2;
    tMano manos[4];
    while(jugar == 1)
    {

        repartirMano(baraja,mano_jug_1);
        ordenarMano(mano_jug_1);
        mostrarMano(mano_jug_1);


        repartirMano(baraja,mano_jug_2);
        ordenarMano(mano_jug_2);
        mostrarMano(mano_jug_2);

        calcularPuntosMano(mano_jug_1);
        calcularPuntosMano(mano_jug_2);
        cout<<"Quieres seguir jugando??(1/0)";
        cin>>jugar;
    }*/

    //mostrarCarta(mano.carta[1]);
    //repartirCarta(carta)




    //mostrarBaraja(baraja);


    return 0;
}
