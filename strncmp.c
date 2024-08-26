#include "myheader.h"

/**
 * _strncmp - Compare the first n characters of two strings.
 * @str1: The first string.
 * @str2: The second string.
 * @num: The number of characters to compare.
 *
 * Return:
 *   - 0 if the first n characters of the strings are equal.
 *   - A negative value if s1 is less than s2.
 *   - A positive value if s1 is greater than s2.
 */
int _strncmp(const char *str1, const char *str2, size_t num)
{
	while (num && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		num--;
	}

	if (num == 0)
		return (0);

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
