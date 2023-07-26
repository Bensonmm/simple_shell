#include "shell.h"

/**
 * linkedlist_to_paths -Function that returns a Linked list of path
 * Tokenized from path enviroment variable (PEV).
 * Return: a linked list, which contains the path extracted
 * from the "PATH" environment variable.
*/
list_paths *linkedlist_to_paths()
{
	list_paths *linkedlists_paths;
	char *variable_copied, *path_variable, *item_token;

	linkedlists_paths = NULL;


	path_variable = _getenv_var("PATH");
	if (path_variable == NULL)
		return (NULL);

	variable_copied = _strup_mem(path_variable);
	if (variable_copied == NULL)
		return (NULL);

	item_token = strtok(variable_copied, ":");
	while (item_token != NULL)
	{
		
		adds_node(&linkedlists_paths, item_token);
		
		item_token = strtok(NULL, ":");
	}
	free(variable_copied);

	return (linkedlists_paths);
}

/**
 * adds_node - a function that adds a new node at the beginning of a list_t list
  * @path: pointer to path.
 * @heads: pointer to the heads of list with the type list_paths

 * Return: the address of the new element, or NULL if it failed
*/

list_paths *adds_node(list_paths **heads, char *path)
{
	list_paths *new;
	int i = 0;
	char *strings_paths;



	while (path[i] != '\0')
	{
		i++;
	}

	new = malloc(sizeof(list_paths));

	if (new == NULL)
		return (NULL);

	if (path)
	{
	
	strings_paths = _strup_mem(path);
	if (strings_paths == NULL)
	{
		free(new);
		return (NULL);
	}

	new->len = i;
	new->path = strings_paths;
	}
	else
	{
		new->len = 0;
		new->path = NULL;
	}
	
	new->next = (*heads);

	*heads = new;
	return (new);
}

/**
* free_lists - Frees a singly linked list
* @heads: Pointer to the heads of the list
*/
void free_lists(list_paths *heads)
{
	list_paths *ptr = heads;
	list_paths *next_Nodes;

	while (ptr != NULL)
	{
		next_Nodes = ptr->next;
		free(ptr->path);
		free(ptr);
	
		ptr = next_Nodes;
	}

}

/**
 * prints_lists - prints all the elements of a list_paths list
 * If str is NULL, print [0] (nil)
 * @h: pointer to the heads of list with the type list_paths
 * Return: the number of nodes
*/
size_t prints_lists(const list_paths *h)
{
	int tally;

	if (h == NULL)
	{
		return (0);
	}
	tally = 0;
	while (h)
	{
		if (h->path == NULL)
		{
			printf("[0] (nil)\n");
			fflush(stdout);
		}
		else
		{
			printf("[%d] %s\n", h->len, h->path);
			fflush(stdout);
		}
		h = h->next;
		tally++;
	}
	return (tally);
}
