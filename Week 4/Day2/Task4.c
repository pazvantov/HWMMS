#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>


int main(int argc, char** argv, char** env)
{
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork");
    }

    if(0 == pid)
    {
        if((execlp(argv[1],argv[1],NULL)) == -1)
        {
            perror("execle");
        }
        exit(EXIT_FAILURE);
    }
    else
    {
        int wstatus;
        wait(&wstatus);
        if(WIFEXITED(wstatus))
        {
            int statusCode = WEXITSTATUS(wstatus);
            if(statusCode != 0)
            {
                if((execlp(argv[2],argv[2],NULL)) == -1)
                {
                    perror("execle");
                }
            }
        }
    }
    return 0;
}