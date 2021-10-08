#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int calculate_readability(string text);

int main (void)
{
    // getting input from the user
    string text = get_string("Text: ");

    // function call
    int grade = calculate_readability(text);

    // if else for printing "before grade 1" and "grade 16+"
    if (grade < 2)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int calculate_readability(string text)
{
    // variable for no of letters
    int no_letters = 0;

    // variable for no of words (it is declared as 1 because theres one more word than the no of spaces)
    int no_words = 1;

    // variable for no of sentences
    int no_sentences = 0;

    // for loop for iterating every character of the text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // updating no of letters
        if (isalpha(text[i]))
        {
            no_letters++;
        }

        // updating no of words
        else if (text[i] == ' ')
        {
            no_words++;
        }

        // updating no of sentences
        else if (text[i] == '.' | text[i] == '!' | text[i] == '?')
        {
            no_sentences++;
        }
    }

    // Calculating no of letters and no of sentences per 100 words
    float L = 100 * (float) no_letters / (float) no_words;
    float S = 100 * (float) no_sentences / (float) no_words;

    // calculating index using  Coleman-Liau index formula
    float  index  = (0.0588 * L) - (0.296 * S) - 15.8;
    int round_index = round(index);

    // returning the grade of the text
    return round_index;
}
