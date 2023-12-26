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
 * is_prime - Checks if a number is prime
 * @n: the number to check
 * Return: 1 if prime, 0 otherwise
 */
int is_prime(unsigned long n)
{
	if (n <= 1) return 0;
	if (n <= 3) return 1;

	if (n % 2 == 0 || n % 3 == 0) return 0;

	for (unsigned long i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;
	}

	return (1);
}

/**
 * factorize_and_print - Find factors and print them
 * @number: the number to be factorized
 */
void factorize_and_print(unsigned long number)
{
	unsigned long i;
	unsigned long larger_factor;

	for (i = 2; i <= number / i; ++i)
	{
		if (number % i == 0) /* Check if i is a factor of number */
		{
			larger_factor = number / i;
			if (is_prime(i) && is_prime(larger_factor))
			{
				printf("%lu=%lu*%lu\n",
				       number, i, larger_factor);
				return;
			}
		}
	}

	printf("%lu=%lu*1\n", number, number);
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
