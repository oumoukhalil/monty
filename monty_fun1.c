#include "monty.h"

/**
 * monty_mul - A function that multiply the two top values of a stack.
 * @stack: The pointer to the stack list.
 * @line_count: The line number of a Monty bytecodes file.
 */
void monty_mul(stack_t **stack, unsigned int line_count)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(8, line_count);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_count);
}

/**
 * monty_div - A function that divides the second value from the top of a
 * stack linked by the top value.
 * @stack: The pointer to the stack list.
 * @line_count: The line number of a Monty bytecodes file.
 */
void monty_div(stack_t **stack, unsigned int line_count)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(6, line_count);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		f_errors(7, line_count);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_count);
}

/**
 * monty_mod - A function that modules
 * @stack: The pointer to the stack list.
 * @line_count: The line number of a Monty bytecodes file.
 */
void monty_mod(stack_t **stack, unsigned int line_count)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(9, line_count);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		f_errors(7, line_count);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_count);
}

/**
 * monty_pchar - A function that prints char at top value of the stack.
 * @stack: The pointer to the stack list.
 * @line_count: The current working line number of a Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_count)
{
	int number = 0;
	stack_t *tmp = *stack;

	if (!tmp)
	{
		f_errors(11, line_count);
		exit(EXIT_FAILURE);
	}
	number = tmp->n;
	if (number < 0 || number > 127)
	{
		f_errors(10, line_count);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}

/**
 * monty_pstr - A function that prints the string starting at the top of the
 * stack
 * @stack: The pointer to the stack list.
 * @line_count: The current working line number of a Monty bytecodes file.
 */
void monty_pstr(stack_t **stack, unsigned int line_count)
{
	stack_t *tmp = *stack;
	(void)line_count;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp != NULL)
	{
		if (tmp->n > 0 && tmp->n <= 127)
		{
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
		else
			break;
	}
	printf("\n");
}
