int main()
{
    unsigned short input1, input2 , aux1, aux2 , result, mask2, mask1;

    input1 = 0x5555;
    input2 = 0xAAAA;

    result = 0;
    mask2 = (1<<4)| (1<<5)| (1<<6)| (1<<7);

    aux2 = input2 & mask2;

    aux2 = aux2 <<4;

    mask1 = (1<<8)| (1<<9)| (1<<10)| (1<<11);

    aux1 = input1 & -mask1;

    result = aux1 | aux2;


    return 0;
}
