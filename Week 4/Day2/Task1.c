#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int randNum(int min,int max);

int main(int argc, char** argv)
{
    int N = atoi(argv[1]);

    for(int i=0;i<N;i++)
    {
        pid_t pid = fork();
        if(pid == -1)
        {
            perror("fork");
            return EXIT_FAILURE;
        }

        if(pid == 0)
        {
            srand(time(NULL) + i);
            char buff[11];
            int j;
            for(j=0;j<10;j++)
            {
                buff[j] = randNum('a','z');
            }
            buff[j] = '\0';
            printf("%s\n",buff);
            exit(EXIT_SUCCESS);
        }
    }
    for(int i=0;i<N;i++)
    {
        wait(NULL);
    }

    return 0;
}

int randNum(int min,int max)
{
    return min + rand() % (max - min + 1);
}