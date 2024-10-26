// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// TODO: Choose number of buckets in hash table
const unsigned int N = (('Z' - 'A') * ('Z' - 'A') * LENGTH);

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int key = hash(word);
    node *temp = table[key];
    while (temp != NULL)
    {
        if (strcasecmp(word, temp->word) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int len = strlen(word);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += (toupper(word[i]) - 'A') * (toupper(word[i]) - 'A');
    }
    return sum;
}

int counter = 0;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("could not open file: %s.\n", dictionary);
        return 1;
    }
    char word[LENGTH + 1];
    //int index = 0;
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        strcpy(n->word, word);
        unsigned int key = hash(word);
        if (table[key] == NULL)
        {
            n->next = NULL;
        }
        else
        {
            n->next = table[key];
        }
        table[key] = n;
        counter++;
    }

    if (ferror(file))
    {
        fclose(file);
        printf("error reading file: %s.\n", dictionary);
        unload();
        return false;
    }
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Unloads one linked list from memory
void unloadlist(node *n)
{

    if (n == NULL)
    {
        return;
    }
    else if (n->next != NULL)
    {
        unloadlist(n->next);
    }
    else if (n->next == NULL)
    {
        free(n);
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    return true;
}
