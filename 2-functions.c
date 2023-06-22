#include "monty.h"

/**
 * divide -  divides the second top element of the stack
 * by the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line number
 */

void divide(stack_t **stack, unsigned int line_number)
{

	stack_t *val = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

		if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}


	val = (*stack)->next;
	sum = val->n;
	sum /= (*stack)->n;
	pop(stack, line_number);
	val->n = sum;
}

/**
 * mul - multiplies the second top element of the stack with
 * the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the line number
 */

void mul(stack_t **stack, unsigned int line_number)
{

	stack_t *val = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->next;
	sum = val->n;
	sum *= (*stack)->n;
	pop(stack, line_number);
	val->n = sum;
}

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the line number
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *val = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}


	val = (*stack)->next;
	sum = val->n;
	sum %= (*stack)->n;
	pop(stack, line_number);
	val->n = sum;
}
#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

