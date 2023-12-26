#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void factorize_numbers(const char *filename);
int is_prime(unsigned long n);
void factorize_and_print(unsigned long number);
unsigned long gcd(unsigned long a, unsigned long b);
unsigned long absolute_difference(unsigned long x, unsigned long y);
unsigned long f(unsigned long x, unsigned long n);
unsigned long pollards_rho(unsigned long n);
void factorize_and_print(unsigned long n);

#endif /* MAIN_H */
