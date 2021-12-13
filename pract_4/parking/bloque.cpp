#include "bloque.h"
#include <iostream>
#include <string.h>
using namespace std;


Bloque :: Bloque(void)
{
    ocupado = false; // inicializamos el atributo del objeto.
}
void Bloque :: ocupar_bloque(const char nuevo_valor_id[])
{// Método para ocùpar un bloque.

    if (ocupado == false)
    {// Primero comprobamos que el bloque esté libre, en ese caso, procedemos a ocuparlo y a rellenar la id del bloque.

        strcpy(valor_id, nuevo_valor_id); // cambiamos el valor por el del nuevo vehiculo que lo ocupa..
        ocupado = true; // cambiamos el valor del booleano para saber que está siendo ocupado ese bloque.
    }
}

/*bool Bloque :: buscar_sitio(Identificador ident, Planta planta)
{
    int espacio = ident.tam_bloques;
    int entra = 0;
    bool hay_sitio = false

    for(int i = 0; i < ident.VALOR_MAX;i++)
    {
        for(int j = 0;) j < ident.VALOR_MAX;j++)
        {
            if(entra == espacio) {hay_espacio = true;}
            else if (planta.bloques[i][j].ocupado ==false){ entra ++;}
        }
    }

    return hay_sitio;

}
*/
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
    cout <<valor_id;
}
