#include "monty.h"


/**
 * add_dnodeint - unction that adds a new node at the beginning of a
 * dlistint_t list.
 * @head: input of a list.
 * @n: data od the node.
 * Return: the new node at the beginning
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	int value;

	if(*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr,"L%d: can't add, stack too short\n",line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	value += (*stack)->next->n;
	op_pop(stack, line_number);
	(*stack)->n = value;
}
