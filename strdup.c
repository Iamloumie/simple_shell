#include "myheader.h"

/**
 * _strdup - Duplicate a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if allocation fails.
 */
char *_strdup(const char *str)
{
	/* The duplicate string*/
	char *dup;
	size_t len;

	if (str == NULL)
		return (NULL);

	len = _strlenc(str);
	dup = (char *)malloc(len + 1);

	if (dup == NULL)
		return (NULL);

	strcpy(dup, str);
	return (dup);
}
