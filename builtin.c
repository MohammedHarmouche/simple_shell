#include "shell.h"

/**
    * exit -exit
    * @ptrs: structure containing all malloced memory
*/

void exit(shell_t *ptrs)
{
	unsigned int i;
	char *exit_string;

	exit_string = ptrs->input_token[1];
	if (exit_string != NULL || ptrs == NULL)
	{
		errno = 0;
		for (i = 0; exit_string[i] != '\0'; i++)
			errno = errno * 10 + (exit_string[i] - '0');
	}
	free_shell_t(ptrs);
	if (errno > 255)
		errno %= 256;
	exit(errno);
}

/**
    * print_environment - prints out the current environment
    * @ptrs: structure containing all malloced memory
*/

void print_environment(shell_t *ptrs)
{
	unsigned int i, x;
	char new_line = '\n';

	(void)ptrs;
	if (environ == NULL)
		return;
	for (i = 0; environ[i] != NULL; i++)
	{
		x = _strlen(environ[i]);
		if (x != 0)
		{
			write(STDOUT_FILENO, environ[i], x);
			write(STDOUT_FILENO, &new_line, 1);
		}
	}
	errno = 0;
}
