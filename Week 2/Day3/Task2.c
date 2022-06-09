#include<stdio.h>

void map(int *array, size_t n, int (*func)(int));
int times2(int num);

int main()
{
    int array[] = {10,13,50,8};
    map(array,4,times2);
    for(int i=0;i<4;i++)
    {
        printf("%d\n",array[i]);
    }

    return 0;
}
int times2(int num)
{
    return num<<1;
}

void map(int *array, size_t n, int (*func)(int))
{
    for(int i=0; i<n; i++)
    {
        array[i] = func(array[i]);
    }
}