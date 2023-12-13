#include "monty.h"

/**
 * add_word - adds word to list
 * @head: Input, list
 * @word: Input, wordto add
 *
 * Return: none
 */
void add_word(node_st **head, char *word)
{
	node_st *new_node = (node_st *)malloc(sizeof(node_st));

	new_node->word = _strdup(word);

	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		node_st *current = *head;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

/**
 * create_input_list - creates word list
 * @input: Input, input
 * @delimiters: Input, seperators
 *
 * Return: new list
 */
node_st *create_input_list(char *input, const char *delimiters)
{
	char *input_copy = _strdup(input);
	char *token = strtok(input_copy, delimiters);
	node_st *head = NULL;

	while (token != NULL)
	{
		add_word(&head, token);
		token = strtok(NULL, delimiters);
	}

	free(input_copy);

	return (head);
}

/**
 * free_input_list- adds word to list
 * @head: Input, list
 *
 * Return: none
 */
void free_input_list(node_st *head)
{
	node_st *current = head;

	while (current != NULL)
	{
		node_st *temp = current;

		current = current->next;
		free(temp->word);
		free(temp);
	}
}

/**
 * free_stack_list- adds word to list
 * @head: Input, list
 *
 * Return: none
 */
void free_stack_list(stack_t *head)
{
	stack_t *current = head;

	while (current != NULL)
	{
		stack_t *temp = current;

		current = current->next;
		/*free(temp->word);*/
		free(temp);
	}
}
