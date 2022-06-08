#include<stdio.h>

unsigned sumArrayDigits(const int* arr, size_t n);

int main()
{

    int arr[] = {12,34,5,70};
    printf("Sum is:%u\n",sumArrayDigits(arr,4));

    return 0;
}

unsigned sumArrayDigits(const int* arr, size_t n)
{
    unsigned sum = 0;
    int temp;
    for(int i=0;i<n;i++)
    {
        temp = arr[i];
        while(temp != 0)
        {
            sum += temp % 10;
            temp /= 10;
        }
    }
    return sum;
}