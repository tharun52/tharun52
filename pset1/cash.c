#include <math.h>
#include <cs50.h>
#include <stdio.h>

//int convertion(N)


int main(void)
{
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);

    int change = 0;
    int dollar = (int)n;
    float dec = n-dollar;
    dec= round(dec*100);
    change = dollar*100;
    change += dec;

    int coin_count = 0;
    while (change >= 25)
    {
        change = change-25;
        coin_count += 1;
    }
    while (change >= 10)
    {
        change = change-10;
        coin_count += 1;
    }
    while (change >= 5)
    {
        change = change-5;
        coin_count += 1;
    }
    while (change >= 1)
    {
        change = change-1;
        coin_count += 1;
    }
    printf("%i\n",coin_count);
}
