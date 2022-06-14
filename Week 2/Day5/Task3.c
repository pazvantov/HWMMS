#include<stdio.h>
#include<stdint.h>

int clearBit(uint32_t* maskArr, size_t nitems, size_t bit);
int setBit(uint32_t* maskArr, size_t nitems, size_t bit);
int checkBit(uint32_t* maskArr, size_t nitems, size_t bit);
void printArr(uint32_t* maskArr, size_t nitems);

int main()
{
    uint32_t maskArr[3]={-1,-1,-1};
    printArr(maskArr,3);
    clearBit(maskArr,3,32);
    clearBit(maskArr,3,42);
    printArr(maskArr,3);
    setBit(maskArr,3,42);
    printArr(maskArr,3);
    printf("%d-%d\n",checkBit(maskArr,3,60),checkBit(maskArr,3,32));
    return 0;
}

int clearBit(uint32_t* maskArr, size_t nitems, size_t bit)
{
    bit--;
    if(bit > nitems * 32 - 1)
    {
        fprintf(stderr,"Invalid bit!\n");
        return -1;
    }
    int i = bit / 32;
    bit %= 32;
    printf("i=%d bit = %lu\n",i,bit);
    maskArr[i] &= ~(1<<bit);
    return 0;
}

int setBit(uint32_t* maskArr, size_t nitems, size_t bit)
{
    bit--;
    if(bit > nitems * 32 - 1)
    {
        fprintf(stderr,"Invalid bit!\n");
        return -1;
    }
    int i = bit / 32;
    bit %= 32;
    maskArr[i] |= (1<<bit);
    return 0;
}

int checkBit(uint32_t* maskArr, size_t nitems, size_t bit)
{
    bit--;
    if(bit > nitems * 32 - 1)
    {
        fprintf(stderr,"Invalid bit!\n");
        return -1;
    }
    int i = bit / 32;
    bit %= 32;
    return !!(maskArr[i] &= (1<<bit));
    
}

void printArr(uint32_t* maskArr, size_t nitems)
{
    for(int i=nitems-1;i>=0;i--)
    {
        for(int j=31;j>=0;j--)
        {
            if(maskArr[i] & (1<<j))
                printf("1");
            else
                printf("0");
        }
        putchar(' ');
    }
    putchar('\n');
}