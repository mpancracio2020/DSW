
int main()
{
    const int LIMITE = 20;
    unsigned long long factorial, resultado;


    for (int i = 0; i <= LIMITE; i++)
    {
        factorial = 1;
        for (int j = 1; j <= i; j++)
        {
             factorial *= j;
        }
        resultado = factorial << 2 ;
    }

    return 0;
}
