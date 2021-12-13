#include "planta.h"
#include <iostream>
#include "array"
#include "bloque.h"
#include "identificador.h"

using namespace std;

Planta :: Planta(const int num_filas, const int num_columnas)
{
   filas = num_filas;
   columnas = num_columnas;
   bloques_libres = num_filas*num_columnas;

}
Planta :: Planta(void)
{

    filas = MAX_FILAS;
    columnas = MAX_COLUMNAS;
}

int Planta :: num_bloques_libres(void) const
{
    return bloques_libres;
}
/*bool Planta :: estacionar_vehiculo()
{
}*/

void Planta::visualizar_estado(void) const
{// Método para visualizar el estado de cada planta.

    cout << endl;

    /*for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            bloques[i][j].mostrar_valor(); // Llamamos al método mostrar_valor para que nos muestre valor_id del bloque, ya que
                                           // es un atributo privado.
            cout<< " ";
        }
        cout<<endl;
    }*/
    bloques[0][0].mostrar_valor();
}
bool Planta :: estacionar_vehiculo( tVehiculo vehiculo )
{// En este método estacionamos un vehiculo en su posible hueco. Traducido en código vamos a buscar un espacio acorde al nº de
 // bloques necesario para el vehiculo y almacenar su id en la array bloques de cierta planta que tenga espacio necesario.

    Identificador id; // Creamos un objeto e inicializamos sus atributos.
    id.setup();

    id.preparar_valor(vehiculo); // Conseguimos su correspondiente id.
    id.generar_valor();

    char arr[4] = {'A','A','A','A'};

    bloques[0][0].ocupar_bloque(id.arr_id);

}
bool Planta :: retirar_vehiculo(const char valor_id[] )
{
    bool retirado = false;

    bloques[0][0].desocupar_bloque();

    return retirado;
}
