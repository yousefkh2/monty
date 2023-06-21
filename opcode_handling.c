#include "monty.h"

void push_f(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (atoi(opcode_value) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		/* free(); */
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		/* free() */
		fprintf(stderr, "Error: malloc failed\n");
	}

	node->n = atoi(opcode_value);
	node->next = NULL;
	node->prev = *stack;
	*stack = node;
}

void pall_f(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *curr = *stack;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->prev;
	}
}

void pint_f(stack_t **stack, unsigned int line_number)
{
	if (stack_top)
		printf("%d\n", stack_top->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

void pop_f(UNUSED stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	if (!stack_top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = stack_top;
	stack_top = stack_top->prev;
	stack_top->next = NULL;
	free(tmp);
}

void swap_f(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *prev_last = last->prev;

	if (!last || !prev_last)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	prev_last->next = NULL;
	last->next = prev_last;
	last->prev = prev_last->prev;
	prev_last->prev = last;
	stack_top = prev_last;
}

void add_f(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *prev_last = last->prev;

	if (!last || !prev_last)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	prev_last->n += last->n;
	prev_last->next = NULL;
	free(last);
	stack_top = prev_last;
}

void nop_f(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	return;
}

void free_stack(stack_t **stack)
{
	stack_t *curr = *stack;
	stack_t *tmp;

	while(curr)
	{
		tmp = curr->prev;
		free(curr);
		curr = tmp;
	}
	stack_top = NULL;
}
