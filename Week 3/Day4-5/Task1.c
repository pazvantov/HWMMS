#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define COUNT 10

typedef struct 
{
    char Title[151];
    char Author[101];
    int Pages;
    double Price;
}Book;

int randNum(int min,int max);
double randReal(double min, double max);
void randName(char* name);
void FillBookArray(Book* arr);

int main(int argc, char **argv)
{
    srand(time(NULL));
    Book arr[COUNT];
    FillBookArray(arr);
    char fName[20];
    strcpy(fName,argv[1]);
    FILE *fptr;
    fptr = fopen(fName,"wb");
    if((fptr == NULL))
    {
        fprintf(stderr,"Error!");
    }
    fwrite(arr, sizeof(arr[0]) * COUNT,1,fptr);

    fclose(fptr);
    return 0;
}

int randNum(int min,int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void randName(char* name)
{
    srand(time(NULL));
    int i = 0;
    int numbofsml;
    for(int j=0;j<2;j++)
    {
        name[i++] = randNum('A','Z');
        numbofsml = randNum(4,9);
        for(int c = 0;c<numbofsml;c++)
        {
            name[i++] = randNum('a','z');
        }
        if(j == 0)
            name[i++] = ' ';
    }
    name[i] = 0;
}

void FillBookArray(Book* arr)
{
    for(int i=0;i<COUNT;i++)
    {
        randName(arr[i].Author);
        randName(arr[i].Title);
        arr[i].Pages = randNum(5,2000);
        arr[i].Price = randReal(1.0,1000.0);
    }
}