//Author: Marvin Pancracio Manso.
//File: tdttt.cpp .
//This file provides the tdttt functionality.

#ifndef TDTTT_CPP_INCLUDED
#define TDTTT_CPP_INCLUDED
#include "tdttt.h"
#include <iostream>

using namespace std;

int tdtt_times()
{

    int times;

    cout << "Enter the number of times you want to play: ";
    cin >> times;

    return times;
}
t_strategy tdtt_level()
{
    int lvl;
    t_strategy strategy;
    cout << "Enter difficult level: ";
    cin >> lvl;

    strategy = (t_strategy)lvl;
    cout << endl;

    return strategy;
}
void tdtt_start_game(t_strategy strategy,int times)
{
    tdttt_init();
    tdttt_train_agent(strategy);
    tdttt_play_against_human(times);

    return;
}

#endif // TDTTT_CPP_INCLUDED
