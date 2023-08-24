#include "monty.h"
#include "lists.h"
/**
 * rotl_handler - handling the rotl instruction
 * @stack: double pointer to the stack that is supposed to be pushed to.
 * @line_number: line number in file
 */

void rotl_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num  = 0;

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, num);
}

/**
 * rotr_handler - handling the rotr instruction
 * @stack: double pointer to the stack that is supposed to be pushed to.
 * @line_number: line number in the file.
 */

void rotr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0, len = dlistint_len(*stack);

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, len - 1);
	num = temp->n;
	delete_dnodeint_at_index(stack, len - 1);
	add_dnodeint(stack, num);
}
/**
 * stack_handler - handling stack instruction
 * @stack: the double pointer to the stack that is supposed to be pushed to.
 * @line_number: line number in a file.
 */

void stack_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 0;
}
/**
 * queue_handler -  handling the queue instruction
 * @stack: the double pointer to the stack that is supposed to be pushed to.
 * @line_number: line number in a file
 */

void queue_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 1;
}
