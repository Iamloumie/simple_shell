#include "myheader.h"

/**
 * builtin_cmd - checks the program for builtin command functions
 * @user_input: incoming user input
 */
void builtin_cmd(char *user_input)
{
	size_t input_size = 0;

	if (strcmp(user_input, "clear") == 0)
	{
		clear_screen();
	}

	if (_strncmp(user_input, "exit", 4) == 0)
	{
		free(user_input);
		user_input = NULL;
		input_size = 0;
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(_stmstr(user_input), "env") == 0)
	{
		print_env_var();
	}
	(void)input_size;
}
