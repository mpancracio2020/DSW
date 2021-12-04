#include "parking.h"
#include "identificador.h"
#include <iostream>
using namespace std;

Parking :: Parking(const Planta nuevas_plantas[], int numero_plantas)
{
    num_plantas = numero_plantas;

    for(int i = 0; i < numero_plantas; i++)
    {
        plantas[i] = nuevas_plantas[i];
    }
}

int Parking :: num_bloques_libres(void) const
{// Este método llama al método bloques_libres de cada plantab que tenga el parking, los suma en una variable auxiliar y devuelve la variable.

    int n = 0; // variable auxiliar.

    for(int i = 0; i < num_plantas; i++)
    {
        n += plantas[i].num_bloques_libres();
    }
    return n;
}

bool Parking ::estacionar_vehiculo( const tVehiculo vehiculo )
{
    char id_valor[4];
    bool estacionado = false;

    Identificador id;
    id.setup();
    /*id.contador = id.VALOR_MIN;
    id.digitos_ident = id.contador;*/

    id.preparar_valor(vehiculo);
    id.generar_valor(id_valor);

    /*for(int i = 0; i < 4; i++)
    {
        cout << id_valor[i] << endl;

    }*/
//    id.contador ++;
    return estacionado;
}

