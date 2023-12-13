#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

#define TOKKEN_DELIMS " \t\n"
#define TOKKEN_DELIMS2 " "

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct Node_st
{
	char *word;
	struct Node_st *next;
} node_st;

/* main */
void _execute(node_st *raw_codes, stack_t **my_stack);

void my_push(stack_t **stack, unsigned int line_number);
void my_pall(stack_t **stack, unsigned int line_number);
void my_pint(stack_t **stack, unsigned int line_number);
void my_pop(stack_t **stack, unsigned int line_number);
void my_swap(stack_t **stack, unsigned int line_number);
void my_add(stack_t **stack, unsigned int line_number);
void my_nop(stack_t **stack, unsigned int line_number);

/*  */
int is_code(char *str, stack_t **my_stack);

/* helper nodes*/
void add_word(node_st **head, char *word);
node_st *create_input_list(char *input, const char *delimiters);
void free_input_list(node_st *head);
void free_stack_list(stack_t *head);
/* helpers */
int _putchar(char c);
void print_err(char *message);
int str_to_int(const char *str, int *result);
void print_list(stack_t *head);

/*str*/
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
char *str_concat_helper(char *new_str, char *s1, char *s2);

#endif /*MONTY_H*/
