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
void* linearSearch(const void *,void *,size_t,size_t,int(*compar)(const void *, const void *));


int compPagesASC(const void *b1, const void *b2);

int main()
{
    srand(time(NULL));
    Book array[COUNT];
    genBooks(array,COUNT);
    printBooks(array,COUNT);
    Book key = {
        .Title = "The Witcher",
        .Author = "Andrzej Sapkowski",
        .Pages = 300,
        .Price = 20.5
    };
    putchar('\n');
    Book *res = linearSearch(&key,array,COUNT,sizeof(array[0]),compPagesASC);
    if(!res)
        printf("Not Found\n");
    else printBooks(res,1);


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
        array[i].Pages = randNum(290,310);
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

void* linearSearch(const void *key, void *base, size_t nitems, size_t size, int(*compar)(const void *, const void *))
{
    for(int i=0;i<nitems;i++)
    {
        if(!compar(base + i*size, key))
            return base + i*size;
    }
    return NULL;
}

int compPagesASC(const void *b1, const void *b2)
{
    Book *el1 = (Book*)b1;
    Book *el2 = (Book*)b2;
    return el1->Pages - el2->Pages;
}