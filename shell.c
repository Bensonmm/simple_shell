#include "shell.h"
/**
* main - Function that RUN SHELL PROGRAM,
* @argc: Argument Count.,
* @argv: Argument vector,
* @env: Shell Environment,
* Return: Exit Status of the Program,
*/
int main(int argc, char *argv[], char *env[])
{
	int *status, count = 0, non_interactive = 1, s = 0, op_mode;
	char *command, **command_lines, **cmd_arr = NULL;
	list_paths *present;

	status = &s;
	op_mode = checks_termnl_mode(argc);
	if (op_mode != INTERACTIVE_MODE)
	
	command_lines = catscan_command_files(op_mode, argv[1], argv[0]);
	present = linkedlist_to_paths();
	while (non_interactive && ++count)
	{
		if (op_mode == NON_INTERACTIVE_MODE || op_mode == NON_INTERACTIVE_PIPE)
		{
			if (command_lines[count - 1])
				command = command_lines[count - 1];
			else
			{
				free(command_lines);
				break;
			}
		}
		else if (op_mode == INTERACTIVE_MODE)
			command = prompt(present); /*prompt user&get command*/
		if (!command)
			continue;
		cmd_arr = _vector_to_lines(command, *status);
		if (!cmd_arr)
		{
			free(command);
			continue;
		}
		if (checks_directory(cmd_arr[0], argv, count, cmd_arr, status, command) == 0)
			continue;
		if (builtin_cmmd_handler(command, cmd_arr, present, argv[0],
			count, status, NULL, command_lines, argv) != 0)
			non_builtins_handlers(cmd_arr, env, status, count, present, argv);
		free_allc_mem(command, cmd_arr);
	}
	free_lists(present);
	exit(*status);
}

