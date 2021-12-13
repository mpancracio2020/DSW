#ifndef BLOQUE_H_INCLUDED
#define BLOQUE_H_INCLUDED
#include "identificador.h"
#include "planta.h"

class Bloque
{
  public:

    Bloque(void); // constructor
    void ocupar_bloque(const char nuevo_valor_id[]); // Método para ocupar un bloque.
    void desocupar_bloque(void);
    void obtener_valor(char valor[]) const;
    bool esta_ocupado(void) const {return ocupado;}
    void mostrar_valor(void)const;
//    bool buscar_sitio(Identificador ident, Planta planta);

  private:

    static const int TAMANO_ID_BLOQUE = 4;
    char valor_id[TAMANO_ID_BLOQUE] = {'X','X','X','X'}; // Inicializamos valor_id.
    bool ocupado;

};



#endif // BLOQUE_H_INCLUDED
