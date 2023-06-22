#include "monty.h"

/**
 * rotl_f - rotate last stack item to first
 *
 * @stack: point to top of stack
 * @line_number: stack line number
 */

void rotl_f(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *head = *stack;

	if (!last || !last->prev)
		return;

	while (head->prev)
		head = head->prev;

	stack_top = last->prev;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = head;
	head->prev = last;
}
