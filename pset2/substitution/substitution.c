#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string str = argv[1];
        if(strlen(str) != 26)
        {
            printf("Key must contain 26 characters.");
            return 1;
        }

        else
        {

        }
    }
    else
    {
        printf("Usage: ./substitution key");
        return 1;
    }
}