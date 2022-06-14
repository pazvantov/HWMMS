#include<stdio.h>
#include<stdint.h>

void showBits(double num);

int main()
{
    double num;
    scanf("%lf",&num);
    showBits(num);
    return 0;
}

void showBits(double num)
{
    union intReal
    {
        double realNum;
        uint64_t num;
    };
    union intReal a;
    a.realNum = num;
    for(int i=63;i>=0;i--)
    {
        if(a.num & (1<<i))
            printf("1");
        else
            printf("0");
    }
    putchar('\n');

}


