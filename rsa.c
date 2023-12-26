#include "main.h"

unsigned long gcd(unsigned long a, unsigned long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

unsigned long absolute_difference(unsigned long x, unsigned long y) {
    return (x > y) ? (x - y) : (y - x);
}

unsigned long f(unsigned long x, unsigned long n) {
    return (x * x + 1) % n;
}

unsigned long pollards_rho(unsigned long n)
{
	unsigned long x, y, d;

	if (n % 2 == 0)
		return 2;

	x = 2;
	y = 2;
	d = 1;

	while (d == 1)
	{
		x = f(x, n);
		y = f(f(y, n), n);
		d = gcd(absolute_difference(x, y), n);
	}

	return d;
}

void factorize_and_print(unsigned long n) {
	unsigned long divisor;

	if (n == 1)
		return;

	divisor = pollards_rho(n);
	if (divisor == n) {
		printf("%lu is a prime factor\n", n);
	} else {
		printf("%lu is a factor\n", divisor);
		factorize_and_print(n / divisor);
	}
}

int main(int argc, char *argv[]) {
	unsigned long n;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <number>\n", argv[0]);
		return 1;
	}

	n = strtoul(argv[1], NULL, 10);
	printf("Factoring %lu:\n", n);
	factorize_and_print(n);

	return 0;
}
