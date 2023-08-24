#include "monty.h"
#include "lists.h"
/*
 * get_func - helps in selecting the right function.
 * @parsed: bytcode file that is passed to the main.
 * Return: pointer
 * otherwise - NULL
 */

void (*get_func(char **parsed))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"nop", nop_handler},
		{"sub", sub_handler},
		{"div", div_handler},
		{"mul", mul_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"stack", stack_handler},
		{"queue", queue_handler},
		{NULL, NULL}
	};

	int codes = 17, j;

	for (j = 0; j < codes; j++)
	{
		if (strcmp(func_arr[j].opcode, parsed[0]) == 0)
		{
			return (func_arr[j].f);
		}
	}
	return (NULL);
}

/**
 * push_handler - handling the push instruction.
 * @stack: double pointer to the stack.
 * @line_number: number of the line that the file is in.
 */

void push_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num = 0, j;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	for (j = 0; data.words[1][j]; j++)
	{
		if (isalpha(data.words[1][j]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			free_all(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);

	if (data.qflag == 0)
		new = add_dnodeint(stack, num);
	else if (data.qflag == 1)
		new = add_dnodeint_end(stack, num);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/*
 * pall_handler - hsndling pall instructions
 * @stack: double pointer to the stack.
 * @line_number: num of line in file.
 */
void pall_handler(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_dlistint(*stack);
}
