#include <cs50.h>
#include <stdio.h>

// getting input from user
int get_height(void)
{
    int n;
    do
    {
        n = get_int("Positive Integer: ");
    }
    while (n < 1 || n > 8);
    return n;
}

// main program
int main(void)
{
    // Function call
    int h = get_height();

    // defining k (that is used later for printing)
    int k = h - 1;

    //outer loop starts
    for (int i = 0; i < h; i++)
    {
        // loop for printing spaces
        for (int j = 0; j < k; j++)
        {
            printf(" ");
        }

        // decrementing k after each loop
        k = k - 1;

        // loop for printing first set of hastags
        for (int J = 0; J < i + 1; J++)
        {
            printf("#");
        }

        // space between first and second set of hastags
        printf("  ");

        // loop for printing second set of hastags
        for (int K = 0; K < i + 1; K++)
        {
            printf("#");
        }

        // moving to next line after a line is printe
        printf("\n");
    }
}
