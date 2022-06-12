#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

#define COUNT 10

typedef struct 
{
    char Title[151];
    char Author[101];
    unsigned Pages;
    double Price;
}Book;

void randName(char* name);
int randNum(int min,int max);
double randReal(double min, double max);
void genBooks(Book *array, size_t n);
void printBooks(Book *array, size_t n);
int compTitleASC(const void *b1, const void *b2);
int compTitleDESC(const void *b1, const void *b2);
int compAuthorASC(const void *b1, const void *b2);
int compAuthorDESC(const void *b1, const void *b2);
int compPagesASC(const void *b1, const void *b2);
int compPagesDESC(const void *b1, const void *b2);
int compPriceASC(const void *b1, const void *b2);
int compPriceDESC(const void *b1, const void *b2);

int main()
{
    srand(time(NULL));
    Book array[COUNT];
    genBooks(array,COUNT);
    printBooks(array,COUNT);
    qsort(array,COUNT,sizeof(array[0]),compPriceDESC);
    putchar('\n');
    printBooks(array,COUNT);



    return 0;
}

void randName(char* name)
{
    int i = 0;
    int numbofsml;
    for(int j=0;j<2;j++)
    {
        name[i++] = randNum('A','Z');
        numbofsml = randNum(5,8);
        for(int c = 0;c<numbofsml;c++)
        {
            name[i++] = randNum('a','z');
        }
        if(j == 0)
            name[i++] = ' ';
    }
    name[i] = 0;
}

int randNum(int min,int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void genBooks(Book *array, size_t n)
{
    for(int i=0;i<n;i++)
    {
        randName(array[i].Title);
        randName(array[i].Author);
        array[i].Pages = randNum(5,2000);
        array[i].Price = randReal(1.0,1000.0);
    }
}

void printBooks(Book *array, size_t n)
{
    for(int i=0;i<n;i++)
    {
        printf("Title:%20s Author:%20s Pages:%4u Price:%4.2lf\n",array[i].Title,
        array[i].Author,array[i].Pages,array[i].Price);
    }
}

int compTitleASC(const void *b1, const void *b2)
{
    Book *el1 = (Book*)b1;
    Book *el2 = (Book*)b2;
    return strcmp(el1->Title,el2->Title);
}

int compTitleDESC(const void *b1, const void *b2)
{
    Book *el1 = (Book*)b1;
    Book *el2 = (Book*)b2;
    return strcmp(el2->Title,el1->Title);
}

int compAuthorASC(const void *b1, const void *b2)
{
    Book *el1 = (Book*)b1;
    Book *el2 = (Book*)b2;
    return strcmp(el1->Author,el2->Author);
}

int compAuthorDESC(const void *b1, const void *b2)
{
    Book *el1 = (Book*)b1;
    Book *el2 = (Book*)b2;
    return strcmp(el2->Author,el1->Author);
}

int compPagesASC(const void *b1, const void *b2)
{
    Book *el1 = (Book*)b1;
    Book *el2 = (Book*)b2;
    return el1->Pages - el2->Pages;
}

int compPagesDESC(const void *b1, const void *b2)
{
    Book *el1 = (Book*)b1;
    Book *el2 = (Book*)b2;
    return el2->Pages - el1->Pages;
}

int compPriceASC(const void *b1, const void *b2)
{
    Book *el1 = (Book*)b1;
    Book *el2 = (Book*)b2;
    if(fabs(el1->Price - el2->Price) < 0.001)
        return 0;
    else if(el1->Price > el2->Price)
        return 1;
    return -1;
}

int compPriceDESC(const void *b1, const void *b2)
{
    Book *el1 = (Book*)b1;
    Book *el2 = (Book*)b2;
    if(fabs(el1->Price - el2->Price) < 0.001)
        return 0;
    else if(el1->Price < el2->Price)
        return 1;
    return -1;
}