#include "main.h"

int is_prime(unsigned long number) {
    if (number <= 1) return 0; // 0 and 1 are not prime numbers
    if (number <= 3) return 1; // 2 and 3 are prime numbers

    // Check for divisibility by 2 and 3
    if (number % 2 == 0 || number % 3 == 0) return 0;

    for (unsigned long i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0)
            return 0;
    }

    return 1;
}

/* Modified factorize_and_print function */
void factorize_and_print(unsigned long number) {
    for (unsigned long i = 2; i <= number / i; ++i) {
        if (number % i == 0) {
            unsigned long larger_factor = number / i;
            if (is_prime(i) && is_prime(larger_factor)) {
                printf("%lu=%lu*%lu\n", number, larger_factor, i);
                return;
            }
        }
    }

    printf("No prime factors found for %lu\n", number); // In case no prime factors are found
}

/* Main function */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: rsa <file>\n");
        return 1;
    }

    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return 1;
    }

    unsigned long number;
    if (fscanf(file, "%lu", &number) != EOF) {
        factorize_and_print(number);
    } else {
        fprintf(stderr, "Error reading the number from the file\n");
    }

    fclose(file);
    return 0;
}
