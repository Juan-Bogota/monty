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


	montyFile = fopen(myfile, "r");
	if (montyFile == NULL)  // si no encuentra el archivo
	{
		write(2, "Error: Can't open file", 22);
		write(2, myfile, strlen(myfile));
		write(2,"\n",1);
		exit(EXIT_FAILURE);
	}
	printf("\nEl contenido del archivo de prueba es \n\n");
	while (1)
	{
		ret = getline(&buffer, &size, archivo);
		if(ret == EOF)
			break;
		printf("%s",buffer);
	}
	free(buffer);
	fclose(archivo);
	return 0;
}
