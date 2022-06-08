#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int quadEq(double a, double b, double c);

int main(int argc, char **argv)
{
    double a,b,c;
    a = strtod(argv[1],NULL);
    b = strtod(argv[2],NULL);
    c = strtod(argv[3],NULL);
    quadEq(a,b,c);

    return 0;

}

int quadEq(double a, double b, double c)
{
    double D,x1,x2;
    D = pow(b,2) - 4 * a * c;
    if(D < 0)
    {
        printf("No real roots\n");
        return -1;
    }
    else
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        printf("x1 = %lf\nx2 = %lf\n",x1,x2);
        return 0;
    }
}