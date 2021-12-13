#ifndef IDENTIFICADOR_H_INCLUDED
#define IDENTIFICADOR_H_INCLUDED

#include "tvehiculo.h"
#include "parking.h"
#include "planta.h"
#include "bloque.h"


class Identificador
{
  public:

    void preparar_valor(const tVehiculo vehiculo);// Método para determinar el tipo de letra según el tipo de vehículo.
    void generar_valor() ;
    static void resetear_contador() { contador = VALOR_MIN; }
    void setup();
    void mostrar_id();
    char arr_id[4]; // array para almacenar el valor de la id.
    int tam_bloques;

  private:

    char tipo_vehic_ident;
    int digitos_ident;
    static int contador;


    static const int VALOR_MIN = 100;
    static const int VALOR_MAX = 999;
    static const int NUM_CIFRAS_IDENT = 4;

};

#endif // IDENTIFICADOR_H_INCLUDED
