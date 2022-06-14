#include<stdio.h>
#include<stdint.h>

typedef union
{
    uint16_t int16;
    uint8_t byte[2];
}forSwap;


void swapBytes(uint16_t* word);

int main()
{
    uint16_t num = 0b1001011000000000;
    printf("%u\n",num);
    swapBytes(&num);
    printf("%u\n",num);

    return 0;
}

void swapBytes(uint16_t* word)
{
    forSwap swap;
    swap.int16 = *word;
    uint8_t temp;
    temp = swap.byte[0];
    swap.byte[0] = swap.byte[1];
    swap.byte[1] = temp;
    *word = swap.int16;
}