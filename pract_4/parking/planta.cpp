#include "planta.h"


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
