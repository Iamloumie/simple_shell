#include "myheader.h"

/**
 * _getline - Reads an entire line from a given stream into a buffer.
 *
 * @lineptr: Pointer to the buffer where the read line will be stored.
 *           If *lineptr is NULL, the function will allocate a new buffer.
 * @n:       Pointer to the size of the buffer. If the buffer is too small,
 *           it will be reallocated to fit the line.
 * @stream:  Pointer to the input stream from which the line is read.
 *
 * Return:   The number of characters read, excluding the null terminator,
 *           or -1 if an error occurs or the end of the file is reached.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *bufptr = NULL;
	char *p = bufptr;
	size_t size;
    int c;

	if (lineptr == NULL || stream == NULL || n == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	bufptr = *lineptr;
	size = *n;

	c = fgetc(stream);
	if (c == EOF)
		return (-1);
	if (bufptr == NULL)
	{
		bufptr = malloc(128);
		if (bufptr == NULL)
			return (-1);
		size = 128;
	}
	p = bufptr;
	while (c != EOF)
	{
		if ((size_t)(p - bufptr) > (size - 1))
		{
			size = size + 128;
			bufptr = realloc(bufptr, size);
			if (bufptr == NULL)
				return (-1);
		}
		*p++ = c;
		if (c == '\n')
		{
			break;
		}
		c = fgetc(stream);
	}

	*p++ = '\0';
	*lineptr = bufptr;
	*n = size;

    return (p - bufptr - 1);
}
