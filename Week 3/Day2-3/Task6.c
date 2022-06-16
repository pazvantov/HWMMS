#include<stdio.h>

void Bubble(int *pArray,size_t uLen);

int main()
{
    int arr[10] = {1,7,3,53,34,112,52,3,9,0};
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    putchar('\n');
    Bubble(arr,10);
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

void Bubble(int *pArray,size_t uLen)
{
    for(int i=0;i<uLen;i++)
    {
        for(int j = 0;j<uLen - i - 1;j++)
        {
            if(pArray[j] > pArray[j + 1])
            {
                int swap = pArray[j];
                pArray[j] = pArray[j+1];
                pArray[j+1] = swap; 
            }
        }
    }
}