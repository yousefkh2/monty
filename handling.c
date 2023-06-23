#include "monty.h"

/**
 * handle_file - handling opening file
 *
 * @argc: number of arguments
 * @argv: array of program argumnets
 * Return: pointer to opening file stream
 */

FILE *handle_file(int argc, char **argv)
{
	FILE *file_stream;
	char *file_name = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_name = *(argv + 1);

	file_stream = fopen(file_name, "r");
	if (file_stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
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
	char *lineptr = NULL;
	size_t buff_size = 0;
	ssize_t bytesread = 0;
	int i = 0;

	bytesread = getline(&lineptr, &buff_size, file_stream);
	if (bytesread == -1)
	{
		free(lineptr);
		if (stack_top)
			free_stack(&stack_top);
		fclose(file_stream);
		exit(EXIT_SUCCESS);
	}
	line_number++;

	strtok(lineptr, " \n");
	opcode_value = strtok(NULL, " \n");
	while (*(lineptr + i) == ' ')
		i++;
	opcode = (lineptr + i);
	return (lineptr);
}

/**
 * get_op_func - get opcode function
 *
 * Return: pointer to opcode function
 */

void (*get_op_func())(stack_t **, unsigned int)
{
	instruction_t *curr_opcodes = opcodes_arr;
	int i = 0;
	size_t str_len = strlen(opcode);

	if (*opcode == '#')
		str_len = 1;
	while (curr_opcodes[i].opcode)
	{
		if (strncmp(opcode, curr_opcodes[i].opcode, str_len) == 0)
			return (curr_opcodes[i].f);
		i++;
	}
	return (NULL);
}
