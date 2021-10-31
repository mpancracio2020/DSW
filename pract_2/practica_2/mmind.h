#ifndef MMIND_H_INCLUDED
#define MMIND_H_INCLUDED
#include <iostream>
using namespace std;

string get_level();
string get_election();
string get_repet_chose();
int get_intento();
int get_length(string level);
int get_interval(string level);
void rellenar_num_secreto(unsigned int numSecretoArray[],unsigned const int l,unsigned const elem, string election);
void array_to_string(unsigned int arr[],int n);
bool get_repeted_num();
void get_array_value(unsigned int arr[]);
void intentos(string nivel, unsigned int numSecreto[], unsigned int intentoDigitos[],const int num_elem,unsigned int intento,int interval,string election_user);
//void heart();

#endif // MMIND_H_INCLUDED
