#include"shell.h"

/**
 * _env_prints - Prints the Environment variables.
 * @rank_status: Pointer to an integer variable to set the rank_status.
 * Each variable is printed on a separate line.
 * The 'rank_status' parameter is used to set the rank_status of the function.
 * Return:nothing
 */
void _env_prints(int *rank_status)
{
	int i;


	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _string_len(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	*rank_status = 0;
}
