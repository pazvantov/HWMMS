#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<unistd.h>
#include<string.h>

int myfprintf(FILE *stream, const char *format, ...);

int main()
{
    FILE *f;
    f = fopen("testFile","w");
    myfprintf(f,"%s asd %d\n %f -- %c\n","Hello", 14, 10.2, 'k');
    fclose(f);
    return 0;
}

int myfprintf(FILE *stream, const char *format, ...)
{
    int cnt = 0;
    int fd = fileno(stream);
    va_list argl;
    va_start(argl,format);
    while(format[cnt] != '\0')
    {
        if(format[cnt] == '%')
        {
            if(format[cnt+1] == 'c')
            {
                char temp = va_arg(argl,int);
                if(write(fd,&temp,sizeof(char)) == -1)
                    return -1;
                cnt+=2;
                continue;
            }

            if(format[cnt+1] == 's')
            {
                char temp[BUFSIZ];
                strcpy(temp,va_arg(argl,char*));
                if(write(fd,temp,sizeof(char) * strlen(temp)) == -1)
                    return -1;
                cnt+=2;
                continue;
            }

            if(format[cnt+1] == 'd')
            {
                int temp = va_arg(argl,int);
                if(write(fd,&temp,sizeof(int)) == -1)
                    return -1;
                cnt+=2;
                continue;
            }

            if(format[cnt+1] == 'f')
            {
                double temp = va_arg(argl,double);
                if(write(fd,&temp,sizeof(double)) == -1)
                    return -1;
                cnt+=2;
                continue;
            }
        }
        write(fd,&format[cnt],sizeof(char));
        cnt++;
    }
    return cnt;
}
