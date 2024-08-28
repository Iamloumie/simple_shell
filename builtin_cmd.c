#include "myheader.h"

int builtin_cmd(char *user_input)
{
    if (_strcmp(user_input, "clear") == 0)
    {
        clear_screen();
        return 0;
    }
    if (_strncmp(user_input, "exit", 4) == 0)
    {
        char *status_str = user_input + 4;
        while (*status_str && isspace(*status_str))
            status_str++;
        
        if (*status_str)
        {
            int status = atoi(status_str);
            exit(status);
        }
        else
        {
            exit(EXIT_SUCCESS);
        }
    }
    if (_strcmp(user_input, "env") == 0)
    {
        print_env_var();
        return 0;
    }
    if (_strncmp(user_input, "cd", 2) == 0)
    {
        char *filepath = _stmstr(user_input + 2);
        ch_user_dir(filepath);
        return 0;
    }
    return 1;
}
