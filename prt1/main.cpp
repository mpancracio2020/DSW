//Author: Marvin Pancracio Manso.
//File: main.cpp .
//This file drive the tdttt function.

#include <iostream>
#include "tdttt.h"
#include "tdtt.h"


using namespace std;

int main()
{
    int t = tdtt_times();
    t_strategy s = tdtt_level();
    tdtt_start_game(s,t);
    return 0;
}
