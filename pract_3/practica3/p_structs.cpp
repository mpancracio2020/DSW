
#include "poker_structs.h"
#include "p_structs.h"
#include <iostream>
#include <array>

using namespace std;

const unsigned int MAX_CARTAS = 52;

/*tBaraja* inicializarBaraja()
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
}*/
void inicializarBaraja(tBaraja& baraja)
{   //Función para inicializar los valores de una baraja.
    baraja.numero = 0;
    for (int i = 1;i < 5;i++)
    {
        for (int j = 1; j < 14;j++)
        {
            baraja.carta[baraja.numero].palo = i;
            baraja.carta[baraja.numero].valor = j;
            baraja.numero++;
        }
    }

}
void mostrarBaraja(tBaraja& baraja)
{   //Función para mostrar las cartas que contiene la baraja.
    int index = 0;
    for (int i = 1;i < 5;i++)
    {
        for (int j = 1; j < 14;j++)
        {
            cout<< "palo: "<<baraja.carta[index].palo<<endl;
            cout << " valor:" << baraja.carta[index].valor<<endl;
            index++;
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
void repartirMano(tBaraja& baraja,tMano& mano)
{   //Función para repartir una mano de cartas a cada jugador, teniendo en cuenta las cartas ya dadas.

    mano.numero = 0; //Inicializamos el atributo número del objeto carta, el cuál irá aumentando
    //a la vez que el número de cartas introducidas en la mano.

    for(int i = 0; i < 5;i++)
    {
        sacarCarta(baraja,mano.carta[i]);
        //cout<<"Carta número: "<< i <<endl;
        //cout<<"palo de la mano: "<< mano.carta[i].palo <<endl;
        //cout<<"valor de la mano: "<< mano.carta[i].valor <<endl;
        mano.numero++;
    }
    ordenarMano(mano);
}

void sacarCarta(tBaraja& baraja,tCarta& carta)
{   // Función para sacar una carta al azar de la baraja y retirarla de la misma.
    // Para marcar que una carta ha sido retirada marcaremos su palo como 0, de esta forma
    // miraremos si el valor numérico del palo es menor que 1, en tal caso, la carta ya estará repartida
    bool repartida = true;
    int numCarta;
    while (repartida)
    {
        srand(time(NULL));
        numCarta = rand()% (52) +0;
        if(baraja.carta[numCarta].palo != 0) repartida = false;
    }
    carta.palo = baraja.carta[numCarta].palo;
    carta.valor = baraja.carta[numCarta].valor;
    baraja.carta[numCarta].palo = 0;
}

void mostrarCarta(tCarta& carta)
{
    cout<<"Palo: "<<carta.palo<<endl;
    cout<<"Valor: "<<carta.valor<<endl;
}

void ordenarMano(tMano& mano)
{
    tCarta carta_aux; // carta auxiliar para poder mover las cartas de posición (método de la burbuja).
    for(int i = 0; i < 6;i++)
    {
        for(int j = 1; j < 5; j++)
        {
            if(mano.carta[i].valor < mano.carta[j].valor)
            {   //Fácil, si el valor de carta[i] es menor que el de cart[j] se intercambian las posiciones.
                carta_aux = mano.carta[i];
                mano.carta[i] = mano.carta[j];
                mano.carta[j] = carta_aux;
            }
        }
    }
    mostrarMano(mano);
}
void mostrarMano(tMano& mano)
{
    for(int i = 0; i < 5; i++)
    {
        cout<<"Carta número: "<< i <<endl;
        cout<<"palo de la mano: "<< mano.carta[i].palo <<endl;
        cout<<"valor de la mano: "<< mano.carta[i].valor <<endl;
        cout<< endl;
    }
}

bool comprobarMismoPalo(tMano& mano)
{
    bool mismo_palo = true; // Variable para comprobar que son del mismo palo.
    int indice = 0;

    for(int j = 1; j < 5; j++)
    {
        if(mano.carta[indice].palo != mano.carta[j].palo) mismo_palo = false;
    }
    return mismo_palo;
}
void comprobarEscaleraReal(tMano& mano)
{
    int valor_escalera = 13;
    int valor_min = 9;

    bool mismo_palo = comprobarMismoPalo(mano);

    if(mismo_palo == true)
    {
        for(int i = 4; i > 0; i--)
        {
            if(mano.carta[i].valor == valor_escalera) valor_escalera--;
            //cout<<"valor_escalera: "<<valor_escalera<<endl;
        }
    }
    if((valor_escalera == valor_min) && (mano.carta[0].valor == 1 ))
    {
        mano.puntos = 10; cout<<"Tienes Escalera Real :)"<<endl;
    }
    else
    {
        cout<<"No tienes Escalera Real :("<<endl;
    }
}
void comprobarEscaleraColor(tMano& mano)
{
    bool mismo_palo = comprobarMismoPalo(mano);
    bool escalera_color = true;

    if(mismo_palo == true)
    {
        for(int i = 0; i < 4; i++)
        {
            if(mano.carta[i].valor > mano.carta[i+1].valor) escalera_color = false;
            //cout<<"valor_escalera: "<<valor_escalera<<endl;
        }

        if(escalera_color = true)
        {
            mano.puntos = 9; cout << "Tienes Escalera de color :)"<<endl;
        }

        else
        {
            cout << "No tienes Escalera de color :("<<endl;
        }
    }

}
void comprobarPoker(tMano& mano)
{
    bool poker = true;
    int contador_poker = 0;
    int VALOR_Q = 12;
    for(int i = 0; i < 5; i++)
    {
        if(mano.carta[i].valor != VALOR_Q) contador_poker++;
        //cout<<"valor_escalera: "<<valor_escalera<<endl;
    }
    if(contador_poker != 4)
    {
        poker = false; cout<< "Tienes poker de locos"<<endl;
        mano.puntos = 8;
    }

    else
    {
        cout<< "No tienes poker de locos"<<endl;
    }

}
void comprobarFull(tMano& mano)
{


}
void comprobarColor(tMano& mano);
void comprobarEscalera(tMano& mano)
{
    bool escalera = true;

    for(int i = 0; i < 4; i++)
    {
        if(mano.carta[i].valor > mano.carta[i+1].valor) escalera = false;
        //cout<<"valor_escalera: "<<valor_escalera<<endl;
    }

    if(escalera = true)
    {
        mano.puntos = 5; cout << "Tienes Escalera :)"<<endl;
    }

    else
    {
        cout << "No tienes Escalera :("<<endl;
    }



}
void comprobarTrio(tMano& mano)
{



}

void comprobarDoblePareja(tMano& mano);
void comprobarPareja(tMano& mano);
void comprobarCartaAlta(tMano& mano);
void calcularPuntosMano(tMano& mano)
{
    comprobarEscaleraReal(mano);
    comprobarEscaleraColor(mano);
    comprobarPoker(mano);
    comprobarEscalera(mano);

    /*comprobarFull(mano);
    comprobarColor(mano);

    comprobarTrio(mano);
    comprobarDoblePareja(mano);
    comprobarPareja(mano);
    comprobarCartaAlta(mano);*/
}

