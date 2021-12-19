#include "bloque.h"
#include <iostream>
#include <string.h>
using namespace std;

Bloque::Bloque(void)
{// Constructor de la clase.
    ocupado = false; // inicializamos el atributo del objeto.
}
void Bloque :: ocupar_bloque(const char nuevo_valor_id[])
{// Método para ocùpar un bloque.

    if (ocupado == false)
    {// Primero comprobamos que el bloque esté libre, en ese caso, procedemos a ocuparlo y a rellenar la id del bloque.

        //strcpy(valor_id, nuevo_valor_id); // cambiamos el valor por el del nuevo vehiculo que lo ocupa..
        valor_id[0] = nuevo_valor_id[0];
        valor_id[1] = nuevo_valor_id[1];
        valor_id[2] = nuevo_valor_id[2];
        valor_id[3] = nuevo_valor_id[3];
        ocupado = true; // cambiamos el valor del booleano para saber que está siendo ocupado ese bloque.
    }
}

void Bloque :: desocupar_bloque(void)
{// Método para desocupar un bloque.
    char libre[4] = {'X','X','X','X'}; // array para remplazar.
    if(ocupado = true)
    {// Comprobamos si el bloque está ocupado, en caso de estarlo, procedemos a desocuparlo. Cambiando el valor de  los atributos de ocupado y valor_id.

        strcpy(valor_id, libre);// cambiamos el valor de la id del bloque a la que viene por defecto, indicando asi que esta vacio.
        ocupado = false;// cambiamos a false, ya que no está ocupado.
    }
}

void Bloque :: obtener_valor(char valor[]) const
{// Método para copiar el valor del array valor_id del bloque en la array valor.
    for(int i  = 0; i < TAMANO_ID_BLOQUE ;i++)
    {
        valor[i] = valor_id[i];
    }
}

void Bloque::mostrar_valor(void)const
{// Método para mostrar valor_id del objeto bloque.
    for(int i = 0; i < 4; i++)
    {
        cout<<valor_id[i];
    }
}

