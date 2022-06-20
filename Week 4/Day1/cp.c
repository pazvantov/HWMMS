#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>


int main(int argc, char** argv)
{
    int n = 0;
    int fr, fw;
    fr = open(argv[1],O_RDONLY);
    fw = open(argv[2],O_WRONLY | O_CREAT, 0754);
    if(fr == -1)
    {
        perror("Open read file ");
        return EXIT_FAILURE;
    }
    if(fw == -1)
    {
        perror("Open read file ");
        return EXIT_FAILURE;
    }
    int c;
    while(read(fr,&c,1) > 0 && n<10)
    {
        if(-1 == write(fw,&c,1))
        {
            perror("Writing ");
        }
    }
    close(fr);
    close(fw);

    return 0;
}