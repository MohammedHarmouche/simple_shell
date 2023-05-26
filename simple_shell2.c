#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CMD_LENGTH 100
#define MAX_ARGS 10

int parse_cmdline(char *cmdline, char *cmd, char **args)
{
        int argc = 0;
        char *token;

        token = strtok(cmdline, "\n");
        strncpy(cmd, token, MAX_CMD_LENGTH);
        cmd[MAX_CMD_LENGTH - 1] = '\0';

        while ((token = strtok(NULL, "\n")) != NULL && argc < MAX_ARGS)
        {
                args[argc++] = token;
        }
        args[argc] = NULL;

        return (argc);
}

int main(void)
{
        char cmdline[MAX_CMD_LENGTH];
        char cmd[MAX_CMD_LENGTH];
        char *args[MAX_ARGS + 1];

        while (1)
        {
                printf(" > ");
                fgets(cmdline, MAX_CMD_LENGTH, stdin);
                int argc = parse_cmdline(cmdline, cmd, args);

                if (strcmp(cmd, "exit") == 0)
                {
                        exit(0);
                }

                else if (strcmp(cmd, "cd") == 0)
                {
                        if (argc > 0)
                        {
                                chdir(args[0]);
                        }
                        else
                        {
                                fprintf(stderr, "cd: missing argument\n");
                        }
                }
                else
                {
                        pid_t pid = fork();

                        if (pid == 0)

                        {
                                execvp(cmd, args);
                                fprintf(stderr, "%s: command not found\n", char *);
                                exit(1);
                        }
                        else
                        {
                                wait(NULL);
                        }
                }
        }
        return (0);
}
