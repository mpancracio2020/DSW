
#include "poker_structs.h"
#include "p_structs.h"
#include <iostream>

using namespace std;

void mostrarCarta(tCarta carta)
{
    string palo = mostrarPalo(carta);
    cout<< "Tu carta es el: "<<carta.palo<< " de "<<palo<<endl;
}

string mostrarPalo(tCarta carta)
{
    string palo;

    if(carta.palo == 1) palo = "Espadas";
    else if(carta.palo == 2) palo = "Corazones";
    else if(carta.palo == 3) palo = "Diamantes";
    else if(carta.palo == 4) palo = "Tréboles";

    cout<<"Palo string: "<<palo<<endl;


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

    int num_palo = rand()% (4) +1;
    int num_valor = rand()% (13) +1;

    carta.valor = rand()% (13) +1;
    carta.palo = rand()% (4) +1;
    cout<<"Palo num: "<<carta.palo<<endl;
    cout<<"Valor num: "<<carta.valor<<endl;



}
