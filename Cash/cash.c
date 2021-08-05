
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float k;

    do

    {
        k = get_float("Changed owed: ");
    }

    while (k<=0);

    int c;
    
    c = round(k*100);
    
    int i = 0;
    
    while (c>=25)
    {
        c -= 25;
        i++;
    }

    while (c>=10)
    {
        c -= 10;
        i++;
    }
    
    while (c>=5)
    {
        c -= 5;
        i++;
    }

    while (c>=1)
    {
        c -= 1;
        i++;
    }
  
    printf("Coins:%i\n", i);

}