#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
    char operation;
    double op1,op2,result;
    int i,length,count = 0;;
    
    while(scanf("%lf %c %lf",&op1, &operation, &op2) != EOF)
    {
        printf("op1=%lf, operation = %c ,  op2=%lf\n",op1,operation,op2);
        if(op1 == 0 && op2 == 0)
        {
            fprintf(stderr,"---Invalid input!\n");
            return 1;
        }

        if(!((operation == '+') || (operation == '-')
        || (operation == '*') || (operation == '/')))
        {
            fprintf(stderr,"Invalid input!\n");
            return 1;
        }

        if(operation == '+')
            result = op1 + op2;
        else if(operation == '-')
            result = op1 - op2;
        else if(operation == '*')
            result = op1 * op2;
        else if(operation == '/')
            result = op1 / op2;
        
        printf("%0.2lf\n",result);
    }
    
    return 0;
}
