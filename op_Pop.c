#include "monty.h"


/**
 * add_dnodeint - unction that adds a new node at the beginning of a
 * dlistint_t list.
 * @head: input of a list.
 * @n: data od the node.
 * Return: the new node at the beginning
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;
	if((*stack)->next == NULL)
	{
		free(tmp);
		*stack = NULL;
		return;
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);

}
