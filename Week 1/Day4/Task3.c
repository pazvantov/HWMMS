#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    char possibleSymbols[37]="0123456789abcdefghijklmnopqrstuvwxyz";
    char num[10];
    int length,counter = 0;
    int DecNum = 0;
    char result[50] = "";
    int InsertedNumSys,ToConvertSys;
    printf("Insert number:");
    scanf("%s",num);
    length = strlen(num);
    for(int i=0;i<length;i++)
    {
        if(!(('0' <= num[i] && '9' >= num[i]) || ('a' <= num[i] && 'z' >= num[i])))
        {
            fprintf(stderr,"Invalid symbols used!\n");
            return 1;
        }
    }
    printf("From base:");
    scanf("%d",&InsertedNumSys);
    if(InsertedNumSys < 2 || InsertedNumSys > 36)
    {
        fprintf(stderr,"Invalid input base!\n");
        return 1;
    }
    for(int i=0;i<length;i++)
    {
        if((num[i]>='0' + InsertedNumSys) && ('0' <= num[i] && '9' >= num[i]))
        {
            fprintf(stderr,"Invalid number!\n");
            return 1;
        }  
        if((num[i] >='a' + InsertedNumSys - 10)&&('a' <= num[i] && 'z' >= num[i]))
        {
            fprintf(stderr,"Invalid number!\n");
            return 1;
        }  
    }
    printf("To base:");
    scanf("%d",&ToConvertSys);
    if(ToConvertSys < 2 || ToConvertSys > 36)
    {
        fprintf(stderr,"Invalid output base!\n");
        return 1;
    }
    for(int i=length - 1;i>=0;i--)
    {
        if(num[i]>='0' && num[i]<='9')
            DecNum +=((num[i] - '0') * pow(InsertedNumSys,counter));
        else
            DecNum +=((num[i] - 'a' + 10) * pow(InsertedNumSys,counter));
        counter++;
    }
    printf("Result = %d\n",DecNum);
    int ost;
    counter = 0;
    while(DecNum != 0)
    {
        ost = DecNum % ToConvertSys;
        result[counter] = possibleSymbols[ost];
        DecNum /= ToConvertSys;
        counter++;
    }
    printf("The converted num is : ");
    for(int i=strlen(result)-1;i>=0;i--)
    {
        printf("%c",result[i]);
    }
    printf("\n");

}