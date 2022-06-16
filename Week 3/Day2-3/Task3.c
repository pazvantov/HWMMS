#include<stdio.h>

void VMirror(unsigned char *pImage);

int main()
{
    unsigned char pic[9];
    char check;
    int i=0;
    int index = 0;
    while(scanf("%c",&check) != EOF)
    {
        if(check == '1' || check == '0')
        {
            if(check == '1')
            {
                pic[index] |= 1;
            }
            i++;
            if(i%8 == 0)
            {
                i = 0;
                index++;
            }
            else
                pic[index] = pic[index]<<1;
        }
        
    }
    for(int j=0;j<8;j++)
    {
        printf("%2x,",pic[j]);
    }
    putchar('\n');
    VMirror(pic);
    for(int j=0;j<8;j++)
    {
        printf("%2x,",pic[j]);
    }
    putchar('\n');
    return 0;
}

void VMirror(unsigned char *pImage)
{
    int i = 0;
    int check;
    while(pImage[i] != 0)
    {
        for(int j=0;j<4;j++)
        {
            check = !!(pImage[i] & (1<<7-j));
            if(!!(pImage[i] & (1<<j)))
                pImage[i] |= (1<<7-j);
            else
                pImage[i] &= ~(1<<7-j);

            if(check)
                pImage[i] |= (1<<j);
            else   
                pImage[i] &= ~(1<<j);
        }
        i++;
    }
}