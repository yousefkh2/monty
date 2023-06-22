#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define UNUSED __attribute__((unused))

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct cmd_s - user command
 * @file_line: current file line
 * @file_stream: pointer to file stream
 *
 * Description: N\A
 */

typedef struct cmd_s
{
	char *file_line;
	FILE *file_stream;
} cmd_t;

extern stack_t *stack_top;
extern instruction_t opcodes_arr[];
extern unsigned int line_number;
extern char *opcode_value;
extern char *opcode;
extern cmd_t cmd;

FILE *handle_file(int argc, char **argv);
char *handle_line(FILE *file_stream);
void (*get_op_func())(stack_t **, unsigned int);

void run(void);
void exit_prog(void);

void push_f(stack_t **stack, unsigned int line);
void pall_f(stack_t **staci, unsigned int line);
void pint_f(stack_t **staci, unsigned int line);
void pop_f(stack_t **staci, unsigned int line);
void swap_f(stack_t **staci, unsigned int line);
void add_f(stack_t **staci, unsigned int line);
void nop_f(stack_t **staci, unsigned int line);
void sub_f(stack_t **stack, unsigned int line);
void div_f(stack_t **stack, unsigned int line);
void mul_f(stack_t **stack, unsigned int line);
void mod_f(stack_t **stack, unsigned int line);
void pchar_f(stack_t **stack, unsigned int line);
void pstr_f(stack_t **stack, unsigned int line);
void rotl_f(stack_t **stack, unsigned int line);
void free_stack(stack_t **stack);
#endif
