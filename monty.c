#include "monty.h"
#include "arr.h"

char *read_file(FILE *file);

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
	sample = read_file(file);

	fclose(file);
	raw_codes = create_input_list(sample, TOKKEN_DELIMS);
	lines = create_iL_arr(raw_codes);
	_execute(&my_stack);

	free(sample);
	free_input_list(raw_codes);
	free_stack_list(my_stack);
	free_iL_arr();
	return (0);
}

/**
 * read_file - reads all char in:
 * @file: Input, file
 *
 * Return: char(s) read
 */
char *read_file(FILE *file)
{
	char *sample;
	int c, bytes, i;

	bytes = 0;
	while ((c = fgetc(file)) != EOF)
		bytes++;
	sample = malloc(bytes + 1);
	if (sample == NULL)
		return (NULL);
	fseek(file, 0, SEEK_SET);
	i = 0;
	while ((c = fgetc(file)) != EOF)
	{
		sample[i] = c;
		i++;
	}
	sample[i] = '\n';
	return (sample);
}

/**
 * _execute - executes codes
 * @my_stack: Input, stack
 *
 * Return: none
 */
void _execute(stack_t **my_stack)
{
	char ***tmp;
	unsigned int n;

	n = 0;
	tmp = lines;
	while (tmp[n] != NULL)
	{
		if (strcmp(tmp[n][0], "push") == 0)
		{
			my_push(my_stack, n);
		}
		else
		{
			if (is_code(tmp[n][0], my_stack, n) != 0)
				print_err(str_concat("L2: unknown instruction ", tmp[n][0]));
		}
		n++;
	}
}

/**
 * is_code - checks if str is valid code
 * @str: Input, str to check
 * @my_stack: Input, stack
 * @l_num: Input, code line #
 *
 * Return: status
 */
int is_code(char *str, stack_t **my_stack, int l_num)
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
			codes[i].f(my_stack, l_num);
			return (0);
		}
		i++;
	}
	return (-1);
}
