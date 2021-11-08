
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
    for (int i = 1;i < 5;i++)
    {
        for (int j = 1; j < 13;j++)
        {
            (*baraja).numero++;
            (*baraja).carta[(*baraja).numero].palo = i;

            (*baraja).carta[(*baraja).numero].valor = j;
            //cout<< "palo: "<<(*baraja).carta[(*baraja).numero].palo;
            //cout << " valor:" << (*baraja).carta[(*baraja).numero].valor<<endl;
        }
    }
    return baraja;
}

void mostrarBaraja(tBaraja &baraja)
{
    int numero = 0;
    for (int i = 1;i < 5;i++)
    {
        for (int j = 1; j < 13;j++)
        {
            numero++;
            cout<< "palo: "<<baraja.carta[baraja.numero].palo;
            cout << " valor:" << baraja.carta[baraja.numero].valor<<endl;
        }
    }
}
int getPalo(int pos)
{
    int a = 0;
    return a;
}

string mostrarPalo(int indice)
{
    string palo;
    int pos_palo = indice%10;

    if(pos_palo== 1) palo = "Espadas";
    else if(pos_palo == 2) palo = "Corazones";
    else if(pos_palo == 3) palo = "Diamantes";
    else if(pos_palo == 4) palo = "Tréboles";

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
void sacarCarta()
{



}

