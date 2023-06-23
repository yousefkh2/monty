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

/**
 * rotr_f - rotate last stack item to first
 *
 * @stack: point to top of stack
 * @line_number: stack line number
 */

void rotr_f(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *head = *stack;

	if (!last || !last->prev)
		return;

	while (head->prev)
		head = head->prev;

	stack_top = head;
	head->next->prev = NULL;
	head->next = NULL;
	last->next = head;
	head->prev = last;
}

/**
 * qpush_f - push node to end of stack
 *
 * @stack: pointer to top node of stack
 * @line_number: current opcode line number
 * Return: None
 */

void qpush_f(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!is_valid_integer(opcode_value))
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
	node->prev = NULL;
	node->next = stack_head;
	if (!*stack)
	{
		stack_head = node;
		*stack = node;
	} else
	{
		stack_head->prev = node;
		stack_head = node;
	}
}
