#include "bloque.h"

#include <iostream>


Bloque :: Bloque()
{
    ocupado = false;

}


void Bloque :: ocupar_bloque(const char nuevo_valor_id[])
{// Método para ocùpar un bloque.

    if (ocupado == false)
    {// Primero comprobamos que el bloque esté libre, en ese caso, procedemos a ocuparlo y a rellenar la id del bloque.
        for(int i  = 0; i < TAMANO_ID_BLOQUE ;i++)
        {
            valor_id[i] = nuevo_valor_id[i];
        }
        ocupado = true;
    }

}

void Bloque :: desocupar_bloque(void)
{// Método para desocupar un bloque.
    if(ocupado = true)
    {// Comprobamos si el bloque está ocupado, en caso de estarlo, procedemos a desocuparlo. Cambiando el valor de  los atributos de ocupado y valor_id.
        /*for(int i  = 0; i < TAMANO_ID_BLOQUE ; i++)
        {
            valor_id[i] = "X";
        }*/
        ocupado = false;
    }
}

void Bloque :: obtener_valor(char valor[]) const
{// Método para copiar el valor del array valor_id del bloque en la array valor.
    for(int i  = 0; i < TAMANO_ID_BLOQUE ;i++)
    {
        valor[i] = valor_id[i];
    }

}


