#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: an integer
 * @prev: pointing to the previous element of the stack
 * @next: pointing to the next element of the stack
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s -an  opcode and its function
 * @opcode: opcode
 * @f: function that is supposed to handle the oppcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct args_s - argument structure from main
 * @av: file name from the command line
 * @ac: argument  umber from main.
 * @line_number: current line number in the file
 *
 * Description: arguments passed to main from the command line
 * used in different functions, organized in a struct for clarity
 */
typedef struct args_s
{
	char *av;
	int ac;
	unsigned int line_number;
} args_t;

/**
 * struct data_s - data that accesses inside functions
 * @line: line from the file
 * @words: line
 * @stack: stack pointer.
 * @fptr: file pointer
 * @qflag: flag for stack
 */
typedef struct data_s
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *fptr;
	int qflag;
} data_t;

typedef stack_t dlistint_t;

extern data_t data;

#define DATA_INIT {NULL, NULL, NULL, NULL, 0}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"

/* main.c */
void monty(args_t *args);

/* getFunc.c */
void (*get_func(char **parsed))(stack_t **, unsigned int);
void push_handler(stack_t **stack, unsigned int line_number);
void pall_handler(stack_t **stack, unsigned int line_number);

/* handleFunc1.c */
void pint_handler(stack_t **stack, unsigned int line_number);
void pop_handler(stack_t **stack, unsigned int line_number);
void swap_handler(stack_t **stack, unsigned int line_number);
void add_handler(stack_t **stack, unsigned int line_number);
void nop_handler(stack_t **stack, unsigned int line_number);

/* handleFunc2.c */
void sub_handler(stack_t **stack, unsigned int line_number);
void div_handler(stack_t **stack, unsigned int line_number);
void mul_handler(stack_t **stack, unsigned int line_number);
void mod_handler(stack_t **stack, unsigned int line_number);

/* handleFunc3.c */
void rotl_handler(stack_t **stack, unsigned int line_number);
void rotr_handler(stack_t **stack, unsigned int line_number);
void stack_handler(stack_t **stack, unsigned int line_number);
void queue_handler(stack_t **stack, unsigned int line_number);

/* put.c */
void pchar_handler(stack_t **stack, unsigned int line_number);
void pstr_handler(stack_t **stack, unsigned int line_number);

/* str.c */
int count_word(char *s);
char **strtow(char *str);
void free_everything(char **args);

/* FreeAll.c */
void free_all(int all);

#endif
