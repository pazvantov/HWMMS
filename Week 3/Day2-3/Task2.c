#include<stdio.h>
#include<stdlib.h>

void Reverse(char* ptr);

int main()
{
    char str[6] = "asdfa";
    Reverse(str);
    return 0;
}

void Reverse(char* ptr)
{
    int len = 0;
    while(ptr[len] != '\0') len++;
    printf("len=%d\n",len);
    char swap;
    for(int i=len-1;i>=len/2;i--)
    {
        swap = ptr[i];
        printf("%c-%d\n",swap,len - i - 1);
        ptr[i] = ptr[len-i-1];
        ptr[len-i - 1] = swap;
    }

    printf("%s\n",ptr);
}

