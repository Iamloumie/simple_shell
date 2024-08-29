#include "myheader.h"

/**
 * main - Entry point of the shell program.
 * Return: Always returns 0.
 */
int main(void)
{
	char *user_input = NULL, *trimmed_input;
	size_t usrin_len = 0;
	ssize_t read_size;
	int result, loop = 1;

	while (loop)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Iamloumie@ALX$ ", 15);

		read_size = getline(&user_input, &usrin_len, stdin);
		if (read_size == -1)
		break;

		if (user_input[read_size - 1] == '\n')
			user_input[read_size - 1] = '\0';

		if (strcmp(user_input, "clear") == 0)
		{
			clear_screen();
			continue;
		}

		trimmed_input = _stmstr(user_input);
		if (*trimmed_input == '\0')
			continue;

		builtin_cmd(trimmed_input);

		if (_strncmp(trimmed_input, "cd", 2) == 0)
			ch_user_dir(_stmstr(trimmed_input + 2));
		else if (read_size > 1)
		{
			result = cmd_exec(trimmed_input);
			if (result == -1)
				break;
		}
	}
	free(user_input);
	return (0);
}
