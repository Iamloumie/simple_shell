#include "myheader.h"

/**
 * prompt_disp - Display the shell prompt "$".
 */
void prompt_disp(void)
{
	/* check if the input is from a terminal */
	if (isatty(STDIN_FILENO) == 1)
	{
		/* display the shell prompt*/
		write(STDOUT_FILENO, "$ ", 2);
		/* flush the output buffer */
		fflush(stdout);
	}
}
