#include<stdio.h>

void Add(const char* p1, const char *p2, char *result);

int main()
{
    char p1[5] = "1234";
    char p2[5] = "1111";
    char result[10];
    Add(p1,p2,result);
    printf("%s\n",result);

    return 0;
}

void Add(const char* p1, const char *p2, char *result)
{
    int num1 = 0,num2 = 0;
    int sum;
    int power = 1;
    int i = 0;
    while(p1[i] != '\0')
    {
        num1 += (p1[i] - '0') * power;
        power *= 10;
        i++;
    }
    power = 1;
    i = 0;
    while(p2[i] != '\0')
    {
        num2 += (p2[i] - '0') * power;
        power *= 10;
        i++;
    }
    sum = num1 + num2;
    char temp[11];
    i = 0;
    while(sum != 0)
    {
        temp[i] = (sum % 10) + '0';
        sum /= 10;
        i++;
    }
    int count = 0;
    for(i--;i>=0;i--)
    {
        result[count] = temp[i];
        count++;
    }

}