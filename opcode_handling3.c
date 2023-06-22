#include "monty.h"

/**
 * mul_f - mul last two node and remove last node
 *
 * @stack: pointer to top node of stack
 * @line_number: current opcode line number
 * Return: None
 */

void mul_f(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *prev_last;

	if (last)
		prev_last = last->prev;
	if (!last || !prev_last)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
		exit_prog();
		exit(EXIT_FAILURE);
	}

	prev_last->n *= last->n;
	prev_last->next = NULL;
	free(last);
	stack_top = prev_last;
}


/**
 * mod_f - mod divide last two node and remove last node
 *
 * @stack: pointer to top node of stack
 * @line_number: current opcode line number
 * Return: None
 */

void mod_f(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *prev_last;

	if (last)
		prev_last = last->prev;
	if (!last || !prev_last)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		exit_prog();
		exit(EXIT_FAILURE);
	}
	if (last->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit_prog();
		exit(EXIT_FAILURE);
	}
	prev_last->n %= last->n;
	prev_last->next = NULL;
	free(last);
	stack_top = prev_last;
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
	stack_t *prev_last;

	if (last)
		prev_last = last->prev;
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

/**
 * pchar_f - print char value
 *
 *
 * @stack: pointer to top node of stack
 * @line_number: current opcode line number
 * Return: None
 */

void pchar_f(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	if (!last)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
			line_number);
		exit_prog();
		exit(EXIT_FAILURE);
	}

	if (last->n < 0 || last->n > 127)
	{
		fprintf(stderr,"L%d: can't pchar, value out of range\n",
			line_number);
		exit_prog();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", last->n);
}
