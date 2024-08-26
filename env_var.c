#include "myheader.h"

/**
 * print_env_var - prints all variables with its values
 */
void print_env_var(void)
{
	char **env_var;

	if (environ == NULL)
	{
		write(STDOUT_FILENO, "Environment variables are not set.\n", 36);
		return;
	}
	for (env_var = environ; env_var != NULL; env_var++)
	{
		int env_len = _strlen(*env_var);

		write(STDOUT_FILENO, *env_var, env_len);
		write(STDOUT_FILENO, "\n", 1);
	}
}
