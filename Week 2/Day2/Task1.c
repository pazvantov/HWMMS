#include<stdio.h>

int secondMax(const int* arr,size_t n,int* secondMax);

int main()
{
    int secondMaxx;
    int a[] = {};
    int b[] = {3};
    int c[] = {5,5,5,5,5,5};
    int d[] = {3,17,21,22,6,32,1};

    secondMax(a,0,&secondMaxx);
    printf("%d\n",secondMaxx);
    secondMax(b,1,&secondMaxx);
    printf("%d\n",secondMaxx);
    secondMax(c,6,&secondMaxx);
    printf("%d\n",secondMaxx);
    secondMax(d,7,&secondMaxx);
    printf("%d\n",secondMaxx);



    return 0;
}

int secondMax(const int* arr,size_t n,int* secondMax)
{
    if(n == 0)
    {
        fprintf(stderr,"Array has no elements!\n");
        return -1;
    }
    
    if(n == 1)
    {
        fprintf(stderr,"Array has only one element!\n");
        return -1;
    }
        
    int max = *arr;
    int check = 0;
    int checkSame = 1;
    int checknum = *arr;

    for(int i=1;i<n;i++)
    {
        if(arr[i] != checknum)
            checkSame = 0;
        
        if(max < arr[i])
        {
            if(check)
                *secondMax = max;

            max = arr[i];
            check = 1;
        }
    }
    if(checkSame)
    {
        fprintf(stderr,"The array has identical elements!\n");
        return -1;
    }
    return 0;
}