#include "monty.h"

instruction_t opcodes_arr[] = {
	{"push", push_f},
	{"pall", pall_f},
	{"pint", pint_f},
	{"pop", pop_f},
	{"swap", swap_f},
	{"add", add_f},
	{"sub", sub_f},
	{"div", div_f},
	{"mul", mul_f},
	{"mod", mod_f},
	{"nop", nop_f},
	{"pchar", pchar_f},
	{"pstr_f", pstr_f},
	{"rotl", rotl_f},
	{"rotr", rotr_f},
	{"stack", nop_f},
	{"queue", nop_f},
	{"#", nop_f},
	{"\n", nop_f},
	{NULL, NULL}
};
unsigned int line_number = 0;
char *opcode_value = NULL;
stack_t *stack_top = NULL;
stack_t *stack_head = NULL;
char *opcode = NULL;
cmd_t cmd = {NULL, NULL};
/**
 * main - Entry point
 *
 * @argc: number of program arguments
 * @argv: pointer to arOIray of arguments
 * Return: (int) 1 if success else 0
 */

int main(int argc, char **argv)
{
	FILE *file_stream;

	file_stream = handle_file(argc, argv);
	cmd.file_stream = file_stream;
	while (1)
	{
		run();
		free(cmd.file_line);
	};
	return (1);
}
