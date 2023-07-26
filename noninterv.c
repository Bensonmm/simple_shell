#include"shell.h"
/**
 * non_interactive_files_handlers - processes shell commands in file
 * @name_shell: name of shell to use
 * Return: pointer to char array with output
 * @data_name: name of file with shell commands
 *
 * Opens file, reads each line.
 * pointer to char array with output.
 */
char **non_interactive_files_handlers(char *data_name, char *name_shell)
{
	struct stat fileStat;
	char *text, **command_lines;
	size_t letters_read;
	int fd;


	if (stat(data_name, &fileStat) != -1)
	{
		if (S_ISREG(fileStat.st_mode))
		{
			fd = open(data_name, O_RDONLY);
			if (fd  == -1)
				exit(ERROR);
			if (fileStat.st_size == 0)
				exit(0);
			text = malloc((fileStat.st_size + 1) * sizeof(char));
			if (!text)
				return (NULL);
			letters_read = read(fd, text, fileStat.st_size);
			if ((int) letters_read == -1)
			{
				perror("reading error");
			}
			close(fd);
			text[letters_read - 1] = '\0';
			if (text)
				command_lines = textured_to_array(text);
			return (command_lines);
		}
		else
			exit(0);
	}
	else
	{
		cant_open_handler_erros(name_shell, 0, data_name);
		exit(127);
	}
	return (NULL);
}
