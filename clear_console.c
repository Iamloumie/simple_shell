#include "myheader.h"

/**
 * clear_screen - ANSI escape sequence to clear screen
 * and move cursor to top-left corner
 */
void clear_screen(void)
{
	const char *CLEAR_SCREEN_ANSI = "\033[1;1H\033[2J";

	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 11);
}
