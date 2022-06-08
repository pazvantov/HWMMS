#include<stdio.h>
#include<math.h>

int main()
{
    int choice;
    float mass,height,BMI;
    printf("Mass = ");
    scanf("%f",&mass);
    printf("Height = ");
    scanf("%f",&height);
    printf("1.Old Method\n2.New Method\nChoose:");
    scanf("%d",&choice);

    if(choice == 1)
        BMI = mass / pow(height,2);
    else
        BMI = 1.3*(mass / pow(height,2.5));
    
    printf("\nBMI : %f",BMI);
    return 0;
}