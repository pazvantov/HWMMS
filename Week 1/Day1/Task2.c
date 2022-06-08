#include<stdio.h>
#include<math.h>

int main()
{
    float Volume;
    int choice;
    float R,L,H;
    
    printf("1.Izpraven\n2.Legnal\nChoose:");
    scanf("%d",&choice);

    if(choice == 1)
    {
        printf("R = ");
        scanf("%f",&R);
        printf("H = ");
        scanf("%f",&H);
        Volume = 3.14 * pow(R,2) * H;
    }
    else
    {
        printf("R = ");
        scanf("%f",&R);
        printf("L = ");
        scanf("%f",&L);
        printf("H = ");
        scanf("%f",&H);
        Volume = L * ((pow(cos((R-H)/R),-1)*pow(R,2))-((R-H)*sqrt(2*R*H-pow(H,2))));
    }
    printf("Volume : %f",Volume);

    return 0;
}