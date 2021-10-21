#include <iostream>
#include "mmind_basic.h"
#include "mmind.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    //get_level();

    //get_repeted_num();
    unsigned int intento = 4513;
    unsigned int intentoDigitos[4];
    const int num_elem = 4;

    rellenarIntento(intento,intentoDigitos, num_elem);

    return 0;
}
