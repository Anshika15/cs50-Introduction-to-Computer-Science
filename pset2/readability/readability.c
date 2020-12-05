#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string str = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sen = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            letters++;
        }

        if (str[i] == ' ')
        {
            words++;
        }
        if (str[i] == '.' || str[i] == '?' || str[i] == '!')
        {
            sen++;
        }
    }

    float L = ((float)letters / (float)words) * 100;
    float S = ((float)sen / (float)words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    int ind = round(index);
    if( ind < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (ind >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.f\n", round(index));
    }


}