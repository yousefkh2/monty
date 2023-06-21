#include "monty.h"

void push_f(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (atoi(opcode_value) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = atoi(opcode_value);
	node->next = NULL;
	node->prev = *stack;
	*stack = node;
}

void pall_f(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->prev;
	}
}
