#include <iostream>
#include "mmind_basic.h"
#include "mmind.h"

using namespace std;

int main()
{
    string level = get_level();

    const int num_elem = get_length(level);
    //cout<<"Your try lenght must be : "<<num_elem<<endl;

    int intento = get_intento();
    //cout<<"Your try: "<<intento<<endl;

    unsigned int intentoDigitos[num_elem];

    unsigned int numSecreto[num_elem];
    rellenar_num_secreto(numSecreto,num_elem);
    array_to_string(numSecreto,num_elem);

    rellenarIntento(intento,intentoDigitos, num_elem);
    array_to_string(intentoDigitos,num_elem);

    calcularAciertos(numSecreto,intentoDigitos,num_elem);
    calcularSemiaciertos(numSecreto,intentoDigitos,num_elem);
    comprobarDigitosRepetidos(intentoDigitos,num_elem);



    //heart();
    return 0;
}
