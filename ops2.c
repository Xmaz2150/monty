#include "monty.h"

/**
 * my_swap - swaps top 2
 *  @stack: Input, stack
 *  @line_number: Inpu, number
 *
 *  Return: none
 */
void my_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *second = (*stack)->next;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		print_err("L1: can't swap, stack too short");
		exit(EXIT_FAILURE);
	}

	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;

	*stack = second;
}

/**
 * my_add - adds top 2
 *  @stack: Input, stack
 *  @line_number: Inpu, number
 *
 *  Return: none
 */
void my_add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *new_node, *first, *second;

	(void)line_number;
	first = *stack;
	second = first->next;

	sum = first->n + second->n;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		print_err("L1: can't add, stack too short");
		exit(EXIT_FAILURE);
	}

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		print_err("L1: can't swap, stack too short");
		exit(EXIT_FAILURE);
	}
	new_node->n = sum;
	new_node->prev = NULL;
	new_node->next = NULL;

	*stack = second->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(first);
	free(second);

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * my_nop - none
 *  @stack: Input, stack
 *  @line_number: Inpu, number
 *
 *  Return: none
 */
void my_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

}
