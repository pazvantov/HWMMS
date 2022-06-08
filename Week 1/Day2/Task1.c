#include<stdio.h>

int main()
{
    float a,b,c,max;
    fscanf(stdin,"%f",&a);
    fscanf(stdin,"%f",&b);
    fscanf(stdin,"%f",&c);
    max = a;
    if(max<b)
        max = b;
    if(max<c)
        max = c;

    fprintf(stdout,"%f\n",max);
    return 0;
}