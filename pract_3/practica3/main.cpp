#include <iostream>
#include "poker_structs.h"
#include "p_structs.h"

using namespace std;

int main()
{
    /*mostrarMenu();
    tCarta carta;
    tCarta cartaRandom;
    repartirCarta(cartaRandom);
    cout<<"Introduce el valor de tu carta: ";
    cin>> carta.valor;
    cout<<"Introduce el palo de tu carta: ";
    cin>> carta.palo;
    cout<<"Tu carta: ";
    mostrarCarta(carta);
    cout<<endl<<"La mia: ";
    mostrarCarta(cartaRandom);*/
    tCarta cartaRandom;
    //cartaRandom.valor = rand()% (13) +1;
    //cartaRandom.palo = rand()% (4) +1;

    repartirCarta(cartaRandom);
    mostrarCarta(cartaRandom);
    mostrarPalo(cartaRandom);
    return 0;
}
