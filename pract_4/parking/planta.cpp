#include "planta.h"
#include <iostream>
#include "array"
#include "bloque.h"
#include "identificador.h"

using namespace std;

Planta :: Planta(const int num_filas, const int num_columnas)
{// Constructor de la clase.
   filas = num_filas;
   columnas = num_columnas;
   bloques_libres = num_filas*num_columnas;

}
Planta :: Planta(void)
{// Constructor de la clase.

    filas = MAX_FILAS;
    columnas = MAX_COLUMNAS;
}

int Planta :: num_bloques_libres(void) const
{
    return bloques_libres;
}
void Planta::visualizar_estado(void) const
{// Método para visualizar el estado de cada planta.

    cout << endl;

    for(int i = (filas-1); i >= 0; i--)
    {
        for(int j = 0 ; j < columnas; j++)
        {
            bloques[i][j].mostrar_valor(); // Llamamos al método mostrar_valor para que nos muestre valor_id del bloque, ya que
                                           // es un atributo privado.
            cout<< " ";
        }
        cout<<endl;
    }
}
bool Planta :: estacionar_vehiculo( tVehiculo vehiculo )
{// En este método estacionamos un vehiculo en su posible hueco. Traducido en código vamos a buscar un espacio acorde al nº de
 // bloques necesario para el vehiculo y almacenar su id en la array bloques de cierta planta que tenga espacio necesario.

    Identificador id; // Creamos un objeto e inicializamos sus atributos.
    id.preparar_valor(vehiculo); // Conseguimos su correspondiente id.
    id.generar_valor();
    bool aparcado = 0;
    int sentinel = 0;
    bool sigue = true;
    for(int i = 0; i < filas;i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            if(sentinel == id.tam_bloques)
            {// Condicional para no sobre escribir la id de un vehículo.
                sigue = false;
                aparcado = 1;
            }
            if( (sigue == true)&(bloques[i][j].esta_ocupado() == false) )
            {// Si se cumplen las condiciones se estaciona.
                bloques[i][j].ocupar_bloque(id.arr_id);
                sentinel++;
            }
        }
    }
    if(aparcado == 1){ bloques_libres = bloques_libres - id.tam_bloques;}
    return aparcado;
}

int Planta::get_num_columnas(tVehiculo vehiculo)
{
    int col;

    switch (vehiculo)
    {
        case AUTOBUS:
            col = 4;
            break;
        case TURISMO:
            col= 2;
            break;
        case FURGONETA:
            col = 3;
            break;
        case MOTOCICLETA:
            col = 1;
            break;
    }
    return col;
}

bool Planta :: retirar_vehiculo(const char valor_id[] )
{
    bool retirado = false;
    int sentinel = 0;
    bool sigue = false;

    /*for(int i = 0; i < filas;i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            if(sentinel == id.tam_bloques)
            {// Condicional para no sobre escribir la id de un vehículo.
                sigue = true;
                aparcado = 1;
            }
            if( (sigue == false)&(bloques[i][j].esta_ocupado() == true)&(bloques[i][j].valor_id == valor_id) )
            {// Si se cumplen las condiciones se estaciona.
                //id.preparar_valor(vehiculo); // Conseguimos su correspondiente id.
                //id.generar_valor();
                bloques[i][j].desocupar_bloque();
                sentinel++;
            }
        }
    }
    if(retirado == 1){ bloques_libres = bloques_libres + id.tam_bloques;}
    */

    return retirado;
}
