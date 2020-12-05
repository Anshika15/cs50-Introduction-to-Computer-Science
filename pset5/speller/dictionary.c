// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHTABLE_SIZE 1000

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

unsigned int num = 0;
bool isloaded = false;

// Hash table
node *table[HASHTABLE_SIZE];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    char check_word[strlen(word)];
    strcpy(check_word, word);
    for (int i = 0; i < check_word[i] != '\0'; i++)
    {
        check_word[i] = tolower(check_word[i]);
    }
    int index = hash(check_word);
    if (table[index] != NULL)
    {
        for (node * nodeptr = table[index]; nodeptr != NULL; nodeptr = nodeptr -> next)
            if (strcmp(nodeptr->word, check_word) == 0)
            {
                return true;
            }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int hash1 = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            n = word[i] - 'a' + 1;
        }
        else
        {
            n = 27;
        }

        hash1 = ((hash1 << 3) + n) % HASHTABLE_SIZE;
    }
    return hash1;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *infile = fopen(dictionary, "r");
    if (infile == NULL)
    {
        return false;
    }

    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        table[i] = NULL;
    }

    char word[LENGTH + 1];
    node *newnodeptr;
    while (fscanf(infile, "%s", word) != EOF)
    {
        num++;
        do
        {
            newnodeptr = malloc(sizeof(node));
            if (newnodeptr == NULL)
            {
                free(newnodeptr);
            }

        }
        while (newnodeptr == NULL);

        strcpy(newnodeptr->word, word);
        int index = hash(word);
        newnodeptr->next = table[index];
        table[index] = newnodeptr;
    }
    fclose(infile);
    isloaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (!isloaded)
    {
        return 0;
    }
    return num;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    if (!isloaded)
    {
        return false;
    }

    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        if(table[i] != NULL)
        {
            node *ptr = table[i];
            while (ptr != NULL)
            {
                node *preptr = table[i];
                ptr = ptr->next;
                free(preptr);
            }
        }
    }
    return true;
}
