#include "main.h"
/**
 * interactive_func - A function to check if our shell is interactive
 *
 * Return: 0 on success
 */
int interactive_func(void)
{
	if (isatty(STDIN_FILENO) == 1) /* isatty func to see if shell is interactive*/
		myshell_works(); /* lets check if our shell is interactive*/
	else
		myshell_isnot(); /* lets see if the shell is not interactive*/

	return (0);
}


#include "main.h"
/**
 * myshell_works - A function to print a prompt for the shell to work
 *
 * Return: void
 */
void myshell_works(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		write(STDOUT_FILENO, "kh$ ", 14);
		line = scan_line();
		args = divide_line(line);
		status = execute_args(args);

		if (status == -1)
		{
			free(line);
			free(args);
			break;
		}
		free(line);
		free(args);

	} while (status != -2);
}


#include "main.h"
/**
 * myshell_isnot - A function for non interactive shell
 *
 * Return: void
 */
void myshell_isnot(void)
{
	char *line;
	char **args;
	int status;

	do {
		line = get_strem();
		args = divide_line(line);
		status = execute_args(args);
		free(line);
		free(args);

		if (status >= 0 || status == -2)
			break;

	} while (status == -1);
