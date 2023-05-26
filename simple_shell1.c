#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

/**
 * Simple UNIX command line interpreter.
 *
 * This program acts as a simple shell, interpreting 
 * one-word commands and executing them using execvp.
 * The shell displays a prompt, waits for the user 
 * to enter a command, executes the command, and then
 * displays the prompt again.
 *
 * If an executable cannot be found, it prints 
 * an error message and displays the prompt again.
 * The shell handles the "end of file" condition (Ctrl+D).
 *
 * @return 0 on successful execution.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("simple_shell$");
		fflush(stdout);

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		pid_t pid = fork();

		if (pid == -1)

		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execlp(command, command, NULL);

			perror("exec");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);

		}
	}
	return (0);
}
