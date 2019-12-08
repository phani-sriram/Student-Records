#include<stdio.h>
#include<string.h>
/**
 * Finds, first index of a word in given file. First index is represented
 * using line and column.
 */
#define BUFFER_SIZE 10   // size of string

int indexOf(FILE *fptr, const char *word, int *line, int *col)
{
    char str[BUFFER_SIZE];
    char *pos;

    *line = 0;
    *col  = -1;

     while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        *line += 1;

        // Find first occurrence of word in str
        pos = strstr(str, word);

        if (pos != NULL)
        {
            // First index of word in str is 
            // Memory address of pos - memory
            // address of str.
            *col = (pos - str);
            break;
        }
    }
    // If word is not found then set line to -1
    if (*col == -1)
        *line = 0;
   return *col;
}