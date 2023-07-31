#include "monty.h"

/**
 * freestack - A function that frees the memory allocated for stack.
 * @stack: Pointer to the doubly linked list representation of a stack.
 * Return: Nothing.
 */

void freestack(stack_t **stack)
{
	stack_t *aux = *stack;

	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
}
