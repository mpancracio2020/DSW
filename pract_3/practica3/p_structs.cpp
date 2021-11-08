
#include "poker_structs.h"
#include "p_structs.h"
#include <iostream>
#include <array>

using namespace std;

void mostrarCarta(tCarta carta)
{
    string palo = mostrarPalo(carta);
    cout<< "Tu carta es el: "<<carta.valor<< " de "<<palo<<endl;
}

string mostrarPalo(tCarta carta)
{
    string palo;

    if(carta.palo == 1) palo = "Espadas";
    else if(carta.palo == 2) palo = "Corazones";
    else if(carta.palo == 3) palo = "Diamantes";
    else if(carta.palo == 4) palo = "Tréboles";

    return palo;
}
void mostrarMenu()
{
    cout<<"Menú Poker:"<<endl<<"̣-------------"<<endl;
    cout<<"Palos: "<<endl<<"1 equivale a Espadas."<<endl<<"2 equivale a Corazones."<<endl;
    cout<<"3 equivale a Diamantes."<<endl<<"4 equivale a Tréboles."<<endl;
}
void repartirCarta(tCarta &carta)
{
    srand(time(NULL));

    carta.valor = rand()% (13) +1;
    carta.palo = rand()% (4) +1;
    cout<<"Palo num: "<<carta.palo<<endl;
    cout<<"Valor num: "<<carta.valor<<endl;
}

void setCarta(int listaCartas[4][52],int listV[],tCarta carta)
{
    //Primero comprobamos que la carta no está repartida ya, si aún está sin repartir, entonces la usamos y la guardamos en la array,
    //dejando así constancia de que ya está en uso

    bool get = getCarta(listaCartas,carta);
    if(get == false)
    {

    listaCartas[carta.palo][carta.valor] = carta.valor;
    cout<<"Carta repartida y guardada."<<endl;
    }

    else
    {
        cout<< "Ya está repartida."<<endl;
    }
}

bool getCarta(int listaCartas[4][52],tCarta carta)
{
    // El método es simple. Tenemos una array 4x52, o lo que es igual PaloxValor. Es decir, el 4 de corazones se aloja en la fila 2 columna 4, con valor 4 (valor). Des esta forma
    // ,podemos saber si un valor de un palo ha sido tomado con tan solo un condicional.

    bool get = false;
    int palo = carta.palo;
    int valor = carta.valor;

    if(listaCartas[palo][valor] == valor)
    {
    //mostrarCarta(carta);
    //cout<<"ya existe." << endl;
    get = true;
    }

    return get;
}
