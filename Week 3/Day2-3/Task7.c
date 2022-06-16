#include<stdio.h>

unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue);
unsigned int mybSearch(unsigned *array, int l, int r, unsigned key);

int main()
{
    unsigned int array[5] = {10,13,54,81,132};
    unsigned int key;
    scanf("%u",&key);
    printf("%u\n",BinSearch(array,5,key));

    return 0;
}

unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue)
{
    return mybSearch(pArray,0,uArraySize-1,uValue);
}

unsigned int mybSearch(unsigned *array, int l, int r, unsigned key)
{
    if(r >= l)
    {
        unsigned mid =l + (r-l) / 2;
        if(array[mid] == key)
        {
            return mid;
        }

        if(array[mid] > key)
        {
            return mybSearch(array, l, mid - 1, key);
        }

            return mybSearch(array , mid + 1, r, key);
    }
    
    return 0xFFFFFFFF;
}