#include<stdio.h>
#include<stdint.h>

unsigned onesCount(uint64_t mask);

int main()
{
    uint64_t test;
    scanf("%ld",&test);
    unsigned res = onesCount(test);
    printf("%u\n",res);

    return 0;
}

unsigned onesCount(uint64_t mask)
{
    unsigned count = 0;
    for(int i=0;i<64;i++)
    {
        if(!!(mask & (1ul<<i)))
            count++;
        
    }
    return count;
}
