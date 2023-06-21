#include "monty.h"

instruction_t opcodes_arr[] = {
	{"push", push_f},
	{"pall", pall_f},
	{"pint", pint_f},
	{"pop", pop_f},
	{"swap", swap_f},
	{"add", add_f},
	{"nop", nop_f},
	{NULL, NULL}
};
unsigned int line_number = 0;
char *opcode_value = NULL;
stack_t *stack_top = NULL;
char *opcode = NULL;


/**
 * main - Entry point
 *
 * @argc: number of program arguments
 * @argv: pointer to arOIray of arguments
 * Return: (int) 1 if success else 0
 */

int main(int argc, char **argv)
{
	char *file_name;
	FILE *file_stream;
	char *file_line;
	void (*op_func)(stack_t **, unsigned int);

	file_name = handle_args(argc, argv);
	file_stream = handle_file(file_name);

	while (1)
	{
		file_line = handle_line(file_stream);
		if (!*file_line)
			break;

		op_func = get_op_func(file_line);
		op_func(&stack_top, line_number);
		free(file_line);

	};
	free(file_line);
	fclose(file_stream);
	free_stack(&stack_top);
	return (1);
}
