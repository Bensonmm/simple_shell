#include"shell.h"
/**
* non_builtins_handlers - Handle non-builtin commands
* @tally: Number of commands executed
* @argv: Array of command-line arguments
* @command_array: Array of command arguments
* @env: Environment variables
* @rank_status: Pointer to the rank_status variable
*
* @present: Pointer to the list_paths structure
*
* This function handles non-builtin commands in the shell.
* by checking the access permission.
*/
void non_builtins_handlers(char **command_array, char *env[], int *rank_status,
						int tally, list_paths *present, char *argv[])
{
	char *new_path;

	if (access(command_array[0], X_OK) == 0)
		_executer_commands(command_array[0], command_array, env, rank_status);
	else
	{
	
		new_path = _checks_access(command_array[0], present);
		if (new_path)
		{
			_executer_commands(new_path, command_array, env, rank_status);
			free(new_path);
		}
		else
		{
			_error_print(argv[0], tally, command_array[0], NOT_FOUND);
			*rank_status = NOT_FOUND;
		}
	}
}
