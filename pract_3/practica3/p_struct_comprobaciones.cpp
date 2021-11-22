#include "poker_structs.h"
#include "p_struct_mano.h"
#include "p_structs.h"
#include "p_struct_comprobaciones.h"
#include "p_struct_carta.h"
#include "p_struct_baraja.h"
#include "p_struct_juego.h"
#include <iostream>
#include <array>

// Este fichero implementa la funcionalidad del módulo comprobaciones, el cual comprueba todas las posibles combinaciones de
// cartas y los posibles empates/ganadores/ganador.

void comprobarEscaleraReal(tMano& mano)
{// Función para comprobar que tenemos eslacera real.
    int valor_escalera = 13;
    int valor_min = 9;
    bool mismo_palo = comprobarMismoPalo(mano);

    if(mismo_palo == true)
    {//Comprobamos si todo es del mismo palo.
        for(int i = 5; i > 0; i--)
        {
            if(mano.carta[i].valor == valor_escalera) valor_escalera--;
        }
    }
    if((valor_escalera == valor_min) && (mano.carta[0].valor == 1 ))
    {// Si se cumple que los valores de la array son los necesarios para tener escalera real (13,12,11,10,9), tendremos escalera real.
        mano.puntos = 10; cout<<"Tienes Escalera Real :)"<<endl;
    }
}

void comprobarEscaleraColor(tMano& mano)
{//Función para comprobar si hay escalera de color.
    bool mismo_palo = comprobarMismoPalo(mano);
    bool escalera_color = true;

    if(mismo_palo == true)
    {// La primera condición es tener todo del mismo palo.
        for(int i = 0; i < 5; i++)
        {
            if((mano.carta[i].valor > mano.carta[i+1].valor)&((mano.carta[i+1].valor - mano.carta[i].valor) == 1)) escalera_color = false;
        }
        if(escalera_color = true)
        {// Si todo es del mismo palo y se prueba que es escalera, hay escalera de color.
            mano.puntos = 9; cout << "Tienes Escalera de color :)"<<endl;
        }
    }
}

void comprobarPoker(tMano& mano)
{// Función para comprobar si hay poker.
    bool poker = true;
    int contador_poker = 0;
    int VALOR_Q = 12;
    for(int i = 0; i < 5; i++)
    {// Recorremos la mano, y si todos los valores son iguales, el contador será 3 por lo que tendremos poker.
       if(mano.carta[i].valor == mano.carta[i+1].valor) contador_poker++;
    }
    if(contador_poker == 3)
    {
        cout<< "Tienes poker de locos"<<endl;
        mano.puntos = 8;
    }
}

void comprobarFull(tMano& mano)
{// Esta funcion comprueba si hay full o no, para ello llamamos a trio. Si después de su comprobación, la puntuación es igual a 4 (hay trio), comprobamos si hay pareja.
    comprobarTrio(mano);
    int contador_full = 0;
    if(mano.puntos == 4)
    {
        comprobarPareja(mano);
    }
    if(mano.puntos == 2)
    {// En el caso de tener pareja también, tendremos full.
        cout<<"Tienes Full!"<<endl;
        mano.puntos = 7;
    }
}

void comprobarColor(tMano& mano)
{// Si tenemos todo del mismo palo, hay color.
    if(mano.puntos == 0)
    {//Comprobamos que no hay otra posible comprobación (que no confunda escalera de color con color).
        bool color = comprobarMismoPalo(mano);
        if(color == true)
        {
            cout<<"Tienes color :)"<<endl;
            mano.puntos = 6;
        }
    }
}

void comprobarEscalera(tMano& mano)
{// Función para comprobar si hay escalera o no.
    int contador_escalera = 0;
    for(int i = 0; i < 4; i++)
    {// Recorremos la array y comparamos los valores, si están en orden ascendente y su diferencia es de 1, tendremos escalera.
        if((mano.carta[i].valor < mano.carta[i+1].valor) & ((mano.carta[i+1].valor - mano.carta[i].valor) == 1)) contador_escalera++;
    }
    if(contador_escalera == 4)
    {
        mano.puntos = 5; cout << "Tienes Escalera :)"<<endl;
    }
}

void comprobarTrio(tMano& mano)
{//Función para comprobar si hay trio.
    int contador_trio = 0;
    if(mano.puntos == 0)
    {
       for(int i = 0; i < 3; i++)
       {// Recorremos la array dando pasos de 3 en 3, ya que buscamos un trio.
            int a = mano.carta[i].valor;
            int b = mano.carta[i+1].valor;
            int c = mano.carta[i+2].valor;
            if((a == b)& (a == c) & ( b - a == 0)) contador_trio++; // Si se cumplen las 3 condiciones tendremos un trio.
        }
        if(contador_trio == 1)
        {
            mano.puntos = 4;
            cout << "Tienes Trio :)"<<endl;
        }
    }
}

void comprobarPareja(tMano& mano)
{// Función para comprobar si hay pareja o no.
    int contador_pareja = 0;
    if(mano.puntos == 0) // Puede darse el caso de que tengamos trío en lugar de pareja, para evitar errores de calculo de puntuación
                         // antes de comprobar que tengamos pareja veamos si ya tenemos trío, en esa situación tener una pareja
                         // con los mismos números es posible, pero de nada sirve calcularlo, pues trío > pareja.
    {
        for(int i = 0; i < 5; i++)
        {// Recorremos toda la mano comparando los valores, buscando una pareja, o 2, como máximo.
            if((mano.carta[i].valor == mano.carta[i+1].valor)&((mano.carta[i+1].valor - mano.carta[i].valor) == 0)) contador_pareja++;
        }
        if(contador_pareja == 1)
        {
            mano.puntos = 2;
            cout << "Tienes Pareja :)"<<endl;
        }
        else if(contador_pareja == 2)
        {
            cout << "Tienes Doble Pareja :)"<<endl;
            mano.puntos = 3;
        }
    }
}

void comprobarCartaAlta(tMano& mano)
{// Función para determinar Carta Alta.
    if(mano.puntos == 0)
    {// Comprobamos que no se haya adjudicado ninguna puntuación, si puntos es 0,
    //  significa que no tenemos ninguna de las combinaciones, por lo que solo nos queda la combinación de carta alta.
        cout<<"Carta alta :)"<<endl;
        mano.puntos =1;
    }
}
bool comprobarMismoPalo(tMano& mano)
{ //Función para comprobar el palo de toda una mano.
    bool mismo_palo = true; // Variable para comprobar que son del mismo palo. Si todas las cartas de la mano son del mismo palo, esta variable no cambiará a false.
    int indice = 0;

    for(int j = 1; j < 6; j++)
    {// Recorremos toda la mano y comparamos los palos.
        if(mano.carta[indice].palo != mano.carta[j].palo) mismo_palo = false;
    }
    return mismo_palo;// Devolverá false, si hay distintos palos, o true si toda la mano es de mismo palo.
}

void comprobarGanador(tMano manos[],int num_jug)
{// Aquí llamamos a la comprobación de los puntos, según el nº de jugadores llamamos a una función compiten diferente.
    if(num_jug == 2)
    {
        compiten2(manos,num_jug);
    }
    else if(num_jug == 3)
    {
        compiten3(manos,num_jug);
    }
    else if(num_jug == 4)
    {
        compiten4(manos,num_jug);
    }
}

void compiten2(tMano manos[], int num_jug)
{// Para saber quién ha ganado o empatado, comprobamos los puntos de cada jugador, los cuales están almacenados en las distintas
 // manos que se encuentran en la array manos.
    if(manos[0].puntos < manos[1].puntos)
    {
        cout<<"\nGana el jugador 2!!!"<<endl;
        cout<<"Con la siguienteb mano: "<<endl;cout<<"_______________________"<<endl;
        mostrarMano(manos[1]);

    }
    else if(manos[0].puntos > manos[1].puntos)
    {
        cout<<"\nGana el jugador 1!!!!"<<endl;
        cout<<"Con la siguienteb mano: "<<endl;cout<<"_______________________"<<endl;
        mostrarMano(manos[0]);
    }
    else
    {
        cout<<"\nEmpate!!!"<<endl;
    }
}

void compiten3(tMano manos[],int num_jug)
{// Análogo a la función anterior, pero con 3 jugadores, lo que incrementa el nº de condicionales.
    if(manos[0].puntos < manos[1].puntos & manos[2].puntos < manos[1].puntos)
    {
        cout<<"\nGana el jugador 2!!!"<<endl;
        cout<<"Con la siguienteb mano: "<<endl;cout<<"_______________________"<<endl;
        mostrarMano(manos[1]);
    }
    else if(manos[0].puntos > manos[1].puntos & manos[0].puntos > manos[2].puntos)
    {
        cout<<"\nGana el jugador 1!!!!"<<endl;
        cout<<"Con la siguienteb mano: "<<endl;cout<<"_______________________"<<endl;
        mostrarMano(manos[0]);
    }
    else if(manos[2].puntos > manos[1].puntos & manos[2].puntos > manos[0].puntos)
    {
        cout<<"\nGana el jugador 3!!!!"<<endl;
        cout<<"Con la siguienteb mano: "<<endl;cout<<"_______________________"<<endl;
        mostrarMano(manos[2]);
    }
    else
    {
        cout<<"\nEmpate!!!"<<endl;
    }
}
void compiten4(tMano manos[],int num_jug)
{// Análogo a la función anterior, pero con 4 jugadores, lo que incrementa el nº de condicionales.
    if((manos[0].puntos < manos[1].puntos) & (manos[2].puntos < manos[1].puntos) & (manos[3].puntos < manos[1].puntos))
    {
        cout<<"\nGana el jugador 2!!!"<<endl;
        cout<<"Con la siguienteb mano: "<<endl;cout<<"_______________________"<<endl;
        mostrarMano(manos[1]);
    }
    else if((manos[0].puntos > manos[1].puntos) & (manos[0].puntos > manos[2].puntos) & (manos[0].puntos > manos[3].puntos))
    {
        cout<<"\nGana el jugador 1!!!!"<<endl;
        cout<<"Con la siguienteb mano: "<<endl;cout<<"_______________________"<<endl;
        mostrarMano(manos[0]);
    }
    else if((manos[2].puntos > manos[1].puntos)& (manos[2].puntos > manos[0].puntos) & (manos[2].puntos > manos[3].puntos))
    {
        cout<<"\nGana el jugador 3!!!!"<<endl;
        cout<<"Con la siguienteb mano: "<<endl;cout<<"_______________________"<<endl;
        mostrarMano(manos[2]);
    }
    else if((manos[3].puntos > manos[1].puntos) & (manos[3].puntos > manos[0].puntos) & (manos[3].puntos > manos[2].puntos))
    {
        cout<<"\nGana el jugador 4!!!!"<<endl;
        cout<<"Con la siguienteb mano: "<<endl;cout<<"_______________________"<<endl;
        mostrarMano(manos[3]);
    }
    else
    {
        cout<<"\nEmpate!!!"<<endl;
    }
}

void calcularPuntosMano(tMano& mano)
{// LLamamos a todas las comprobaciones, en orden. De mayor puntuación a menor, asi ahorramos comprobar un Trío cuando ya tenemos un Full.
    comprobarEscaleraReal(mano);
    comprobarEscaleraColor(mano);
    comprobarPoker(mano);
    comprobarFull(mano);
    comprobarColor(mano);
    comprobarEscalera(mano);
    comprobarTrio(mano);
    comprobarPareja(mano);
    comprobarCartaAlta(mano);
}

