#include "monty.h"

/**
 * monty_start - A function that runs a Monty bytecodes script.
 * @fd: File descriptor for an open Monty bytecodes script.
 * Return: EXIT_SUCCESS on success, otherwise.
 */
int monty_start(FILE *fd)
{
	stack_t *stack = NULL;
	char *line = NULL, **token = NULL, delim[] = " \n\t\a\b";
	size_t len = 0, mode = 1;
	size_t line_cnt = 0, exit_status = EXIT_SUCCESS;

	while (getline(&line, &len, fd) != -1)
	{
		line_cnt++;
		if (void_line(line, delim))
			continue;
		token = tokening(line, delim);
		if (token[0][0] == '#' || strcmp(token[0], "nop") == 0)
		{
			free(token);
			continue;
		}
		else if (strcmp(token[0], "stack") == 0)
			mode = 1;
		else if (strcmp(token[0], "queue") == 0)
			mode = 0;
		else if (strcmp(token[0], "push") == 0 && mode == 0)
			exit_status = queue_push(&stack, token, line_cnt);
		else if (strcmp(token[0], "push") == 0 && mode == 1)
			exit_status = stack_push(&stack, token, line_cnt);
		else
			exit_status = execute(token, &stack, line_cnt);
		free(token);
		if (exit_status == EXIT_FAILURE)
			break;
	}
	freestack(&stack);
	free(line);
	return (exit_status);
}

/**
 * tokening - A function that split the line.
 * @line: The pointer to bytecode line.
 * @delim: Array with 5 delimiters " \n\t\a\b".
 * Return: The pointer to tokens.
 */
char **tokening(char *line, char *delim)
{
	char *tokens = NULL, **token = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (line == NULL || !*line)
		return (NULL);

	bufsize = strlen(line);
	if (bufsize == 0)
		return (NULL);
	token = malloc(bufsize * sizeof(char *));
	if (token == NULL)
	{
		free(line);
		free(token);
		exit(usage_error(0));
	}
	tokens = strtok(line, delim);
	if (tokens == NULL)
	{
		free(token);
		free(line);
		return (NULL);
	}
	while (tokens != NULL)
	{
		token[i] = tokens;
		i++;
		tokens = strtok(NULL, delim);
	}
	token[i] = '\0';
	return (token);
}

/**
 * void_line - A function that checks if line only contains delimiters.
 * @line: The pointer to the line.
 * @d: The string with delimiter characters.
 * Return: 1 if the line only contains delimiters, otherwise 0.
 */
int void_line(char *line, char *d)
{
	size_t i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; d[j]; j++)
		{
			if (line[i] == d[j])
				break;
		}
		if (d[j] == '\0')
			return (0);
	}

	return (1);
}
