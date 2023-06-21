#include "monty.h"

instruction_t opcodes_arr[] = {
	{"push", push_f},
	{"pall", pall_f},
	{NULL, NULL}
};
unsigned int line_number = 0;
char *opcode_value = NULL;
stack_t *stack_top = NULL;



/**
 * main - Entry point
 *
 * @argc: number of program arguments
 * @argv: pointer to array of arguments
 * Return: (int) 1 if success else 0
 */

int main(int argc, char **argv)
{
	char *file_name;
	FILE *file_stream;
	char *file_line;

	file_name = handle_args(argc, argv);
	file_stream = handle_file(file_name);
	while (1)
	{
		file_line = handle_line(file_stream);
		printf("line: %s\n", file_line);
		get_op_func(file_line)(&stack_top, line_number);
		/* pall_f(&stack_top, line_number); */
	};

}
