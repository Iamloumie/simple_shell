#include "myheader.h"

void prompt_disp(void);

/**
 * main - Entry point of the shell program.
 * Return: Always returns 0.
 */
int main(void)
{
	char *filepath, *user_input = NULL;
	size_t usrin_len = 0;
	ssize_t read_size;
	int loop;
	int result;

	loop = 1;
	while (loop)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "Iamloumie@ALX$ ", 15);
			fflush(stdout);
		}
		read_size = _getline(&user_input, &usrin_len, stdin);
		if (read_size == -1)
		{
			free(user_input);
			return (0);
		}
		if (user_input[read_size - 1] == '\n')
			user_input[read_size - 1] = '\0';
		builtin_cmd(user_input);
		if (_strncmp(user_input, "cd", 2) == 0)
		{
			filepath = _stmstr(user_input + 2);
			ch_user_dir(filepath);
			free(user_input);
			user_input = NULL;
			usrin_len = 0;
		}
		if (read_size > 1)
		{
			result = cmd_exec(_stmstr(user_input));
			if (result == -1)
				break;
		}
	}
	free(user_input);
	return (0);
}
