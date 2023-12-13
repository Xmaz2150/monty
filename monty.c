#include "monty.h"

/**
 * main - entry point
 * @ac: fnput, argument count
 * @av: Input, argument vector
 *
 * Return: (0) Success
 */

int main(int ac, char **av)
{
	FILE *file;
	int c, bytes, i;
	char *sample;
	stack_t *my_stack;
	node_st *raw_codes;

	file = NULL;
	my_stack = NULL;
	(void)av;
	if (ac != 2)
	{
		print_err("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
		return (1);
	bytes = 0;
	while ((c = fgetc(file)) != EOF)
		bytes++;
	sample = malloc(bytes + 1);
	if (sample == NULL)
		return (2);
	fseek(file, 0, SEEK_SET);
	i = 0;
	while ((c = fgetc(file)) != EOF)
	{
		sample[i] = c;
		i++;
	}
	sample[i] = '\n';
	fclose(file);
	raw_codes = create_input_list(sample, TOKKEN_DELIMS);
	_execute(raw_codes, &my_stack);

	free(sample);
	free_input_list(raw_codes);
	free_stack_list(my_stack);
	return (0);
}

/**
 * _execute - executes codes
 * @raw_codes: Input, all instructions
 * @my_stack: Input, stack
 *
 * Return: none
 */
void _execute(node_st *raw_codes, stack_t **my_stack)
{
	node_st *tmp;
	unsigned int n;

	tmp = raw_codes;
	while (tmp != NULL)
	{
		if (strcmp(tmp->word, "push") == 0)
		{
			n = atoi(tmp->next->word);
			my_push(my_stack, n);
		}
		else
		{
			if (is_code(tmp->word, my_stack) != 0)
			{
				if (!atoi(tmp->word))
					print_err(str_concat("L2: unknown instruction ", tmp->word));
			}
		}
		tmp = tmp->next;
	}
}

/**
 * is_code - checks if str is valid code
 * @str: Input, str to check
 * @my_stack: Input, stack
 *
 * Return: status
 */
int is_code(char *str, stack_t **my_stack)
{
	int i;
	instruction_t codes[] = {
		{"pall", my_pall},
		{"pint", my_pint},
		{"pop", my_pop},
		{"swap", my_swap},
		{"add", my_add},
		{"nop", my_nop},
		{NULL, NULL}
	};

	i = 0;
	while (codes[i].opcode != NULL)
	{
		if (strcmp(str, codes[i].opcode) == 0)
		{
			codes[i].f(my_stack, 0);
			return (0);
		}
		i++;
	}
	return (-1);
}
