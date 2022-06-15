#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double randReal(double min, double max);

int main()
{
    srand(time(NULL));
    int n,m,p;
    printf("n=");
    scanf("%d",&n);
    double* arr = malloc(n*sizeof(double));
    int i = 0;
    for(i=0;i<n;i++)
    {
        arr[i] = randReal(0.0,1.0);
    }

    printf("m=");
    scanf("%d",&m);
    arr = realloc(arr,(m + n)*sizeof(double));
    for(;i<(m + n);i++)
    {
        arr[i] = randReal(1.0,2.0);
    }

    printf("p=");
    scanf("%d",&p);
    arr = realloc(arr,(n + m + p)*sizeof(double));
    for(;i<(n + m + p);i++)
    {
        arr[i] = randReal(2.0,3.0);
    }

    for(i = 0;i<(n + m + p);i++)
    {
        printf("%.2lf ",arr[i]);
    }
    putchar('\n');
    free(arr);

    return 0;
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}