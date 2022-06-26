#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int comp(const void* el1, const void* el2);
void* Sort(void* arg);

int randNum(int min,int max)
{
    return min + rand() % (max - min + 1);
}

int main(int argc, char** argv)
{
    pthread_t *th = malloc(sizeof(pthread_t) * (argc - 1));
    for(int i=1;i<argc;i++)
    {
        pthread_create(&th[i-1],NULL,Sort,argv[i]);
    }

    for(int i=0;i<argc - 1;i++)
    {
        pthread_join(th[i],NULL);
    }
    free(th);
    return 0;
}

void* Sort(void* arg)
{
    printf("Start sort\n");
    int temp[100];
    int i = 0;
    FILE *f;
    f = fopen((char*)arg,"rb");
    while((fread(&temp[i],sizeof(int),1,f)) != 0)
    {
        i++;
    }
    fclose(f);
    qsort(temp,i,sizeof(int),comp);
    
    f = fopen((char*)arg,"wb");
    for(int j=0;j<i;j++)
    {
        if(!fwrite(&temp[j],sizeof(int),1,f))
        {
            perror("write");
        }
    }
    fclose(f);

}

int comp(const void* el1, const void* el2)
{
    return *(int *)el1 - *(int *)el2;
}