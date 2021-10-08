#include <cs50.h>
#include <stdio.h>

// functions :
int get_start_size(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);
    {
        return n;
    }
}
int get_end_size(N)
{
    int n;
    do
    {
        n = get_int("End size:");
    }
    while (n < N);
    {
        return n;
    }
}

int main(void)
{
    // TODO: Prompt for start size
    int start_size = get_start_size();
    // TODO: Prompt for end size
    int end_size = get_end_size(start_size);

    // TODO: Calculate number of years until we reach threshold
    int year_count = 0;
    while (start_size < end_size)
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        year_count++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", year_count);
}
