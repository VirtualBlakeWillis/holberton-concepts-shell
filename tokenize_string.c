#include "main.h"
/**
 * tokenize_string - 
 * 
 * @str:
 * Return: 
 */

char *tokenize_string(char *str)
{
        char *arg;
        int i = 0;
        arg = strtok(str, " ");

        while (arg != NULL)
        {
                arg = strtok(NULL, " \0");
                i++;
        }
}
