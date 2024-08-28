#include "myheader.h"

/**
 * ch_user_dir - changes user current directory
 * @filepath: incoming file path string
 */
void ch_user_dir(char *filepath)
{
	char *dest_dir;

	if (!filepath || *filepath == '\0')
	{
		filepath = getenv("HOME");
	}
	else if (_strcmp(filepath, "-") == 0)
	{
		filepath = getenv("OLDPWD");
	}

	if (chdir(filepath) != 0)
	{
		perror("chdir");
		return;
	}

	dest_dir = getcwd(NULL, 0);

	if (dest_dir != NULL)
	{
		setenv("PWD", dest_dir, 1);
		free(dest_dir);
	}
	else
	{
		perror("UNABLE TO CHANGE DIRECTORY: FAILED");
	}
}
