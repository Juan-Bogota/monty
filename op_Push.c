#include "monty.h"


/**
 * add_dnodeint - unction that adds a new node at the beginning of a
 * dlistint_t list.
 * @head: input of a list.
 * @n: data od the node.
 * Return: the new node at the beginning
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	unsigned int num, i;

	for (i = 0; i < strlen(number); i++)
	{
		if(!isdigit(number[i]) ) {
			fprintf(stderr,"L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(number);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		write(2,"Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
	new->next = *stack;
	new->prev = NULL;
	new->n = num;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
