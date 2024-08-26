#include "myheader.h"

/**
 * error - print error message
 * @cmd: user command
 */
void error(char *cmd)
{
	char *err_msg1 = "Command '";
	char *err_msg2 = "' not found\n";

	int msg1_len = _strlen(err_msg1);
	int msg2_len = _strlen(err_msg2);
	int cmd_len = _strlen(cmd);

	write(STDERR_FILENO, err_msg1, msg1_len);
	write(STDERR_FILENO, cmd, cmd_len);
	write(STDERR_FILENO, err_msg2, msg2_len);

	exit(EXIT_FAILURE);
}
