#include "shell.h"

/**
 * catscan_command_files - Scans command files based on the operation mode.
 * @_mode_op: The operation mode.
 * @data_name: The name of the command file.
 * @name_shell: The name of the shell program.
 * Return: The array of command lines read from the file.
 */
char **catscan_command_files(int _mode_op, char *data_name, char *name_shell)
{
	char **command_lines;

	if (_mode_op == NON_INTERACTIVE_PIPE)
	{
		command_lines = non_interactive_pipes_handlers();
		if (!command_lines)
			exit(0);
	}
	else if (_mode_op == NON_INTERACTIVE_MODE)
	{
		command_lines = non_interactive_files_handlers(data_name, name_shell);
		if (!command_lines)
			exit(0);
	}
	return (command_lines);
}



