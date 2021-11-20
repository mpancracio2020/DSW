
#include "poker_structs.h"
#include "p_structs.h"
#include <iostream>
#include <array>

using namespace std;
const unsigned int MAX_CARTAS = 52;
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
        //cout<<"Carta número: "<< i<<endl;
        //cout<<"palo de la mano: "<< mano.carta[i].palo <<endl;
        //cout<<"valor de la mano: "<< mano.carta[i].valor <<endl;
        mano.numero++;
    }
    //ordenarMano(mano);
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
    for(int i = 1; i < 6 ;i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(mano.carta[j+1].valor < mano.carta[j].valor)
            {   //Fácil, si el valor de carta[i] es menor que el de cart[j] se intercambian las posiciones.
                carta_aux = mano.carta[j];
                mano.carta[j] = mano.carta[j+1];
                mano.carta[j+1] = carta_aux;
            }
        }
    }
    //mostrarMano(mano);
}
void mostrarMano(tMano& mano)
{
    for(int i = 0; i < 5; i++)
    {
        cout<<"______________"<<endl;
        cout<<"|Carta número: "<< i+1 <<"|"<<endl;
        cout<<"|palo: "<< mano.carta[i].palo <<"|"<<endl;
        cout<<"|valor: "<< mano.carta[i].valor <<"|"<<endl;
        cout<<"|_____________|"<<endl;
    }
}

bool comprobarMismoPalo(tMano& mano)
{
    bool mismo_palo = true; // Variable para comprobar que son del mismo palo.
    int indice = 0;

    for(int j = 1; j < 6; j++)
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
        for(int i = 5; i > 0; i--)
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
        //cout<<"No tienes Escalera Real :("<<endl;
    }
}
void comprobarEscaleraColor(tMano& mano)
{
    bool mismo_palo = comprobarMismoPalo(mano);
    bool escalera_color = true;

    if(mismo_palo == true)
    {
        for(int i = 0; i < 5; i++)
        {
            if((mano.carta[i].valor > mano.carta[i+1].valor)&((mano.carta[i+1].valor - mano.carta[i].valor) == 1)) escalera_color = false;
            //cout<<"valor_escalera: "<<valor_escalera<<endl;
        }
        if(escalera_color = true)
        {
            mano.puntos = 9; cout << "Tienes Escalera de color :)"<<endl;
        }

        else
        {
            //cout << "No tienes Escalera de color :("<<endl;
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
       if(mano.carta[i].valor == mano.carta[i+1].valor) contador_poker++;
    }
    if(contador_poker == 3)
    {
        cout<< "Tienes poker de locos"<<endl;
        mano.puntos = 8;
    }

    else
    {
        //cout<< "No tienes poker de locos"<<endl;
    }

}
void comprobarFull(tMano& mano)
{
    comprobarTrio(mano);
    int contador_full = 0;
    if(mano.puntos == 4)
    {
        comprobarPareja(mano);
    }
    if(mano.puntos == 2)
    {
        cout<<"Tienes Full!"<<endl;
        mano.puntos = 7;
    }
}
void comprobarColor(tMano& mano)
{
    bool color = comprobarMismoPalo(mano);
    if(color == true)
    {
        cout<<"Tienes color :)"<<endl;
        mano.puntos = 6;
    }
}
void comprobarEscalera(tMano& mano)
{
    int contador_escalera = 0;
    for(int i = 0; i < 4; i++)
    {
        if((mano.carta[i].valor < mano.carta[i+1].valor) & ((mano.carta[i+1].valor - mano.carta[i].valor) == 1)) contador_escalera++;
    }
    if(contador_escalera == 4)
    {
        mano.puntos = 5; cout << "Tienes Escalera :)"<<endl;
    }
    else
    {
        //cout << "No tienes Escalera :("<<endl;
    }
}
void comprobarTrio(tMano& mano)
{
    int contador_trio = 0;
    if(mano.puntos == 0)
    {
       for(int i = 0; i < 3; i++)
       {
            int a = mano.carta[i].valor;
            int b = mano.carta[i+1].valor;
            int c = mano.carta[i+2].valor;
            if((a == b)& (a == c) & ( b - a == 0)) contador_trio++;

        }
        if(contador_trio == 1)
        {
            mano.puntos = 4;
            cout << "Tienes Trio :)"<<endl;
        }
    }

}
void comprobarPareja(tMano& mano)
{
    int contador_pareja = 0;
    if(mano.puntos == 0) // Puede darse el caso de que tengamos trío en lugar de pareja, para evitar errores de calculo de puntuación
                         // antes de comprobar que tengamos pareja veamos si ya tenemos trío, en esa situación tener una pareja
                         // con los mismos números es posible, pero de nada sirve calcularlo, pues trío > pareja.
    {
        for(int i = 0; i < 5; i++)
        {
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
    else
    {
        //cout << "No tienes Pareja :("<<endl;
    }
}
void comprobarCartaAlta(tMano& mano)
{
    bool mismo_palo = comprobarMismoPalo(mano);
    if(mano.puntos == 0)
    {
        cout<<"Carta alta :)"<<endl;
        mano.puntos =1;
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
void inicializarManos(tMano manos[])
{// Funciónn que inicializa una array de manos, mediante un bucle.
    tMano mano;
    for(int i = 0; i < 4; i++)
    {
        manos[i] = mano;
    }
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

