#ifndef P_STRUCT_COMPROBACIONES_H_INCLUDED
#define P_STRUCT_COMPROBACIONES_H_INCLUDED

bool comprobarMismoPalo(tMano& mano);
void comprobarEscaleraReal(tMano& mano);
void comprobarEscaleraColor(tMano& mano);
void comprobarPoker(tMano& mano);
void comprobarFull(tMano& mano);
void comprobarColor(tMano& mano);
void comprobarEscalera(tMano& mano);
void comprobarTrio(tMano& mano);
void comprobarDoblePareja(tMano& mano);
void comprobarPareja(tMano& mano);
void comprobarCartaAlta(tMano& mano);
void comprobarGanador(tMano manos[],int num_jug);

#endif // P_STRUCT_COMPROBACIONES_H_INCLUDED
