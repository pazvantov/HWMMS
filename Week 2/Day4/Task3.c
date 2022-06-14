#include<stdio.h>

int binarySearch(int *array, size_t n, int key);
int mybSearch(int *array, size_t l, size_t r, int key);

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
    return mybSearch(array,0,n-1,key);
    
}

int mybSearch(int *array, size_t l, size_t r, int key)
{
    if(r >= l)
    {
        int mid =l + (r-l) / 2;
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
    
    return -1;
}