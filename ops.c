#include "monty.h"
#include "globals.h"

/**
 * my_push - adds new node to lls if it exists creates new if not
 * @stack: Input, lls
 * @line_number: Input, number
 *
 * Return: none
 */
void my_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int val;

	val = str_to_int(lines[line_number][1]);
	if (val == -1)
	{
		print_err("L6: usage: push integer");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		*stack = (stack_t *)malloc(sizeof(stack_t));
		if (*stack == NULL)
		{
			return;
		}
		(*stack)->n = val;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
	}
	else
	{
		new_node = (stack_t *)malloc(sizeof(stack_t));
		if (new_node == NULL)
		{
			return;
		}
		new_node->n = val;
		new_node->prev = NULL;
		new_node->next = *stack;

		(*stack)->prev = new_node;
		*stack = new_node;
	}
}


/**
 * my_pall - prints stack
 * @stack: Input, lls
 * @line_number: Input, number
 *
 * Return: none
 */
void my_pall(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	print_list(*stack);
}

/**
 * my_pint - prints top
 *  @stack: Input, stack
 *  @line_number: Inpu, number
 *
 *  Return: none
 */
void my_pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
	{
		print_err("L0: can't pint, stack empty");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * my_pop - removes top
 *  @stack: Input, stack
 *  @line_number: Inpu, number
 *
 *  Return: none
 */
void my_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	(void)line_number;

	if (*stack == NULL)
	{
		print_err("L0: can't pop an empty stack");
		exit(EXIT_FAILURE);
	}

	if (top->next != NULL)
		top->next->prev = NULL;
	*stack = top->next;
	free(top);
}

