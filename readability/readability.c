#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
    // Get input text from user
    string text = get_string("Text: ");

    // Count number of letters
    int i;
    int len;
    int letters = 0;

    for (i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            letters += 1;
        }
    }

    // Count number of words
    int words = 1;

    for (i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            words += 1;
        }
    }

    // Count number of sentences
    int sentences = 0;

    for (i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
    }

    // Calculate index


    float subindex = 0.0588 * 100 * letters / words - 0.296 * 100 * sentences / words - 15.8;

    int index = round(subindex);

    // Print grade

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 1 && index < 16)
    {
        printf("Grade %d\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }


}




