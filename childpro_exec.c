#include "myheader.h"

/**
 * childpro_exec - the execution of child process with its full path
 * @cmd: incoming user command
 * @args: incoming command arguments
 */
void childpro_exec(char *cmd, char *args[])
{
	char *filepath = path_finder(cmd);

	if (filepath == NULL)
	{
		if (access(cmd, X_OK) == 0)
		{
			filepath = cmd;
		}
		else
		{
			error(cmd);
			exit(EXIT_FAILURE);
		}
	}
	if (execve(filepath, args, NULL) == -1)
	{
		perror("execve");
	}

	free(filepath);
	exit(EXIT_FAILURE);
}

