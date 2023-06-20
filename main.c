#include "monty.h"




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

	file_name = handle_args(argc, argv);
	file_stream = handle_file(file_name);

}
