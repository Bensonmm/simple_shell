#include "shell.h"

/**
* _string_len - returns the length of a string
* @s: a pointer to the string
*
* This function takes a pointer to a
* string and counts the number of characters
* in the string using a loop. It returns the length of
* the string as an integer.
*
* Return: the length of the string as an integer.
*/
int _string_len(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
* _strup_mem - Returns a pointer to a newly allocated space in memory,
* which contains a copy of the string given as a parameter.
* @str: The string to duplicate
* Return: If str is NULL or if malloc() fails - NULL
*/
char *_strup_mem(char *str)
{
	int len;
	char *arr;

	if (str == NULL)
		return (NULL);
	len = _string_len(str);
	arr = malloc((sizeof(char) * len) + 1);
	if (arr == NULL)
		return (NULL);
	arr[len] = '\0';
	while (len--)
		arr[len] = str[len];
	return (arr);
}

/**
* _cmpstr - Compares two strings.
*
* @s1: Pointer to the first string to be compared.
* @s2: Pointer to the second string to be compared.
*
* Return: An integer less than, equal to, or greater than zero
*/
int _cmpstr(char *s1, char *s2)
{
		while (*s1 && *s2 && *s1 == *s2)
		{
			if (*s1 != *s2)
			{
				return ((int)*s1 - (int)*s2);
			}
			s1++;
			s2++;
		}

	return ((int)*s1 - (int)*s2);
}
/**
 * _cpy_str - copies a string
 *
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string
 */
char *_cpy_str(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _concat_array - concats two arrays
 *
 * @dest: destination of concat
 * @src: source array to concat
 * Return: a pointer to the resulting string dest
 */
char *_concat_array(char *dest, char *src)
{
	int len, i;

	len = _string_len(dest);
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}
