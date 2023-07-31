#include "monty.h"

/**
 * monty_pint - A function that prints the top value of the stack.
 * @stack: The pointer to the stack list.
 * @line_count: The current working line number of a Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_count)
{
	stack_t *aux = *stack;

	if (!aux)
	{
		f_errors(1, line_count);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", aux->n);
}


/**
 * monty_pop - A function that removes the top value in the stack.
 * @stack: The pointer to the stack_t list.
 * @line_count: The line number of a Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_count)
{
	stack_t *aux = *stack;

	if (!aux)
	{
		f_errors(2, line_count);
		exit(EXIT_FAILURE);
	}

	if (aux->next)
		aux->next->prev = aux->prev;
	*stack = aux->next;
	free(aux);
}

/**
 * monty_swap - swaps the two values at the top of stack.
 * @stack: The pointer to the top of a stack list.
 * @line_count: The line number of a Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_count)
{
	int aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(3, line_count);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = aux;
}

/**
 * monty_add - A function that adds the two top values of a stack.
 * @stack: The pointer to the stack list.
 * @line_count: The line number of a Monty bytecodes file.
 */
void monty_add(stack_t **stack, unsigned int line_count)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(4, line_count);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_count);
}

/**
 * monty_sub - A function that subtracts the second value from the top of a
 * stack linked by the top value.
 * @stack: The pointer to the stack list.
 * @line_count: The line number of a Monty bytecodes file.
 */
void monty_sub(stack_t **stack, unsigned int line_count)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(5, line_count);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_count);
}
