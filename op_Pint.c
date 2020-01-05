#include "monty.h"


/**
 * add_dnodeint - unction that adds a new node at the beginning of a
 * dlistint_t list.
 * @head: input of a list.
 * @n: data od the node.
 * Return: the new node at the beginning
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if(tmp == NULL)
	{
		fprintf(stderr,"L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while(tmp != NULL)
	{
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	while(tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}
