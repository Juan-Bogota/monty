#include "monty.h"

char *number;
/**
 * readfile - This function validate the status of the file
 * @myfile: file to open
 *
 * Return: Function Void
 */

void readfile(char *myfile)
{
	FILE *montyFile;
	char *buffer = NULL, **command;
	size_t size = 0;
	ssize_t ret;
	int pointer, line = 0, i = 0;
	stack_t *list = NULL;

	montyFile = fopen(myfile, "r");
	if (montyFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", myfile);
		exit(EXIT_FAILURE);
	}
	while ((ret = getline(&buffer, &size, montyFile)) != EOF)
	{
		if (!buffer)
		{
			write(2, "Error: malloc failed\n", 21);
			fclose(montyFile);
			exit(EXIT_FAILURE);
		} line += 1;
		if (ret == 1)
			continue;
		else
		{
			i = 0;
			while (buffer[i] == ' ' && buffer[i + 1] == ' ')
				i++;
			if (buffer[i + 1] == '\n')
				continue;
		}
		pointer = _memory(buffer);
		command = validateBuffer(buffer, pointer, montyFile);
		op_val(command, buffer, &list, line, montyFile);
		free(command);
	}
	free_stack(&list);
	free(buffer);
	fclose(montyFile);
}

/**
 * validateBuffer - Function tokenized the variable buffer in command
 * @buffer: is the variable storage in getline
 * @pointer: is the amount of words in the buffer
¨* @montyF: File
 * Return: command is the tokenized of buffer
 */

char **validateBuffer(char *buffer, int pointer, FILE *montyF)
{
	char *delim = " \n\t";
	char *tok;
	size_t i;
	char **command;


	command = malloc(sizeof(char *) * pointer);
	if (command == NULL)
	{
		write(2, "Error: malloc failed\n", 21);
		free(buffer);
		fclose(montyF);
		exit(EXIT_FAILURE);
	}
	tok = strtok(buffer, delim);
	i = 0;
	while (tok)
	{
		command[i] = tok;
		tok = strtok(NULL, delim);
		i++;
	}
	command[i] = NULL;
	return (command);
}


/**
 * op_val - opcode validate the number of arguments in command
 * @command: is the tokenized of the string in getline
 * @buffer: is the string storared in getline
 * @list: is the struct of the doubly linked list
 * @line: is the currently number line in the file
 * @a: File
 * Return: void
 */

void op_val(char **command, char *buffer, stack_t **list, int line, FILE *a)
{
	int i = 0;

	while (command[i] != NULL)
		i++;
	if (!(i == 2 || i == 1))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, command[0]);
		free(command);
		free(buffer);
		free_stack(list);
		fclose(a);
		exit(EXIT_FAILURE);
	}
	if (i == 2)
		number = command[1];
	f_opcode(command, buffer, line, list, a);
}


/**
 * f_opcode - is the function that compare the word read in the file for
 * realize a function in the struct instruction_t
 * @command: is the tokenized of the string in getline
 * @buffer: is the string storared in getline
 * @list: is the struct of the doubly linked list
 * @line: is the currently number line in the file
 * @m: File.
 * Return: void
 */

void f_opcode(char **command, char *buffer, int line, stack_t **list, FILE *m)
{
	int j = 0;
	instruction_t opcodeFunc[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL},
	};

	while (opcodeFunc[j].opcode != NULL)
	{
		if (strcmp(opcodeFunc[j].opcode, command[0]) == 0)
		{
			opcodeFunc[j].f(list, line);
			return;
		}
		j++;
	}
	if (opcodeFunc[j].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, command[0]);
		free(command);
		free(buffer);
		free_stack(list);
		fclose(m);
		exit(EXIT_FAILURE);
	}
}
