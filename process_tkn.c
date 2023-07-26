#include"shell.h"
/**
 * token_mapping - Processes a item_token and returns the corresponding string.
 * 
 * @rank_status: An integer representing the rank_status of the command.
 * @item_token: The input item_token to process.
 
 * Return: A dynamically allocated string representing the processed item_token.
 */
char *token_mapping(char *item_token, int rank_status)
{
	char *cmde, *variable;

	cmde = NULL;
	variable = NULL;

	if (_cmpstr("$$", item_token) == 0)
		cmde = get_id_process();
	else if (_cmpstr("$?", item_token) == 0)
		cmde = gets_rank_status(rank_status);
	else if (item_token[0] == '$' && item_token[1] != '\0')
	{
		variable = _getenv_var(&item_token[1]);
		cmde = (variable != NULL) ? _strup_mem(variable) : _strup_mem("");
	}
	else
		cmde = _strup_mem(item_token);
	return (cmde);
}
