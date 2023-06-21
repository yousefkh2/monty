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
	char *lineptr = NULL;
	size_t buff_size = 0;
	ssize_t bytes_read;

	bytes_read = getline(&lineptr, &buff_size, file_stream);
	if (bytes_read == -1)
	{
		free(lineptr);
		return (NULL);
	}
	line_number++;

	if (!opcode_is_valid(lineptr))
	{
		fprintf(stderr, "L%d: unknown instruction %s",
			line_number, lineptr);
		free(lineptr);
		exit(EXIT_FAILURE);
	}

	return (lineptr);
}

int opcode_is_valid(char *lineptr)
{
	instruction_t *curr_opcodes = opcodes_arr;
	int i = 0;

	strtok(lineptr, " ");
	opcode_value = strtok(NULL, " ");

	while (i < OPCODE_ARR_LENGTH)
	{
		if (strcmp(lineptr, curr_opcodes[i].opcode) == 0)
			return (1);
		curr_opcodes++;
		i++;
	}
	return (0);
}
