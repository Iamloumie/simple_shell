#include "myheader.h"

/**
 * _stmstr- Trim leading and trailing whitespaces from a string.
 * @str: The input string.
 *
 * Return: A pointer to the trimmed string.
 */
char *_stmstr(char *str)
{
	char *end;

	if (str == NULL)
		return (NULL);

	while (isspace(*str))
		str++;

	if (*str == '\0')
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && isspace(*end))
		end--;

	*(end + 1) = '\0';

	return (str);
}
