#ifndef IDENTIFICADOR_H_INCLUDED
#define IDENTIFICADOR_H_INCLUDED

#include "tvehiculo.h"
#include "parking.h"
#include "planta.h"
#include "bloque.h"


class Identificador
{
  public:

    void preparar_valor(const tVehiculo vehiculo);
    void generar_valor(char valor[]) const;
    static void resetear_contador() { contador = VALOR_MIN; }

  private:

    char tipo_vehic_ident;
    int digitos_ident;
    static int contador;

    static const int VALOR_MIN = 100;
    static const int VALOR_MAX = 999;
    static const int NUM_CIFRAS_IDENT = 4;

};

#endif // IDENTIFICADOR_H_INCLUDED
