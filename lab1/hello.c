#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Getting the input from the user
    string name = get_string("What is your name? :");
    
    // Printing the input name
    printf("Hello, %s\n", name);
}
