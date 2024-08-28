#include "myheader.h"

/**
 * cmd_exec - Execute a command
 * @cmd_args: The command with its arguments.
 * Return: 0 on success, -1 on failure.
 */
int cmd_exec(char *cmd_args)
{
	pid_t child_pid;
	int status;
	char *token, *args[MAX_USER_INPUT / 2 + 2];
	int arg_count = 0;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (child_pid == 0)
	{
		token = strtok(cmd_args, " ");

		while (token != NULL && arg_count < MAX_USER_INPUT / 2 + 1)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}

		args[arg_count] = NULL;

		childpro_exec(args[0], args);
	}
	else
	{
		wait(&status);
	}

	return (0);
}
