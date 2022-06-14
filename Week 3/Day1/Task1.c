#include<stdio.h>

#define MAX(x,y,z) ((x>y)?((x>z)?x:z):((y>z)?y:z))
#define MIN(x,y,z) ((x<y)?((x<z)?x:z):((y<z)?y:z))
#define SETBIT(mask,bit) (mask |= (1<<bit-1))
#define CLEARBIT(mask,bit) (mask &= ~(1<<bit-1))
#define INVERSEBIT(mask,bit) (mask ^= (1<<bit-1))
#define CHECKBIT(mask,bit) (mask &= (1<<bit-1))
#define SWAP(a,b) (a ^= b ^= a ^= b)

int main()
{
    printf("%d\n",MAX(1,5,3));
    printf("%d\n",MIN(8,5,3));
    int n = 4;
    SETBIT(n,2);
    printf("n=%d\n",n);
    CLEARBIT(n,3);
    printf("n=%d\n",n);
    INVERSEBIT(n,1);
    printf("n=%d\n",n);
    if(!!CHECKBIT(n,5))
        printf("ITS 1\n");
    else    
        printf("ITS 0\n");
    int a = 3, b = 7;
    SWAP(a,b);
    printf("a=%d,b=%d\n",a,b);
    
    return 0;
}