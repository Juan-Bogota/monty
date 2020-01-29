#include "monty.h"


/**
 * op_sub - The opcode sub, substraction the top two elements of the stack.
 * The result is stored in the second top element of the stack, and
 * the top element is removed
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: Currently line number in the file.
 * Return: void.
 */

void op_sub(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	value -= (*stack)->next->n;
	value *= -1;
	op_pop(stack, line_number);
	(*stack)->n = value;
}
