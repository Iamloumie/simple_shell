#include "myheader.h"

void ch_user_dir(char *filepath)
{
    char *dest_dir;
    char *old_pwd = getenv("PWD");

    if (!filepath || *filepath == '\0')
    {
        filepath = getenv("HOME");
    }
    else if (_strcmp(filepath, "-") == 0)
    {
        filepath = getenv("OLDPWD");
        if (filepath)
            printf("%s\n", filepath);
    }

    if (chdir(filepath) != 0)
    {
        perror("chdir");
        return;
    }

    dest_dir = getcwd(NULL, 0);
    if (dest_dir != NULL)
    {
        setenv("OLDPWD", old_pwd, 1);
        setenv("PWD", dest_dir, 1);
        free(dest_dir);
    }
    else
    {
        perror("UNABLE TO CHANGE DIRECTORY: FAILED");
    }
}
