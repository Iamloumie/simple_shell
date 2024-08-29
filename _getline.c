#include "myheader.h"

#define INITIAL_BUFFER_SIZE 128
#define BUFFER_INCREMENT 128
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
	static char *buffer;
	static size_t buffer_size;
	int c;
	size_t pos = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		buffer = malloc(INITIAL_BUFFER_SIZE);
		if (buffer == NULL)
			return (-1);
		buffer_size = INITIAL_BUFFER_SIZE;
	}
	else
	{
		buffer = *lineptr;
		buffer_size = *n;
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (pos >= buffer_size - 1)
		{
			char *new_buffer = realloc(buffer, buffer_size + BUFFER_INCREMENT);
			if (new_buffer == NULL)
				return (-1);
			buffer = new_buffer;
			buffer_size += BUFFER_INCREMENT;
		}
		buffer[pos++] = c;
		if (c == '\n')
		break;
	}

	if (c == EOF && pos == 0)
		return (-1);

	buffer[pos] = '\0';
	*lineptr = buffer;
	*n = buffer_size;
	return (pos);
}
