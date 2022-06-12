#include<stdio.h>

int binarySearch(int *array, size_t n, int key);

int main()
{
    int array[] = {10,13,54,81,132};
    int key;
    scanf("%d",&key);
    printf("%d\n",binarySearch(array,5,key));

    return 0;
}

int binarySearch(int *array, size_t n, int key)
{
    printf("n = %lu\n",n);
    if(array[n/2] == key)
    {
        return n/2;
    }
    else if(array[n/2] > key)
    {
        return binarySearch(array, n/2, key);
    }
    else if(array[n/2-1] < key)
    {
        return n/2 + binarySearch(array + n/2, n/2 , key);
    }
    return -1;
}