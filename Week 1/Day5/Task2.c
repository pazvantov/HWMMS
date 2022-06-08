#include<stdio.h>
#include<math.h>

int triangle(double a, double b, double c, double* S, double* P);

int main()
{
    double a,b,c,S,P;
    while(scanf("%lf %lf %lf",&a,&b,&c) != EOF)
    {
        int check = triangle (a,b,c,&S,&P);
        if(!check)
        {
            printf("S = %lf\nP = %lf\n",S,P);
        }
    }

    return 0;
}

int triangle(double a, double b, double c, double* S, double* P)
{
    if(a <= 0 || b <= 0 || c <=0)
    {
        printf("---Invalid triangle sides!\n");
        return -1;
    } 
    if((a+b<c) || (b+c<a) || (a+c<b))
    {
        printf("Invalid triangle sides!\n");
        return -1;
    }
    *P = a+b+c;
    *S = sqrt((*P/2)*((*P/2)-a)*((*P/2)-b)*((*P/2)-c));
    return 0;
}