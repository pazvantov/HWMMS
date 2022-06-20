#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>


int main(int argc, char** argv)
{
    int n = 0;
    int fd;
    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        perror("Open read file ");
        return EXIT_FAILURE;
    }
    int c;
    while(read(fd,&c,1) > 0 && n<10)
    {
        if(c == '\n')
            n++;
        if(-1 == write(STDOUT_FILENO,&c,1))
        {
            perror("Writing ");
        }
    }
    close(fd);
}