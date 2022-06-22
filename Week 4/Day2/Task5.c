#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void closed(int arg);
void paused(int arg);

int main()
{
    struct sigaction saClosed;
    saClosed.sa_handler = closed;
    saClosed.sa_flags = SA_RESTART;
    sigaction(SIGINT, &saClosed, NULL);

    struct sigaction saPaused;
    saPaused.sa_handler = paused;
    saPaused.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &saPaused, NULL);

    while(1)
    {
        sleep(1);
        printf("MMS C Camp\n");
    }

    return 0;
}
void closed(int arg)
{
    printf("Nope\n");
}

void paused(int arg)
{
    printf("Try again\n");
}