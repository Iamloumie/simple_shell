#include "myheader.h"

#define MAX_ARGS 64

/**
 * cmd_exec - Execute a command
 * @cmd_args: The command with its arguments.
 * Return: 0 on success, -1 on failure.
 */
int cmd_exec(char *cmd_args)
{
	pid_t child_pid;
	int status;
	char *token, *args[MAX_ARGS];
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
		while (token != NULL && arg_count < MAX_ARGS - 1)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		childpro_exec(args[0], args);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
