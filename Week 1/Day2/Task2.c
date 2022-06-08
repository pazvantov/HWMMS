#include<stdio.h>

int main()
{
    int count = 2;
    int a,b;
    fscanf(stdin,"%d",&a);
    while(fscanf(stdin,"%d",&b) != -1)
    {
        if(count == 0)
            break;
        a ^= b;
        count--;
    }
    fprintf(stdout,"%d\n",a);

    return 0;
}