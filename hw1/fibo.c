#include <stdio.h>
#include <stdlib.h>

unsigned long long fibo_recursive(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (fibo_recursive(n - 1) + fibo_recursive(n - 2));
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("%llu", fibo_recursive(atoi(argv[1])));
	return (0);
}
