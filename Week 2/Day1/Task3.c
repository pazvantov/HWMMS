#include<stdio.h>
#include<stdint.h>

#define TCHAR 1
#define TDOUBLE 2
#define TFLOAT 3
#define TINT8 4
#define TINT16 5
#define TINT32 6
#define TINT64 7

void printValue(const void* valuePtr, uint8_t flag);

int main()
{
    char c = 'b';
    printValue(&c,TCHAR);

    double d = 13.2;
    printValue(&d,TDOUBLE);

    float f = 11.32;
    printValue(&f,TFLOAT);

    uint8_t ui8 = 8;
    printValue(&ui8,TINT8);

    uint16_t ui16 = 16;
    printValue(&ui16,TINT16);

    uint32_t ui32 = 32;
    printValue(&ui32,TINT32);

    uint64_t ui64 = 64;
    printValue(&ui64,TINT64);

    uint8_t ui9 = 15;
    printValue(&ui9,8);

    return 0;
}

void printValue(const void* valuePtr, uint8_t flag)
{
    if(flag == 1)
        printf("Char : %c\n",*(char*)valuePtr);
    else if(flag == 2)
        printf("Double : %lf\n",*(double*)valuePtr);
    else if(flag == 3)
        printf("Float : %f\n",*(float*)valuePtr);
    else if(flag == 4)
        printf("Uint8 : %u\n",*(uint8_t*)valuePtr);
    else if(flag == 5)
        printf("Uint16 : %u\n",*(uint16_t*)valuePtr);
    else if(flag == 6)
        printf("Uint32 : %u\n",*(uint32_t*)valuePtr);
    else if(flag == 7)
        printf("Uint64 : %lu\n",*(uint64_t*)valuePtr);
    else fprintf(stderr,"Invalid flag!\n");
    
}