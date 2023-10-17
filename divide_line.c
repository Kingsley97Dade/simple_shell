#include "main.h"

/**
 * divide_line - A function to divide a string
 * @line: string to be utilised
 *
 * Return: pointer to a new element
 */

char **divide_line(char *line)
{
	int bufsize = 64;
	int x = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("error in allocation memory");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		token[x] = strdup(token);
		x++;

		if (x >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("error in reallocation memeory");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	token[x] = NULL;
	return (tokens);
}


/**
 * *strdup - A function to duplicate a string
 *
 * @str: string to be used
 *
 * Return: new string
 */

char *strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *new_str = (char *)malloc(len);

	if (new_str == NULL)
	{
		return (NULL);
	}

	strcpy(new_str, str);

	return (new_str);
}

/**
 * strcpy - copies a source string to a destination string
 * @dest: the destination string
 * @src: the source string
 *
 * Return: pointer to the beginning of the 'dest' string
 */

char *strcpy(char *dest, const char *src)
{
	char *origin_dest = dest;

	while ((*dest++ = *src++) != '\0')
		;
	return (origin_dest);
}
