#include "myheader.h"

/**
 * _strlen - finds the length of a string.
 * @str: incoming string
 * Return: string length
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
		;
	return (i);
}

/**
 * _strlenc - finds length of a string but for constant characters
 * @str: incoming string
 * Return: integer
 */
int _strlenc(const char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
		;
	return (i);
}
