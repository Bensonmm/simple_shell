#include"shell.h"
/**
 * prompt- It Scans & Retrieves User Input Command.
 * @present: pointer to a list_paths struct representing the present path.
 * Return: control after scanning.
 */
char *prompt(list_paths *present)
{
	ssize_t read;
	size_t s = 0;
	char *control = NULL;

	write(STDOUT_FILENO, "(#cisfun$) ", 10);
	read = getline(&control, &s, stdin);

	if (read == EOF)
	{
	
		write(STDOUT_FILENO, "\n", 1);
		free_lists(present);
		free(control);
		exit(0);
	}
	
	if (read == 1 && control[0] == '\n')
	{
		free(control);
		return (NULL);
	}

	control[read - 1] = '\0';

	return (control);
}
