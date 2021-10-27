#ifndef MMIND_H_INCLUDED
#define MMIND_H_INCLUDED
#include <iostream>
#include<vector>
using namespace std;

string get_level();
int get_intento();
int get_length(string level);
int get_interval(string level);
void rellenar_num_secreto(unsigned int numSecretoArray[],unsigned const int l);
void array_to_string(unsigned int arr[],int n);

bool get_repeted_num();
void get_array_value(unsigned int arr[]);
//void heart();

#endif // MMIND_H_INCLUDED
