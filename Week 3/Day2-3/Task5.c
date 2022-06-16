#include<stdio.h>

#define MAX_SIZE 10

int arr[MAX_SIZE];
int top = 0;
int bottom = 0;

int isEmpty();
int isFull();
void Push(int nNewValue);
int Pop();
void printArr();

int main()
{
    printArr();
    if(isFull())
        Push(12);
    printArr();
    if(isFull())
        Push(15);
    if(isFull())
        Push(32);
    if(isFull())
        Push(1123);
    printArr();
    printf("Pop=%d\n",Pop());
    printArr();
    return 0;
}

int isEmpty()
{
    return !(top == bottom);
}

int isFull()
{
    return !(top == MAX_SIZE - 1);
}

void Push(int nNewValue)
{
    for(int i=top+1;i>0;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = nNewValue;
    top++;
}

int Pop()
{
    return arr[top-- - 1];
}

void printArr()
{
    for(int i=0; i< top;i++)
    {
        printf("%d ",arr[i]);
    }
    putchar('\n');
}