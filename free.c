#include"shell.h"
/**
* free_allc_mem - Frees the allocated memory
* @command: Pointer to the command string
* @command_array: Pointer to the array of command and its arguments
*/
void free_allc_mem(char *command, char **command_array)
{
	free(command);
	free_mem_array(command_array);
}
