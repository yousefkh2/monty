#include "monty.h"

/**
 * handle_args - check argument validation
 *
 * @argc: argument counter
 * @argv: array of arguments
 * Return: pointer to file name
 */

char *handle_args(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (*(argv + 1));
}

/**
 * handle_file - handling opening file
 *
 * @file_name: pointer to file name
 * Return: pointer to opening file stream
 */

FILE *handle_file(char *file_name)
{
	FILE *file_stream;

	file_stream = fopen(file_name, "r");
	if (file_stream == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (file_stream);
}

/**
 * handle_line - read line from file stream
 *
 * @file_stream: pointer to file stream
 * Return: pointer to line string
 */

char *handle_line(FILE *file_stream)
{
	size_t buff_size = 0;
	ssize_t bytesread;

	bytesread = getline(&opcode, &buff_size, file_stream);
	if (bytesread == -1)
		*opcode = '\0';
	line_number++;
	return (opcode);
}

/**
 * get_op_func - get opcode function
 *
 * @lineptr: pointer to current line
 * Return: pointer to opcode function
 */

void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t *curr_opcodes = opcodes_arr;
	int i = 0;

	strtok(opcode, " \n");
	opcode_value = strtok(NULL, " \n");

	while (curr_opcodes[i].opcode)
	{
		if (strcmp(opcode, curr_opcodes[i].opcode) == 0)
			return (curr_opcodes[i].f);
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
		line_number, opcode);
	free(opcode);
	exit(EXIT_FAILURE);

	return (0);
}
