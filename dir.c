#include"shell.h"

/**
* directory_check - checks if a directory exists and is accessible
* @command_array:array
* @command_line_before:checks prompt
* @command: the name of the directory to check
* @argument_vector: checker
* @tally:combines the data together(grouping)
* 
* @rank_status:checks status
*
* Return: 1 if the directory exists and is accessible, else 0
*/
int checks_directory(char *command, char **argument_vector, int tally,
char **command_array, int *rank_status, char *command_line_before)
{
	struct stat st;

if (stat(command, &st) == 0)
{
	if (S_ISDIR(st.st_mode))
	{
		_error_print(argument_vector[0], tally, command_array[0], PERMISSION_DENIED);
		*rank_status = PERMISSION_DENIED;
		free_allc_mem(command_line_before, command_array);
		return (0);
	}
}
return (-1);
}
