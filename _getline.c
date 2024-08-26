#include "myheader.h"
#define BUFFER_SIZE 1024

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
	static char buffer[BUFFER_SIZE];
	int position = 0, c;

	if (!lineptr || !n || !stream)
		return (-1);

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (position >= BUFFER_SIZE - 1)
		{
			fprintf(stderr, "Input too long, truncating.\n");
			while ((c = fgetc(stream)) != '\n' && c != EOF)
			;
			break;
		}
		buffer[position++] = c;
	}

	buffer[position] = '\0';

	if (position == 0 && c == EOF)
		return (-1);

	if (!*lineptr || *n < (size_t)(position + 1))
	{
		*n = position + 1;
		*lineptr = realloc(*lineptr, *n);
		if (!*lineptr)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
	}

	_strcpy(*lineptr, buffer);
	return ((ssize_t)position);
}
