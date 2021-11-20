#include <iostream>
#include "poker_structs.h"
#include "p_structs.h"

using namespace std;

int main()
{

    int continuar = 1;
    tMano manos[4];
    int jugadores = pedirJugadores();
    jugar(manos,jugadores,continuar);

    /*tMano prueba;
    prueba.carta[0].palo = 3;
    prueba.carta[0].valor = 3;

    prueba.carta[1].palo = 1;
    prueba.carta[1].valor = 3;

    prueba.carta[2].palo = 4;
    prueba.carta[2].valor = 3;

    prueba.carta[3].palo = 4;
    prueba.carta[3].valor = 13;

    prueba.carta[4].palo = 3;
    prueba.carta[4].valor = 5;

    ordenarMano(prueba);
    prueba.puntos = 0;
   // mostrarMano(prueba);

    calcularPuntosMano(prueba);
    cout<<"Puntos: "<<prueba.puntos<<endl;*/
    return 0;
}
