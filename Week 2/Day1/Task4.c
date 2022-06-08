#include<stdio.h>
#include<stdarg.h>

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...);

int main()
{
    printf("Result1 is : %u\n",bitsNCount(4,2,0x0a,0xff,0,1));
    printf("Result2 is : %u\n",bitsNCount(3,8,0xff,0x13f1,0xaaaa));
    printf("Result3 is : %u\n",bitsNCount(5,10,0x0a,0xa0ff,0,10,0b1010111110111));

    return 0;
}

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...)
{
    int result = 0;
    unsigned mask;
    int counter;
    va_list argl;
    va_start(argl,bitscnt);
    for(int i=0;i<count;i++)
    {
        counter = 0;
        mask = va_arg(argl,unsigned);
        for(int j=0;j<32;j++)
        {
            if(mask & (1<<j))
                counter++;
        }
        if(counter == bitscnt)
            result++;
    }
    return result;
}
