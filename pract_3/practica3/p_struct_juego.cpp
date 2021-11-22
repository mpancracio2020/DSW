#include "poker_structs.h"
#include "p_struct_mano.h"
#include "p_structs.h"
#include "p_struct_comprobaciones.h"
#include "p_struct_carta.h"
#include "p_struct_baraja.h"
#include "p_struct_juego.h"
#include <iostream>
#include <array>

//Este fichero implementa toda la funcionalidad del módulo juego.

void jugar(tMano manos[],int num_jug,int election)
{// Esta es la función que llama a todas las demás y ejecuta el juego.
    mostrarMenu();// Mostramos el menú del juego al usuario.
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
