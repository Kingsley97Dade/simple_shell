#include "main.h"

/**
 * _strlen - A C function to know the length of a string
 * @z: pointer to be used
 *
 * Return: 0 on sucess
 */

int _strlen(const char *z)
{
	const char *p = z;

	while (*p != '\0')
	{
		p++;
	}
	return (p - z);
}

/**
 * _strcmp - A function to compare two strings
 * @fs: First string to be used
 * @ss: Secong string to be used
 *
 * Return: change of both
 */

int _strcmp(char *fs, char *ss)
{
	while (*fs != '\0' && (*fs == *ss))
	{
		fs++;
		ss++;
	}
	return (*fs - *ss);
}
