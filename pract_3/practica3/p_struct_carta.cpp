#include "poker_structs.h"
#include "p_struct_mano.h"
#include "p_structs.h"
#include "p_struct_comprobaciones.h"
#include "p_struct_carta.h"
#include "p_struct_baraja.h"
#include <iostream>
#include <array>

void sacarCarta(tBaraja& baraja,tCarta& carta)
{   // Función para sacar una carta al azar de la baraja y retirarla de la misma.
    // Para marcar que una carta ha sido retirada marcaremos su palo como 0, de esta forma
    // miraremos si el valor numérico del palo es menor que 1, en tal caso, la carta ya estará repartida
    bool repartida = true;
    int numCarta;
    while (repartida)
    {
        srand(time(NULL));
        numCarta = rand()% (52) +0;
        if(baraja.carta[numCarta].palo != 0) repartida = false;
    }
    carta.palo = baraja.carta[numCarta].palo;
    carta.valor = baraja.carta[numCarta].valor;
    baraja.carta[numCarta].palo = 0;
}
void mostrarCarta(tCarta& carta)
{
    cout<<"Palo: "<<carta.palo<<endl;
    cout<<"Valor: "<<carta.valor<<endl;
}
