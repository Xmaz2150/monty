#include "monty.h"

/**
 * str_to_int - convserts intto string
 * @str: Input, str to convert
 * @result: Input, addr of new it
 *
 * Return: status(0) persfect+
 */

int str_to_int(const char *str, int *result)
{
	int i;
	int new_int = atoi(str);

	if (new_int > 0)
	{
		printf("positive %s\n", str);
		*result = new_int;
		return (0);
	}
	else if (new_int < 0)
	{
		printf("negative %s\n", str);
		return (-1);
	}
	else
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			if (isdigit(str[i]))
			{
				printf("characters %s\n", str);
				return (1);
			}
		}
		*result = 0;
	return (1);
	}
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
