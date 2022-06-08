#include<stdio.h>
#include<math.h>

int floatCompare1(float a, float b)
{
    return a == b;
}

int floatCompare2(float a, float b)
{
    return fabs(a - b) < 1.0e-5f;
}

int floatCompare3(float a, float b)
{
    return fabs(a - b) < 1.0e-5f * fmax(fabs(a),fabs(b));
}

int doubleCompare1(double a, double b)
{
    return a == b;
}

int doubleCompare2(double a, double b)
{
    return fabs(a - b) < 1.0e-5;
}

int doubleCompare3(double a, double b)
{
    return fabs(a - b) < 1.0e-5 * fmax(fabs(a),fabs(b));
}
int main()
{
    float af = 200.0f;
    float bf = 0.0f;
    double ad = 200.0;
    double bd = 0.0;
    for(int i = 0;i<2000;i++)
    {
        bf += 0.1f;
        bd += 0.1f;
    }
    if(floatCompare1(af,bf))
        printf("CF1-True\n");
    else
        printf("CF1-False\n");
    
    if(floatCompare2(af,bf))
        printf("CF2-True\n");
    else
        printf("CF2-False\n");

    if(floatCompare3(af,bf))
        printf("CF3-True\n");
    else
        printf("CF3-False\n");

    if(doubleCompare1(ad,bd))
        printf("CD1-True\n");
    else
        printf("CD1-False\n");

    if(doubleCompare2(ad,bd))
        printf("CD2-True\n");
    else
        printf("CD2-False\n");

    if(doubleCompare3(ad,bd))
        printf("CD3-True\n");
    else
        printf("CD3-False\n");

    return 0;
}