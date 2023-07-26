#include "shell.h"

/**
 * builtin_cmmd_handler - Handles Built-in commands in the Shell.
 * @present: A pointer to a list_paths struct representing the present path.
 * @shell_name: The name of the shell.
 * @rank_status: A pointer to an integer variable to set the rank_status.
 * @command: Original Comnd entered by the user.
 * @command_array: An array of strings containing the parsed command.
 * @argv:.Argument vector
 * @count: The count of the commands entered in the shell.
 * @env_list:.enviroments lists 
 * @command_lines:. command line in shell
 * Return: The function returns 0 on successful execution of a built-in command
 * -1 if the command is not a built-in command,
 * or an error occurs.
 */
int builtin_cmmd_handler(char *command, char **command_array, list_paths *present,
char *shell_name, int count, int *rank_status,
list_paths *env_list, char **command_lines, char **argv)
{
	int i, n;
	char *built_in[] = {"env", "exit", "cd", "setenv"};

	n = -1;

	for (i = 0; i < 4; i++)
	{
		if (_cmpstr(built_in[i], command_array[0]) == 0)
		{
			n = i;
			break;
		}
	}

	if (n == -1)
		return (n);


	switch (n)
	{
		case 0:
			_env_prints(rank_status);
			break;
		case 1:
			exits_handler_(command, command_array,
			present, shell_name, count, rank_status, env_list, command_lines);
			break;
		case 2:
			custom_cd_dir(command_array, argv);
			break;
		case 3:
			_setenv_custom(command_array[1], command_array[2], present);
			break;
		default:
			return (-1);
	}
	return (0);
}


