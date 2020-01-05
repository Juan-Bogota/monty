#include "monty.h"

/**
 * main - Start of the program
 * @argc: numbers of arguments
 * @argv: arguments vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *myfile;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	myfile = argv[1];
	readfile(myfile);

	return (0);
}
