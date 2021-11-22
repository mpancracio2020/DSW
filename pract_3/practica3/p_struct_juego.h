#ifndef P_STRUCT_JUEGO_H_INCLUDED
#define P_STRUCT_JUEGO_H_INCLUDED
//Este fichero contiene la información relacionada a los métodos del módulo juego.

void jugar(tMano manos[],int num_jug,int election);// Función que contiene el resto de funciones y llamadas a otras.
void juegan2(tMano manos[],int num_jug,int election);//Función que se realiza cuando juegan 2 personas.
void juegan3(tMano manos[],int num_jug,int election); //Función para jugar con 3 jugadores.
void juegan4(tMano manos[],int num_jug,int election);// Funcion para jugar con 4 jugadores.



#endif // P_STRUCT_JUEGO_H_INCLUDED
