#include "monty.h"

/**
 * main - Start of the program
 * @argc: numbers of arguments
 * @argv: arguments vector
 * Return: 0
 */

int main(char *argv[], int argc)
{
	if(argc != 2)
	{
		write(2,"USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	file = argv[1];
	return(0);
}
