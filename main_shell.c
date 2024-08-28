#include "myheader.h"

int main(void)
{
    char *user_input = NULL;
    size_t usrin_len = 0;
    ssize_t read_size;

    while (1)
    {
        prompt_disp();
        read_size = _getline(&user_input, &usrin_len, stdin);
        if (read_size == -1)
        {
            if (feof(stdin))
            {
                write(STDOUT_FILENO, "\n", 1);
                free(user_input);
                exit(EXIT_SUCCESS);
            }
            else
            {
                perror("_getline");
                free(user_input);
                exit(EXIT_FAILURE);
            }
        }

        if (user_input[read_size - 1] == '\n')
            user_input[read_size - 1] = '\0';

        if (_strlen(user_input) == 0)
            continue;

        if (builtin_cmd(user_input) == 0)
            continue;

        if (cmd_exec(user_input) == -1)
            break;
    }

    free(user_input);
    return 0;
}
