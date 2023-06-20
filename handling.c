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

