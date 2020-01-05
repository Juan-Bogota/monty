#include "monty.h"

int number;
/**
 * main - Start of the program
 * @argc: numbers of arguments
 * @argv: arguments vector
 * Return: 0
 */

void readfile(char *myfile)
{
	FILE *montyFile;
	char *buffer = NULL;
	size_t size = 0;
	ssize_t ret;
	char **command;
	int pointer;
	stack_t *list = NULL;

	montyFile = fopen(myfile, "r");
	if (montyFile == NULL)
	{
		write(2, "Error: Can't open file ", 22);
		write(2, myfile, strlen(myfile));
		write(2,"\n",1);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		ret = getline(&buffer, &size, montyFile);
		if (!buffer)
		{
			write(2,"Error: malloc failed\n", 21);
			exit(EXIT_FAILURE);
		}
		if (ret == EOF)
			break;
		pointer = _memory(buffer);
		command = validateBuffer(buffer, pointer);
		opcode_validate(command, buffer, &list);
		free(command);
	}
	free_list(list); // falta el free validar
	{
		dlistint_t *tmp = head;

		while (head != NULL)
		{
			head = head->next;
			free(tmp);
			tmp = head;
		}
		free(head);
	}
	free(buffer);
	free(command);
	fclose(montyFile);
}

/**
 * main - Start of the program
 * @argc: numbers of arguments
 * @argv: arguments vector
 * Return: 0
 */

char **validateBuffer(char *buffer, int pointer)
{
	char *delim = " \n\t";
	char *tok;
	size_t i;
	char **command;


	command = malloc(sizeof(char *) * pointer);
	if (command == NULL)
	{
		write(2,"Error: malloc failed\n", 21);
		free(buffer);
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
 * main - Start of the program
 * @argc: numbers of arguments
 * @argv: arguments vector
 * Return: 0
 */

void opcode_validate(char **command, char *buffer, stack_t **list)
{
	int i = 0;
	static int line = 0;

	while(command[i] != NULL)
		i++;
	line++;
	if (!(i == 2 || i == 1))
	{
		fprintf(stderr,"L %d: unknown instruction %s",line,command[0]);
		free(command);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	if (i == 2)
		number = atoi(command[1]);
	f_opcode(command, buffer, line, list);
}


/**
 * main - Start of the program
 * @argc: numbers of arguments
 * @argv: arguments vector
 * Return: 0
 */

void f_opcode(char **command, char *buffer, unsigned int line, stack_t **list)
{
	int j = 0;
	instruction_t opcodeFunc[] = {
		{"push", op_push},
		{"pall", op_pall},
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
	if(opcodeFunc[j].opcode == NULL)
	{
		fprintf(stderr,"L %d: unknown instruction %s",line,command[0]);
		free(command);
		free(buffer);
		exit(EXIT_FAILURE);
	}

}

/**
 * main - Start of the program
 * @argc: numbers of arguments
 * @argv: arguments vector
 * Return: 0
 */


int _memory(char *buffer)
{
	int i, count = 2;
	char *delim = " ";

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == delim[0])
			count++;
	}
	return (count);
}
