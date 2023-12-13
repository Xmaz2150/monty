#include "monty.h"

/**
 * *str_concat - returns pointer to new string containing :
 * @s1: Input and
 * @s2: Input
 *
 * Return: char
 */
char *str_concat(char *s1, char *s2)
{
	int lengths1 = 0;
	int lengths2 = 0;
	char *new_str;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		*s1 = '\0';
	}
	if (s2 == NULL)
	{
		s2 = malloc(sizeof(char));
		if (s2 == NULL)
			return (NULL);
		*s2 = '\0';
	}

	lengths1 = strlen(s1);
	lengths2 = strlen(s2);

	new_str = malloc(sizeof(char) * (lengths1 + lengths2 + 1));
	if (new_str == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}

	return (str_concat_helper(new_str, s1, s2));
}

/**
 * str_concat_helper - concats two strings
 * @new_str: Input, new memory space for strs the strings
 * @s1: Input, str 1
 * @s2: Input, str 2
 *
 * Return: cont str
 */

char *str_concat_helper(char *new_str, char *s1, char *s2)
{
	int n_str_counter = 0;
	int str_counter = 0;

	while (*(s1 + str_counter) != '\0')
	{
		*(new_str + n_str_counter) = *(s1 + str_counter);
		n_str_counter++;
		str_counter++;
	}

	str_counter = 0;
	while (*(s2 + str_counter) != '\0')
	{
		*(new_str + n_str_counter) = *(s2 + str_counter);
		n_str_counter++;
		str_counter++;
	}
	*(new_str + n_str_counter) = '\0';
	return (new_str);
}

