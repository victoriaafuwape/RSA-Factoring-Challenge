#include "main.h"

/**
 * factorize_numbers - Read file and process each number
 * @filename: pointer to the name of the file to be read
 */
void factorize_numbers(const char *filename)
{
	FILE *file;
	unsigned long number;

	file = fopen(filename, "r"); /* Open the file for reading */

	while (fscanf(file, "%lu", &number) != EOF) /* Read until end of file */
	{
		factorize_and_print(number); /* Process each number */
	}

	fclose(file); /* Close the file after processing */
}

/**
 * factorize_and_print - Find factors and print them
 * @number: the number to be factorized
 */
void factorize_and_print(unsigned long number)
{
	unsigned long i;

	for (i = 2; i <= number / i; ++i)
	{
		if (number % i == 0) /* Check if i is a factor of number */
		{
			printf("%lu=%lu*%lu\n",
			       number, i, number / i); /* Print factors */
			return;
		}
	}

	/* If no factors found, print the number itself (prime number case) */
	printf("%lu=%lu*%u\n", number, number, 1);
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: (0) on success, (1) on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2) /* Check for correct number of arguments */
	{
		fprintf(stderr,
			"Usage: factors <file>\n"); /* Print error message */
		return (1); /* Return (1) on failure */
	}

	factorize_numbers(argv[1]); /* Process the file */
	return (0); /* Return (0) on success */
}
