#include "monty.h"

/**
 * push_f - push node to end of stack
 *
 * @stack: pointer to top node of stack
 * @line_number: current opcode line number
 * Return: None
 */

void push_f(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (atoi(opcode_value) == 0 && *opcode_value != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit_prog();
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_prog();
		exit(EXIT_FAILURE);
	}

	node->n = atoi(opcode_value);
	node->next = NULL;
	node->prev = *stack;
	*stack = node;
}

/**
 * pall_f - print all stack nodes value
 *
 * @stack: pointer to top node of stack
 * @line_number: current opcode line number
 * Return: None
 */

void pall_f(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *curr = *stack;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->prev;
	}
}

/**
 * pint_f - print value of last node
 *
 * @stack: pointer to top node of stack
 * @line_number: current opcode line number
 * Return: None
 */

void pint_f(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", stack_top->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit_prog();
		exit(EXIT_FAILURE);
	}
}

/**
 * pop_f - pop last node
 *
 * @stack: pointer to top node of stack
 * @line_number: current opcode line number
 * Return: None
 */

void pop_f(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!stack_top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit_prog();
		exit(EXIT_FAILURE);
	}
	stack_top = stack_top->prev;
	if (stack_top)
		stack_top->next = NULL;
	free(tmp);
}

/**
 * swap_f - swap last top two nodes
 *
 * @stack: pointer to top node of stack
 * @line_number: current opcode line number
 * Return: None
 */

void swap_f(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *prev_last = last->prev;

	if (!last || !prev_last)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		fflush(stderr);
		exit_prog();
		exit(EXIT_FAILURE);
	}
	prev_last->next = NULL;
	last->next = prev_last;
	last->prev = prev_last->prev;
	prev_last->prev = last;
	stack_top = prev_last;
}
