#include "main.h"

/**
 * create_process - A function to create a new process
 * @args: array string flags
 *
 * Return: 1 on success, else 0
 */

int create_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args) == -1)
			perror("error in child process cretaion");
		eixt(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error in forking new process");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status))
	}

	return (-1);
}
