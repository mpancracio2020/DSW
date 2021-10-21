#include <iostream>

using namespace std;

#include "primes.h"

int main()
{
    const int FIRST_VALUE = 2;
    const int LAST_VALUE = 10000000;
    const int ARRAY_SIZE = 664579;
    int array_primes[ARRAY_SIZE];

    cout << store_primes(array_primes, FIRST_VALUE, LAST_VALUE) << endl;
    // cout << number_of_primes( FIRST_VALUE, LAST_VALUE) << endl;

    return 0;
}


