#include "monty.h"

char *handle_args(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (*(argv + 1));
}

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

char *handle_line(FILE *file_stream)
{
	char *lineptr;
	size_t buff_size = 0;
	ssize_t bytesread;

	bytesread = getline(&lineptr, &buff_size, file_stream);
	line_number++;

	if (bytesread != -1 && !opcode_is_valid(lineptr))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, lineptr);
		free(lineptr);
		exit(EXIT_FAILURE);
	}

	return (lineptr);
}

int opcode_is_valid(char *lineptr)
{
	instruction_t *curr_opcodes = opcodes_arr;
	char *opcode;
	int i = 0;

	opcode = strtok(lineptr, " ");
	opcode_value = strtok(NULL, " ");

	while (curr_opcodes[i].opcode)
	{
		if (strcmp(opcode, curr_opcodes[i].opcode) == 0)
			return (1);
		i++;
	}
	return (0);
}

void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t *curr_opcodes = opcodes_arr;
	int i = 0;

	while (curr_opcodes[i].opcode)
	{
		if (strcmp(opcode, curr_opcodes[i].opcode) == 0)
			return (curr_opcodes[i].f);
		i++;
	}
	return (NULL);
}
