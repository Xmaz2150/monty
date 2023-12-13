#include "monty.h"
#include "globals.h"

/**
 * create_iL_arr - creates global opcodes arr
 * @raw_codes: Input, list of enrefined opcodes
 *
 * Return: 3D list
 */
char ***create_iL_arr(node_st *raw_codes)
{
	int str_count, i;
	char ***lines, *token1, *token2;
	node_st *current;

	str_count = list_st_count(raw_codes);
	lines = (char ***)malloc((str_count + 1) * sizeof(char **));
	if (lines == NULL)
		return (NULL);

	current = raw_codes;
	for (i = 0; i < str_count; i++)
	{
		token1 = strtok(current->word, " ");
		token2 = strtok(NULL, " ");

		lines[i] = (char **)malloc(2 * sizeof(char *));
		if (lines[i] == NULL)
			return (NULL);

		lines[i][0] = _strdup(token1);
		lines[i][1] = _strdup(token2);

		current = current->next;
	}
	lines[i] = NULL;

	return (lines);
}

/**
 * list_st_count - counts list items
 * @raw_codes: Input, list of enrefined opcodes
 *
 * Return: item count
 */
int list_st_count(node_st *raw_codes)
{
	int str_count = 0;
	node_st *current = raw_codes;

	while (current != NULL)
	{
		str_count++;
		current = current->next;
	}
	return (str_count);
}

/**
 * free_iL_arr - frees global opcode arr
 *
 * Return: none
 */
void free_iL_arr(void)
{
	int i;

	for (i = 0; lines[i] != NULL; i++)
	{
		free(lines[i][0]);
		free(lines[i][1]);
		free(lines[i]);
	}
	free(lines);
}
