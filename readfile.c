#include "monty.h"

/**
 * main - Start of the program
 * @argc: numbers of arguments
 * @argv: arguments vector
 * Return: 0
 */

void readfile(char *myfile)
{
	FILE *montyFIle;
	char *buffer = NULL;
	size_t size = 0;
	ssize_t ret;
	char **command;


	montyFile = fopen(myfile, "r");
	if (montyFile == NULL)  // si no encuentra el archivo
	{
		write(2, "Error: Can't open file", 22);
		write(2, myfile, strlen(myfile));
		write(2,"\n",1);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		ret = getline(&buffer, &size, archivo);
		if(ret == EOF)
			break;
		//printf("%s",buffer);
		command = validateBuffer(buffer);
		opcode_validate(command, buffer);
	}
	free(buffer);
	fclose(archivo);
	return (0);
}

/**
 * main - Start of the program
 * @argc: numbers of arguments
 * @argv: arguments vector
 * Return: 0
 */

char **validateBuffer(char *buffer)
{
	char *delim = " \n\t";
	char *tok;
	size_t i;
	char **command;

	if (!buffer)
	{
		write(2,"Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
	command = malloc(sizeof(char *) * pointer);
	if (command == NULL)
	{
		write(2,"Error: malloc failed\n", 21);
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

void opcode_validate(char **command, char *buffer);
{
	int i = 0;
	static int j = 0;

	while(command[i] != NULL)
		i++;
	j++;
	count = _itoa(j);
	if (i != 2)
	{
		write(2,"L", 1);
		write(2, count, strlen(count));
		write(2,": unknown instruction", 21);
		write(2, command[0], strlen(command[0]));
		exit(EXIT_FAILURE);
	}
	function_opcode(command, buffer);

}


/**
 * main - Start of the program
 * @argc: numbers of arguments
 * @argv: arguments vector
 * Return: 0
 */

void function_opcode(char **command, char *buffer)
{


}
