#include "myheader.h"

/**
 * clear_screen - Clear the console screen
 *
 * This function uses ANSI escape sequences to clear the screen and
 * move the cursor to the top-left corner. If that fails, it prints
 * newlines to create a visual separation.
 */
void clear_screen(void)
{
	const char *CLEAR_SCREEN_ANSI = "\033[2J\033[H";

	/* Attempt to use ANSI escape sequence */
	if (write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 7) != 7)
	{
		/* If ANSI escape sequence fails, print newlines */
		int i;

		for (i = 0; i < 100; i++)
		{
			write(STDOUT_FILENO, "\n", 1);
		}
	}

	/* Flush the output */
	fflush(stdout);
}
