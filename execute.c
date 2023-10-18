#include "main.h"


/**
 * execute_args - A function to excute a programs
 * @args: arugumrnts it takes
 *
 * Return: 0 on fail otherwsie 1 on sucess
 */

int execute_args(char **args)
{
	char *builtin_func_list[] = {
		"env",
		"exit",
	};

	int (*builtin_func[])(char **) = {
		/*&my_cd,*/
		&my_env,
		&my_exit,
	};
	size_t x = 0;

	if (args[0] == NULL)
		return (-1);
	for (; x < sizeof(builtin_func_list) / sizeof(char *); x++)
	{
		if (_strcmp(args[0], builtin_func_list[x]) == 0)
		{
			return ((*builtin_func[x])(args));
		}
	}
	if (_strcmp(args[0], "exit") == 0)
	{
		return (my_exit(args));
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		return (my_env(args));
	}

	return (create_process(args));
}
