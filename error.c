#include "monty.h"

/**
 * print_err - prints to stderr
 * @message: Input, error to be printed
 */
void print_err(char *message)
{
	write(STDERR_FILENO, str_concat(message, "\n"), strlen(message) + 1);
}
