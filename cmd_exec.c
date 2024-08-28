#include "myheader.h"

int cmd_exec(char *cmd_args)
{
    pid_t child_pid;
    int status;
    char *token, *args[MAX_USER_INPUT / 2 + 2];
    int arg_count = 0;
    char *full_path;

    token = strtok(cmd_args, " ");
    while (token != NULL && arg_count < MAX_USER_INPUT / 2 + 1)
    {
        args[arg_count++] = token;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;

    full_path = path_finder(args[0]);
    if (full_path == NULL)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return 0;
    }

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        free(full_path);
        return -1;
    }
    if (child_pid == 0)
    {
        if (execve(full_path, args, environ) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }
    free(full_path);
    return 0;
}
