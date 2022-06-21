#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>
#include<getopt.h>

int main(int argc, char** argv)
{
    DIR *pDir;
    struct dirent *pDirent;
    int opt;
    pDir = opendir(".");
    while((opt = getopt(argc,argv,"rda")) != -1)
    {
        switch(opt)
        {
            case 'r':
                while((pDirent = readdir(pDir)) != NULL)
                {
                    if(pDirent->d_type == DT_REG)
                        printf("%s ",pDirent->d_name);
                }
                putchar('\n');
                break;
            case 'd':
                while((pDirent = readdir(pDir)) != NULL)
                {
                    if(pDirent->d_type == DT_DIR && pDirent->d_name[0] != '.')
                        printf("%s ",pDirent->d_name);
                }
                putchar('\n');
                break;
            case 'a':
                while((pDirent = readdir(pDir)) != NULL)
                {
                    printf("%s ",pDirent->d_name);
                }
                putchar('\n');
                break;
            default:
                printf("Genis\n");

        }
    }
    closedir(pDir);


    return 0;
}