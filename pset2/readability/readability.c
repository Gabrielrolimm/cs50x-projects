#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// declare functions of the code
int cletters(string text);
int cwords(string text);
int csentences(string text);

// main function of the code
int main(void)
{
    // prompt for text
    string text = get_string("Insert text to evaluate grade level: ");

    // count letters, words and sentences
    int letters = cletters(text);
    int words = cwords(text);
    int sentences = csentences(text);

    // Coleman-Liau Index algorithm
    float L = (float) letters / (float) words * 100;

    float S = (float) sentences / (float) words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // output the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// function to count the amount of letters in the text
int cletters(string text)
{
    int carat = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            carat++;
        }
    }
    return carat;
}
// function to count the amount of words in the text
int cwords(string text)
{
    int aword = 1;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isblank(text[i]))
        {
            aword++;
        }
    }
    return aword;
}

// function to count the amount of sentences in the text
int csentences(string text)
{
    int asen = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            asen++;
        }
    }
    return asen;
}
