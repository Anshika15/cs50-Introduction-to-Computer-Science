#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {

        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!(isdigit(argv[1][i])))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        int val = atoi(argv[1]);

        string str = get_string("plaintext: ");

        printf("ciphertext: ");

        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                printf("%c", ((str[i] + val - 'a') % 26) + 'a');
            }

            else if (str[i] >= 'A' && str[i] <= 'Z')
            {
                printf("%c", ((str[i] + val - 'A') % 26) + 'A');
            }

            else
            {
                printf("%c", str[i]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}