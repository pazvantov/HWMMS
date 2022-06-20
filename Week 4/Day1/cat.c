#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>


int main(int argc, char** argv)
{
    if(argc == 1)
    {
        int c;
        while(read(STDIN_FILENO,&c,1) > 0)
        {
            if(-1 == write(STDOUT_FILENO,&c,1))
            {
                perror("Writing ");
            }
        }
    }
    for(int i=1;i<argc;i++)
    {
        int fd;
        fd = open(argv[i],O_RDONLY);
        if(fd == -1)
        {
            perror("Open read file ");
            return EXIT_FAILURE;
        }
        int c;
        while(read(fd,&c,1) > 0)
        {
            if(-1 == write(STDOUT_FILENO,&c,1))
            {
                perror("Writing ");
            }
        }
        c = '\n';
        if(-1 == write(STDOUT_FILENO,&c,1))
        {
            perror("Writing \\n ");
        }
        close(fd);
    }

    return EXIT_SUCCESS;
}