#include"shell.h"
/**
 * gets_rank_status - It gets the string representation of a rank_status value.
 * @n: The value of rank_status to convert to a string.
 * Return: A pointer to a string representing the rank_status value.
 */
char *gets_rank_status(int n)
{
	char *rank_status;


	rank_status = characters_to_numbers(n);

	
	return (rank_status);
}
