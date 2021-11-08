
#include "poker_structs.h"
#include "p_structs.h"
#include <iostream>
#include <array>

using namespace std;

const unsigned int MAX_CARTAS = 52;

tBaraja* inicializarBaraja()
{
    tBaraja* baraja = new tBaraja;
    (*baraja).numero = 0;
    for (int i = 1;i < 4;i++)
    {
        for (int j = 0; j < 52;j++)
        {
            (*baraja).numero++;
            (*baraja).carta[(*baraja).numero].palo = i;

            (*baraja).carta[(*baraja).numero].valor = j;
        }
    }
    return baraja;
}

void mostrarBaraja(tBaraja* baraja,int valor, int palo)
{
    //Método para mostrar una carta de la baraja.

    tCarta carta = (*baraja).carta[VALORES*palo + valor];

    mostrarCarta(carta);

}

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

void setCarta(tBaraja baraja,tCarta carta)
{
    //Primero comprobamos que la carta no está repartida ya, si aún está sin repartir, entonces la usamos y la guardamos en la array,
    //dejando así constancia de que ya está en uso.


}

/*bool getCarta(tBaraja baraja,tCarta carta)
{
    //En este método comprobamos si la carta ya está repartida (true) o aún sigue en la baraja (false).
    bool get = false;

    if(carta.valor == bajara.carta[carta.valor].valor)
    {
        get = true;
    }

    return get;
}*/
