#include "poker_structs.h"
#include "p_struct_mano.h"
#include "p_structs.h"
#include "p_struct_comprobaciones.h"
#include "p_struct_carta.h"
#include "p_struct_baraja.h"
#include <iostream>
#include <array>
void mostrarBaraja(tBaraja& baraja)
{   //Función para mostrar las cartas que contiene la baraja.
    int index = 0;
    for (int i = 1;i < 5;i++)
    {
        for (int j = 1; j < 14;j++)
        {
            cout<< "palo: "<<baraja.carta[index].palo<<endl;
            cout << " valor:" << baraja.carta[index].valor<<endl;
            index++;
        }
    }
}

void inicializarBaraja(tBaraja& baraja)
{   //Función para inicializar los valores de una baraja.
    baraja.numero = 0;
    for (int i = 1;i < 5;i++)
    {
        for (int j = 1; j < 14;j++)
        {
            baraja.carta[baraja.numero].palo = i;
            baraja.carta[baraja.numero].valor = j;
            baraja.numero++;
        }
    }
}

