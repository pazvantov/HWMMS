#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int randNum(int min,int max);
void* genMessage(void *arg);

int main(int argc, char** argv)
{
    srand(time(NULL));
    int N = atoi(argv[1]);
    pthread_t* threads = malloc(sizeof(pthread_t) * N);
    for(int i=0;i<N;i++)
    {
        pthread_create(&threads[i],NULL,genMessage,NULL);
    }

    for(int i=0;i<N;i++)
    {
        if(pthread_join(threads[i], NULL)){
            perror("join");
            exit(EXIT_FAILURE);
        }
    }
    free(threads);
    return 0;
}

void* genMessage(void *arg)
{
    char temp[11];
    int i;
    for(i = 0;i < 10;i++)
    {
        temp[i] = randNum('a','z');
    }
    temp[i++] = '\n';
    write(STDOUT_FILENO,temp,sizeof(char) * (i+1));
}

int randNum(int min,int max)
{
    return min + rand() % (max - min + 1);
}