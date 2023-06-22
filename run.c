#include "monty.h"

/**
 * run - run opcode
 *
 * Return: None
 */

void run(void)
{
	char *file_line = NULL;
	void (*op_func)(stack_t **, unsigned int);

	file_line = handle_line(cmd.file_stream);
	cmd.file_line = file_line;
	op_func = get_op_func();
	if (!op_func)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, opcode);
		exit_prog();
		exit(EXIT_FAILURE);
	}
	op_func(&stack_top, line_number);
}

/**
 * exit_prog - closing and clearning memory
 *
 * Return: None
 */

void exit_prog(void)
{
	free(cmd.file_line);
	if (stack_top)
		free_stack(&stack_top);
	fclose(cmd.file_stream);
}
