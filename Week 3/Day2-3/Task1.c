#include<stdio.h>
#include<stdint.h>

unsigned char CheckBit(unsigned int uValue);

int main()
{
    uint16_t num;
    scanf("%hx",&num);
    printf("0x0%x\n",CheckBit(num));
    return 0;
}

unsigned char CheckBit(unsigned int uValue)
{
    int check = 0;
    for(int i=0;i<16;i++)
    {
        if(uValue & (1<<i))
            check++;
    }
    if(check == 1)
        return 1;
    else
        return 0;
}