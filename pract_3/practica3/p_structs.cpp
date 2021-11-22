#include "poker_structs.h"
#include "p_structs.h"
#include "p_struct_mano.h"
#include "p_struct_comprobaciones.h"
#include "p_struct_carta.h"
#include "p_struct_baraja.h"
#include "p_struct_juego.h"
#include <iostream>
#include <array>

// Este fichero implementa la funcionalidad del módulo structs, el cual está encargado de mostrar o pedir información al usuario.

using namespace std;
const unsigned int MAX_CARTAS = 52;

void mostrarMenu()
{
    cout<<"Menú Poker:"<<endl<<"̣-------------"<<endl;
    cout<<"Palos: "<<endl<<"1 equivale a Espadas."<<endl<<"2 equivale a Corazones."<<endl;
    cout<<"3 equivale a Diamantes."<<endl<<"4 equivale a Tréboles."<<endl;
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

