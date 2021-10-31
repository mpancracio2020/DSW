#include <iostream>
#include "mmind_basic.h"
#include "mmind.h"

using namespace std;

int main()
{
    string level = get_level();
    string election_user = get_election();

    int num_elem = get_length(level);


    int interval = get_interval(level);


    int intento = get_intento();

    unsigned int intentoDigitos[num_elem];

    unsigned int numSecreto[num_elem];


    intentos(level,numSecreto,intentoDigitos,num_elem,intento,interval,election_user);

    return 0;
}
