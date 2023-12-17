#include "monty.h"

/**
 * str_to_int - convserts intto string
 * @str: Input, str to convert
 *
 * Return: int
 */

int str_to_int(const char *str)
{
	int i;
	int new_int;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-')
			continue;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
	}
	new_int = atoi(str);
	return (new_int);
}

/**
 * print_list - prints list
 * @head: Input, start of list
 */

void print_list(stack_t *head)
{
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
