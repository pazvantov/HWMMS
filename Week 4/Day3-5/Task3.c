#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void* Print(void* arg);

int main(int argc, char** argv)
{
    unsigned int P,T;
    P = atoi(argv[1]);
    T = atoi(argv[2]);
    pid_t pid;
    for(int i=0;i<P;i++)
    {
        pid = fork();
        if(pid == -1)
        {
            perror("fork");
            return EXIT_FAILURE;
        }
        if(pid == 0)
        {
            pthread_t *th = malloc(sizeof(pthread_t) * T);
            for(int j=0;j<T;j++)
            {   
                pthread_create(&th[j],NULL,Print,argv[3]);
            }

            for(int j=0;j<T;j++)
            {
                pthread_join(th[j],NULL);
            }
            exit(EXIT_SUCCESS);
        }
        
    }
    for(int i=0;i<P;i++)
    {
        wait(NULL);
    }
    return EXIT_SUCCESS;
}

void* Print(void* arg)
{
    printf("PID:%d -- Thread id:%ld -- %s\n",getpid(),pthread_self(),(char*)arg);
}