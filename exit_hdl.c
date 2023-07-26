#include"shell.h"
/**
 * is_exit - Checks if the command is an "exit" command and handles it.
* @shell_name: The name of the shell program.
 * @status: A pointer to an integer variable representing the status.
 * @command: The original command entered by the user.
 * @command_array: An array of strings containing the command and its arguments
 * @present: A pointer to a list_paths struct representing the present path.
 * @tally: The command tally.
 * @command_lines:commands
 * @env:environment
 * Return:Nothing
 */

void exits_handler_(char *command, char **command_array, list_paths *present,
char *shell_name, int tally, int *status,
list_paths *env, char **command_lines)
{
	int exit_num;

	if (_cmpstr(command_array[0], "exit") == 0)
	{
		if (command_array[1] == NULL)
		{
			_frees_whole(command_lines, tally, env,
			present, command, command_array);
			exit(*status);
		}
		else if (command_array[1] != NULL)
		{
			if (_string_len(command_array[1]) <= 9)
			{
				exit_num = _atoi_str_int(command_array[1]);
				if (exit_num != -1)
				{
					_frees_whole(command_lines, tally, env,
					present, command, command_array);
					exit(exit_num);
				}
				else
				{
					*status = EXIT_ERROR;
					_error_print(shell_name, tally, command_array[1], EXIT_ERROR);
				}
			}
			else
			{
				*status = EXIT_ERROR;
				_error_print(shell_name, tally, command_array[1], EXIT_ERROR);
			}
		}
	}
}
/**
 * _frees_whole - free whole
 * @present: A pointer to a list_paths struct representing the present path.
 * @tally: The command tally.
 * @command_lines:. command lines 
 * @env:. envirmrnts variables
 * @command: The original command entered by the user.
 * @command_array: An array of strings containing the command and its arguments
 * Return: Nothing
*/
void _frees_whole(char **command_lines, int tally, list_paths *env,
		list_paths *present, char *command, char **command_array)
{
	if (command_lines)
	{
		free(command_lines[tally]);
		if (command_lines)
			free(command_lines);
	}
	free_lists(env);
	free_lists(present);
	free_allc_mem(command, command_array);
}
