#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // if the user didn't specify the key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // if the key is less than or more than 26
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // for checking other conditions
    else
    {
        // iterating throungh each character of the key
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // if a character is a digit
            if (isdigit(argv[1][i]))
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }

            //declaring another iteration on n to check for repeated alphabeth
            for (int j = i + 1; j < n; j++)
            {
                //checking repeated alphabeth in argv[1]
                if (argv[1][i] == argv[1][j])
                {
                    printf("Key must not contain repeated alphabeth\n");
                    return 1;
                }
            }
        }
    }

    // getting input from the user and declaring len as the lenght of plaintext
    string plaintext = get_string("plaintext: ");
    int len = strlen(plaintext);

    // if the user didn't enter anything
    if (len < 1)
    {
        printf("plaintext should contain atleast one character\n");
        return 1;
    }
    else
    {
        // for format purpose
        printf("ciphertext: ");

        // iterating throungh each character of the plaintext
        for (int i = 0; i < len; i++)
        {
            // if the char is uppercase, printing the corresponding char in uppercase
            if (isupper(plaintext[i]))
            {
                printf("%c", toupper(argv[1][plaintext[i] - 'A']));
            }

            // if the char is lowercase, printing the corresponding char in lowercase
            else if (islower(plaintext[i]))
            {
                printf("%c", tolower(argv[1][plaintext[i] - 'a']));
            }

            // if the char is not a alphabet
            else
            {
                printf("%c", plaintext[i]);
            }
        }
    }
    // new line at the end
    printf("\n");
}
