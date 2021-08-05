// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <stddef.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int word_count = 0;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //Hash word to obtain a hash value

    int key = hash(word);

    //Access linked list at that index in the hash table
    //Traverse link list, looking for the word (strcasecmp)
    node *cursor = table[key];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)

        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int value = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        value += tolower(word[i]);
    }
    return value % N;
 
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //Open the dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    //Read strings from file one at a time
    char temp_word[LENGTH + 1];

    while (fscanf(file, "%s", temp_word) != EOF)
    {
        //Create a new node for each word
        node *new_node = malloc(sizeof(node));
        strcpy(new_node->word, temp_word);

        //Hash word to obtain a hash value
        int key = hash(temp_word);


        //Insert node into hash table at that location
        if (table[key] == NULL)
        {
            new_node->next = NULL;
            table[key] = new_node;
        }
        else
        {
            new_node->next = table[key];
            table[key] = new_node;
        }
        word_count++;

    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        table[i] = NULL;

    }
    return true;
}
