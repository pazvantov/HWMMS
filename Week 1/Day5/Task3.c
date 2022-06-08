#include<stdio.h>

int rectangle(double w, double h, double* S, double* P);

int main()
{
    double w,h,S,P;
    while(scanf("%lf %lf",&w,&h) != EOF)
    {
        int check = rectangle(w,h,&S,&P);
        if(!check)
        {
            printf("S = %lf\nP = %lf\n",S,P);
        }
    }

    return 0;
}

int rectangle(double w, double h, double* S, double* P)
{
    if(w <= 0 || h <=0)
    {
        printf("---Invalid rectangle!\n");
        return -1;
    } 
    
    *P = 2*w + 2*h;
    *S = w * h;
    return 0;
}