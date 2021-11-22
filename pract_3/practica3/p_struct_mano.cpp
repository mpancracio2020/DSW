#include "poker_structs.h"
#include "p_struct_mano.h"
#include "p_structs.h"
#include "p_struct_comprobaciones.h"
#include "p_struct_carta.h"
#include "p_struct_baraja.h"
#include "p_struct_juego.h"
#include <iostream>
#include <array>

// Este fichero implementa la funcionalidad del módulo mano.

void repartirMano(tBaraja& baraja,tMano& mano)
{   //Función para repartir una mano de cartas a cada jugador, teniendo en cuenta las cartas ya dadas.

    mano.numero = 0; //Inicializamos el atributo número del objeto carta, el cuál irá aumentando
    //a la vez que el número de cartas introducidas en la mano.

    for(int i = 0; i < 5;i++)
    {
        sacarCarta(baraja,mano.carta[i]);
        mano.numero++;
    }
}

void ordenarMano(tMano& mano)
{
    tCarta carta_aux; // carta auxiliar para poder mover las cartas de posición (método de la burbuja).
    for(int i = 1; i < 6 ;i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(mano.carta[j+1].valor < mano.carta[j].valor)
            {   //Fácil, si el valor de carta[i] es menor que el de cart[j] se intercambian las posiciones.
                carta_aux = mano.carta[j];
                mano.carta[j] = mano.carta[j+1];
                mano.carta[j+1] = carta_aux;
            }
        }
    }
    //mostrarMano(mano);
}

void mostrarMano(tMano& mano)
{// Muestra las cartas de un mano, recorriendo la array de cartas que contiene la estructura mano.
    for(int i = 0; i < 5; i++)
    {
        cout<<"______________"<<endl;
        cout<<"|Carta número: "<< i+1 <<"|"<<endl;
        cout<<"|palo: "<< mano.carta[i].palo <<"|"<<endl;
        cout<<"|valor: "<< mano.carta[i].valor <<"|"<<endl;
        cout<<"|_____________|"<<endl;
    }
}

void inicializarManos(tMano manos[])
{// Funciónn que inicializa una array de manos, mediante un bucle.
    tMano mano;
    for(int i = 0; i < 4; i++)
    {
        manos[i] = mano;
    }
}


