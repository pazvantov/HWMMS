#include<stdio.h>

double sqrt(double num);

int main()
{
    double num = 64;
    printf("Square root of %lf is %lf\n",num,sqrt(num));

    return 0;
}

double sqrt(double num)
{
    double sqrt = num / 2;
    double temp = 0;
    while(sqrt != temp)
    {
        temp = sqrt;
        sqrt = (num/temp + temp) / 2;
    }

    return sqrt;
}