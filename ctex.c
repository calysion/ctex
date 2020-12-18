// ctex -- a simple program that prints the content of a file to the standard output.

#include <stdio.h>


void main (unsigned short argc, char *argv[]) // argv array element size limit is handled by OS/compiler and not specified here
{
	// Error handling
	if (argc == 1 && argv[1] == NULL) // Check for NULL input
	{
		printf("Error: No input file\n");
		return;
	}
	else if (argc > 2) // Check for more than 1 argument supplied
	{
		printf("Error: Too many arguments\n");
		return;
	}


	FILE *fptr; // Set file pointer


	// Open file
	fptr = fopen(argv[1], "r"); // Set argv input argument as file to access

	if (fptr == NULL) // Check for file not found
	{
		printf("Error: File not found - %s\n", argv[1]);
		return;
	}


	// Read contents from file
	char c; // Character buffer to print from file

	c = fgetc(fptr);

	while (c != EOF)
	{
		printf("%c", c); // Print each character from file
		c = fgetc(fptr);
	}


	fclose(fptr);
}