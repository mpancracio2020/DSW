#include <iostream>
#include "poker_structs.h"
#include "p_structs.h"
#include "p_struct_juego.h"


using namespace std;

int main()
{

    int continuar = 1;
    tMano manos[4];
    int jugadores = pedirJugadores();
    jugar(manos,jugadores,continuar);
    return 0;
}
