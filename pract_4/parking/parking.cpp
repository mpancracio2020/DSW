#include "parking.h"
#include "identificador.h"
#include <iostream>
using namespace std;

Parking :: Parking(const Planta nuevas_plantas[], int numero_plantas)
{// Constructor de la clase parking.

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
{// Este método estaciona un vehiculo, y devuelve 1 si ha sido estacionado o 0 en caso contrario.
    bool aparcado = false;

    plantas[0].estacionar_vehiculo(vehiculo); // Llamamos al método estacionar de la clase planta.

    if(aparcado == true) return 1;

    return aparcado;



}

void Parking::visualizar_estado(void) const
{// Método para visualizar el estado de todas las plantas de un parking.

    cout<<endl;
    for(int i = 0; i < num_plantas; i++)
    {
        cout<<"Planta "<< i<<endl;
        plantas[i].visualizar_estado();
    }
}
bool Parking :: retirar_vehiculo( const char valor_id[] )
{
    bool retirado = false;

    return retirado;
}
