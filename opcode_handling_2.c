#include "monty.h"

/**
 * add_f - sum last two node and remove last node
 *
 * @stack: pointer to top node of stack
 * @line_number: current opcode line number
 * Return: None
 */

void add_f(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *prev_last = last->prev;

	if (!last || !prev_last)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		free(opcode);
		exit(EXIT_FAILURE);
	}

	prev_last->n += last->n;
	prev_last->next = NULL;
	free(last);
	stack_top = prev_last;
}

/**
 * nop_f - Do Nothing
 *
 * @stack: pointer to top node of stack
 * @line_number: current opcode line number
 * Return: None
 */

void nop_f(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
}

/**
 * free_stack - free linkedlist stack
 *
 * @stack: pointer to top node of stack
 * Return: None
 */

void free_stack(stack_t **stack)
{
	stack_t *curr = *stack;
	stack_t *tmp;

	while (curr)
	{
		tmp = curr->prev;
		free(curr);
		curr = tmp;
	}
	stack_top = NULL;
}
