#include "identificador.h"
#include <iostream>
using namespace std;

int Identificador::contador;

void Identificador::preparar_valor(tVehiculo vehiculo)
{// Método para determinar el tipo de letra según el tipo de vehículo.
    switch (vehiculo)
    {
        case AUTOBUS:
            tipo_vehic_ident = 'A';
            tam_bloques = 4;
            break;
        case TURISMO:
            tipo_vehic_ident = 'T';
            tam_bloques = 2;
            break;
        case FURGONETA:
            tipo_vehic_ident = 'F';
            tam_bloques = 3;
            break;
        case MOTOCICLETA:
            tipo_vehic_ident = 'M';
            tam_bloques = 1;
            break;
    }

    digitos_ident = contador++;

    if (contador > VALOR_MAX)
        contador = VALOR_MIN;

    arr_id[0] = tipo_vehic_ident;

}


void Identificador::generar_valor()
{// Método para generar el valor id de un vehículo.
    int numero = digitos_ident;

    for (int i=1; i<=NUM_CIFRAS_IDENT - 1; i++)
    {
        arr_id[NUM_CIFRAS_IDENT - i] = (numero % 10) + '0';
        numero /= 10;
    }

}
void Identificador :: setup()
{
    contador = VALOR_MIN;
    digitos_ident = contador;

}
void Identificador::mostrar_id()
{// Método para mostrar el id de un vehículo.
    //cout<< tipo_vehic_ident<<endl;
    for(int i = 0; i < 4; i++)
    {
        cout<<arr_id[i];
    }
    cout<<endl;

    //cout<<<<endl;
}
