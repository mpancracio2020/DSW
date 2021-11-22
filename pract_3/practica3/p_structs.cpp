#include "poker_structs.h"
#include "p_structs.h"
#include "p_struct_mano.h"
#include "p_struct_comprobaciones.h"
#include "p_struct_carta.h"
#include "p_struct_baraja.h"
#include <iostream>
#include <array>

using namespace std;
const unsigned int MAX_CARTAS = 52;

void mostrarMenu()
{
    cout<<"Menú Poker:"<<endl<<"̣-------------"<<endl;
    cout<<"Palos: "<<endl<<"1 equivale a Espadas."<<endl<<"2 equivale a Corazones."<<endl;
    cout<<"3 equivale a Diamantes."<<endl<<"4 equivale a Tréboles."<<endl;
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

int pedirJugadores()
{// Función que pide al usuario cuantos jugadores serán. Esta solo recibe respuestas correctas.
    int n;
    bool correcto = true;
    while(correcto)
    {
        cout<<"_______Bienvenido a POKERFEICH______"<<endl;
        cout<<"Cuantos jugadores serán"<<endl;
        cin>>n;
        if(1 < n & n < 5) correcto = false;
    }

    return n;
}
void jugar(tMano manos[],int num_jug,int election)
{// Esta es la función que llama a todas las demás y ejecuta el juego.
    if(num_jug == 2)
    {
        juegan2(manos,num_jug,election);
    }
    else if(num_jug == 3)
    {
        juegan3(manos,num_jug,election);
    }
    else if (num_jug == 4)
    {
        juegan4(manos,num_jug,election);
    }
    cout<<"\nHasta la próxima !!!"<<endl;
}
void juegan2(tMano manos[],int num_jug,int election)
{// Función que juega cuando hay 2 jugadores. Hemos dividido el trabajo en función del nº de jugadores, así es más simple.
    bool continuar = true;
    while(continuar)
    {
        cout<<"Nueva Partida!"<<endl;
        tBaraja baraja;
        inicializarBaraja(baraja);      // Inicializamos una baraja con la que jugaremos y también las manos de los jugadores.
        tMano mano_jug_1 ; mano_jug_1.puntos=0;
        tMano mano_jug_2 ; mano_jug_2.puntos=0;

        repartirMano(baraja,mano_jug_1);ordenarMano(mano_jug_1);mostrarMano(mano_jug_1);calcularPuntosMano(mano_jug_1);
        cout<<"_____Siguiente mano_____"<<endl;
        repartirMano(baraja,mano_jug_2);ordenarMano(mano_jug_2);mostrarMano(mano_jug_2);calcularPuntosMano(mano_jug_2);
        cout<<"Resultados:"<<endl;

        manos[0] = mano_jug_1; manos[1] = mano_jug_2;
        comprobarGanador(manos,num_jug);// Una vez repartidas las manos, ordenarlas y comprobar su combinación ganadora comprobamos
                                        //quién ha ganado.
        cout<<"Quieres seguir jugando??(1/0)";
        cin>>election;
        if(election == 0) continuar = false;
    }
}
void juegan3(tMano manos[],int num_jug,int election)
{// Esta función es análoga a la anterior aumentando en 1 el nº de jugadores y por ende, las manos.
    bool continuar = true;
    while(continuar)
    {
        cout<<"Nueva Partida!"<<endl;
        tBaraja baraja;
        inicializarBaraja(baraja);

        tMano mano_jug_1 ;mano_jug_1.puntos=0;
        tMano mano_jug_2 ;mano_jug_2.puntos=0;
        tMano mano_jug_3;mano_jug_3.puntos=0;

        repartirMano(baraja,mano_jug_1);ordenarMano(mano_jug_1);mostrarMano(mano_jug_1);calcularPuntosMano(mano_jug_1);
        cout<<"_____Siguiente mano_____"<<endl;
        repartirMano(baraja,mano_jug_2);ordenarMano(mano_jug_2);mostrarMano(mano_jug_2);calcularPuntosMano(mano_jug_2);
        cout<<"_____Siguiente mano_____"<<endl;
        repartirMano(baraja,mano_jug_3);ordenarMano(mano_jug_3);mostrarMano(mano_jug_3);calcularPuntosMano(mano_jug_3);
        cout<<"Resultados:"<<endl;

        manos[0] = mano_jug_1;manos[1] = mano_jug_2;manos[2] = mano_jug_3;
        comprobarGanador(manos,num_jug);

        cout<<"Quieres seguir jugando??(1/0)";
        cin>>election;
        if(election == 0) continuar = false;
    }
}
void juegan4(tMano manos[],int num_jug,int election)
{// Lo mismo aqui, ahora con 4 jugadores.
    bool continuar = true;
    while(continuar)
    {
        cout<<"Nueva Partida!"<<endl;
        tBaraja baraja;
        inicializarBaraja(baraja);
        tMano mano_jug_1 ;mano_jug_1.puntos=0;
        tMano mano_jug_2 ;mano_jug_2.puntos=0;
        tMano mano_jug_3;mano_jug_3.puntos=0;
        tMano mano_jug_4;mano_jug_4.puntos=0;

        repartirMano(baraja,mano_jug_1);ordenarMano(mano_jug_1);mostrarMano(mano_jug_1);calcularPuntosMano(mano_jug_1);
        cout<<"_____Siguiente mano_____"<<endl;
        repartirMano(baraja,mano_jug_2);ordenarMano(mano_jug_2);mostrarMano(mano_jug_2);calcularPuntosMano(mano_jug_2);
        cout<<"_____Siguiente mano_____"<<endl;
        repartirMano(baraja,mano_jug_3);ordenarMano(mano_jug_3);mostrarMano(mano_jug_3);calcularPuntosMano(mano_jug_3);
        cout<<"_____Siguiente mano_____"<<endl;
        repartirMano(baraja,mano_jug_4);ordenarMano(mano_jug_4);mostrarMano(mano_jug_4);calcularPuntosMano(mano_jug_4);
        cout<<"Resultados:"<<endl;

        manos[0] = mano_jug_1;manos[1] = mano_jug_2;manos[2] = mano_jug_3;manos[3] = mano_jug_4;
        comprobarGanador(manos,num_jug);

        cout<<"Quieres seguir jugando??(1/0)";
        cin>>election;
        if(election == 0) continuar = false;
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
    cout<<"puntos primer jugador: "<<manos[0].puntos<<endl;
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
        //cout<<endl;
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


