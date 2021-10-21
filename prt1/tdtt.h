//Author: Marvin Pancracio Manso.
//File: tdtt.h .
//This file contains prototype info for tdttt program.

//Funtion: init tdtt_times();
//This function ask users the times they want to play.

//Function: tdtt_level();
//This function ask users the level they want to play against themselves.

//Function: tdtt_start_game();
//This function gets the times and level that users want and start the game.


#ifndef TDTT_H_INCLUDED
#define TDTT_H_INCLUDED

int tdtt_times();
t_strategy tdtt_level();
void tdtt_start_game(t_strategy strategy, int time);

#endif // TDTT_H_INCLUDED
