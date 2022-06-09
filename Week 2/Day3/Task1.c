#include<stdio.h>

size_t strlen(const char *str);
char* strcpy(char *dest, const char *src);
char* strncpy(char *dest, const char *src, size_t n);
char* strcat(char *dest, const char *src);
char* strncat(char *dest, const char *src, size_t n);
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t n);
char *strstr(const char *haystack, const char *needle);

int main()
{
    char src[30] = "Tutorial";
    printf("src = %s\n",src);

    printf("1.strlen = %lu\n",strlen(src));
    char dest[30];
    printf("2.strcpy = %s\n",strcpy(dest,src));
    printf("3.strncpy = %s\n",strncpy(dest,src,5));
    char cat[30] = "Cat-";
    printf("4.strcat = %s\n",strcat(cat,src));
    printf("5.strncat = %s\n",strncat(cat,src,5));
    printf("src = %s\n",src);
    printf("dest = %s\n",dest);
    printf("6.strcmp = %d\n",strcmp(dest,src));
    printf("7.strncmp = %d\n",strncmp(dest,src,4));
    printf("8.strstr = %s\n",strstr(src,dest));

    return 0;
}

size_t strlen(const char *str)
{
    size_t i;
    while(str[i] != 0)
    {
        i++;
    }
    return i;
}

char* strcpy(char *dest, const char *src)
{
    int i = 0;
    while(src[i] != 0)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return dest;
}

char* strncpy(char *dest, const char *src, size_t n)
{
    for(int i =0;i<n;i++)
    {
        dest[i] = src[i];
    }
    dest[n] = 0;
    return dest;
}

char* strcat(char *dest, const char *src)
{
    int destC = 0;
    int srcC = 0;
    while(dest[destC] != 0)
        destC++;

    while(src[srcC] != 0)
    {
        dest[destC] = src[srcC];
        destC++;
        srcC++;
    }
    dest[destC] = 0;
    return dest;
}

char* strncat(char *dest, const char *src, size_t n)
{
    int destC = 0;
    int srcC = 0;
    while(dest[destC] != 0)
        destC++;

    while(src[srcC] != 0 && srcC < n)
    {
        dest[destC] = src[srcC];
        destC++;
        srcC++;
    }
    dest[destC] = 0;
    return dest;
}

int strcmp(const char *str1, const char *str2)
{
    int i = 0;
    while(str1[i] != 0 && str2[i] != 0)
    {
        
        if(str1[i] != str2[i])
        {
            if(str1[i] - str2[i] < 0)
                return -1;
            else return 1;
        }
        i++;
    }
    if(!str1[i] && !str2[i])
        return 0;
    else if(!str1[i])
        return -1;
    else if(!str2[i])
        return 1;
}

int strncmp(const char *str1, const char *str2, size_t n)
{
    int i = 0;
    while(str1[i] != 0 && str2[i] != 0 && i < n)
    {
        if(str1[i] != str2[i])
        {
            if(str1[i] - str2[i] < 0)
                return -1;
            else return 1;
        }
        i++;
    }
    if(!str1[i] || !str2[i])
    {
        if(!str1[i])
            return -1;
        else
            return 1;
    }
    return 0;
}

char *strstr(const char *haystack, const char *needle)
{
    int hayC = 0;
    int needleC = 0;
    while(haystack[hayC] != 0)
    {
        if(haystack[hayC] == needle[needleC])
        {
            needleC++;
            if(needle[needleC] == 0)
            {
                return haystack + hayC - needleC + 1;
            }
        }
        else needleC = 0;

        hayC++;
    }
    return NULL;
}