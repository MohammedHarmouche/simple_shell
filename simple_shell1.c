#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_CMD_LEN 100

/**
 * The main: function serves as the entry point for the program.
 * It implements a simple UNIX command line interpreter (shell).
 * The shell displays a prompt, waits for the user to enter a command,
 * executes the command, and repeats the process until the user exits.
 *
 * @return (0)
 */

int main(void)
{
        char cmd[MAX_CMD_LEN];
        char *args[2] = {NULL};
        int status;

        pid_t pid;

        while (1)
        {
                printf("Myshell>");
                fgets(cmd, MAX_CMD_LEN, stdin);

                if (cmd[0] == '\n')
                {
                        continue;
                }

                cmd[strcspn(cmd, "\n")] = '\0';
                args[0] = cmd;

                pid = fork();

                if (pid < 0)
                {
                        perror("fork");
                        continue;
                }
                else if (pid == 0)
                {
                        execve(args[0], args, NULL);
                        perror("execve");
                        exit(EXIT_FAILURE);
                }

                else
                {
                        waitpid(pid, &status, 0);
                }
        }
        return (0);
}
