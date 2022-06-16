#include<stdio.h>
#include<stdint.h>

void Conv(int16_t sValue, char* pBuffer);

int main()
{
    int16_t num = -1523;
    char str[7];
    Conv(num,str);
    printf("%s\n",str);
    return 0;
}

void Conv(int16_t sValue, char* pBuffer)
{
    for(int i=0;i<7;i++)pBuffer[i] = ' ';
    if(sValue<0)
    {
        pBuffer[0] = '-';
        sValue *= -1;
    }
    else
        pBuffer[0] = ' ';
    
    
    int i = 5;
    while(sValue != 0)
    {
        pBuffer[i] = '0' + sValue%10;
        printf("%d-%c-%d\n",sValue,pBuffer[i],i);
        sValue /= 10;
        i--;
    }
    pBuffer[6] = '\0';

}