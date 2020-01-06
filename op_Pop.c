#include "monty.h"


/**
 * op_pop - The opcode pop removes the top element of the stack.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: Currently line number in the file.
 * Return: void
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
	{
		free(tmp);
		*stack = NULL;
		return;
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);

}
