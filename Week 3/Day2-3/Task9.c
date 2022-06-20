#include<stdio.h>

void SPRINTF(char* szBuffer, char* szPattern, char** args);

int main()
{
    char szBuffer[100];
    char szPattern[] = "This function takes %s and %s as arguments\n";
    char* args[] = {"Arg1","Arg2"};
    SPRINTF(szBuffer,szPattern,args);
    printf("%s\n",szBuffer);

    return 0;
}

void SPRINTF(char* szBuffer, char* szPattern, char** args)
{
    int buffcnt = 0;
    int patterncnt = 0;
    int argnum = 0;
    int argcnt = 0;
    while(szPattern[patterncnt] != '\0')
    {
        if(szPattern[patterncnt] == '%')
        {
            printf("HERE %d\n",argnum);
            if(szPattern[patterncnt+1] == 's')
            {
                while(args[argnum][argcnt]!= '\0')
                {
                    szBuffer[buffcnt++] = args[argnum][argcnt++];
                }
                patterncnt+=2;
                argcnt = 0;
                argnum++;
            }
        }
        szBuffer[buffcnt++] = szPattern[patterncnt++];
    }
    szBuffer[buffcnt] = '\0';
}
