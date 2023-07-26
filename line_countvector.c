#include "shell.h"
/**
 * _vector_to_lines - converts a string into an array of strings
 * 
 * @rank_status: an integer representing the rank_status of the command
 * @command: the string to convert
 
 * Return: a pointer to a char array.
 */
char **_vector_to_lines(char *command, int rank_status)
{
	char *copied_line, *token, **argument_vector, *variable, *cmde;
	int i = 0, character_tally;

	
	if (command[0] == '\0')
		return (NULL);
	copied_line = _strup_mem(command);
	if (copied_line == NULL)
		return (NULL); 
	character_tally = _chars_tally(copied_line, ' ');
	argument_vector = malloc((character_tally + 1) * sizeof(char *));
	token = _strtok(copied_line, TOK_D);

	cmde = handler_flags_(token, command, argument_vector, rank_status);
	argument_vector[i++] = cmde;
	while (token != NULL)
	{
		token = _strtok(NULL, TOK_D);
		if (token != NULL)
		{
			if (_cmpstr("$$", token) == 0)
				cmde = get_id_process();
			else if (_cmpstr("$?", token) == 0)
				cmde = gets_rank_status(rank_status);
			else if ((token[0] == '$') && (token[1]))
			{
				variable = _getenv_var(&token[1]);
				if (variable)
					cmde = _strup_mem(variable);
				else
					cmde = _strup_mem("");
			}
			else
				cmde = _strup_mem(token);
			argument_vector[i++] = cmde;
		}
	}
	argument_vector[i] = NULL;
	free(copied_line);
	return (argument_vector);
}
/**
 * handler_flags_ - .
 * @token:.tokens 
 * @command:.comands env
 * @argument_vector:.argurment 
 * @rank_status:. stataus 
 * Return:.
*/
char *handler_flags_(char *token, char *command,
char **argument_vector, int rank_status)
{
		char *variable, *cmde, *copied_line;

	copied_line = command;
		if (token == NULL)
	{
		free(argument_vector);
		free(copied_line);
		return (NULL);
	}
	if (_cmpstr("$$", token) == 0)
		cmde = get_id_process();
	else if (_cmpstr("$?", token) == 0)
		cmde = gets_rank_status(rank_status);
	else if ((token[0] == '$') && (token[1]))
	{
		variable = _getenv_var(&token[1]);
		if (variable)
			cmde = _strup_mem(variable);
		else
			cmde = _strup_mem("");
	}
	else
		cmde = _strup_mem(token);

	return (cmde);
}
