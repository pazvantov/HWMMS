#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char** argv)
{
    int fd[2];
    if(pipe(fd) == -1)
    {
        perror("pipe");
        return EXIT_FAILURE;
    }
    pid_t pid = fork();
    if(pid == 0)
    {
        int sum = 0;
        for(int i = (argc/2) + 1;i<argc;i++)
        {
            sum+= atoi(argv[i]);
            printf("Child num:%d\n",sum);
        }
        write(fd[1],&sum,sizeof(int));
        exit(EXIT_SUCCESS);
    }
    else if(pid>0)
    {
        int sum = 0;
        for(int i = 1;i<argc/2 + 1;i++)
        {
            sum+= atoi(argv[i]);
            printf("Parent num:%d\n",sum);
        }
        wait(NULL);
        int childNum;
        read(fd[0],&childNum,sizeof(int));
        sum+=childNum;
        printf("The sum is :%d\n",sum);
    }
    return 0;
}