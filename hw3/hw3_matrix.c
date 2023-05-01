#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE (1000)

typedef unsigned long long ull;

static ull dimensions[MAX_SIZE];
static ull optimal_k[MAX_SIZE][MAX_SIZE];
static ull opt[MAX_SIZE][MAX_SIZE];

static void get_dimensions(int argc, char **argv);
static void solve(int mat_cnt);
static void print_result(int mat_cnt);

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("usage: ./matrix d1, d2, ... , dn+1\n");
		return (0);
	}
	get_dimensions(argc, argv);
	solve(argc - 2);
	print_result(argc - 2);
	return (0);
}

static void get_dimensions(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		dimensions[i] = (ull)atoll(argv[i]);
	}
}

static void solve(int mat_cnt)
{
	for (int j = 1; j <= mat_cnt; ++j)
	{
		for (int i = 1; i + j <= mat_cnt; ++i)
		{
			int min_k;
			ull min_cost = ULLONG_MAX;
			for (int k = i; k < i + j; ++k)
			{
				ull cost = opt[i][k] + opt[k + 1][i + j] + dimensions[i] * dimensions[k + 1] * dimensions[i + j + 1];
				if (cost < min_cost)
				{
					min_k = k;
					min_cost = cost;
				}
			}
			opt[i][i + j] = min_cost;
			optimal_k[i][i + j] = min_k;
		}
	}
}

static void print_table_opt(int mat_cnt)
{
	for (int i = 1; i <= mat_cnt; ++i)
	{
		for (int j = 1; j <= mat_cnt; ++j)
		{
			if (j >= i)
				printf("%5llu ", opt[i][j]);
			else
				printf("      ");
		}
		printf("\n");
	}
}

static void print_table_k(int mat_cnt)
{
	for (int i = 1; i <= mat_cnt; ++i)
	{
		for (int j = 1; j <= mat_cnt; ++j)
		{
			if (j >= i)
				printf("%5llu ", optimal_k[i][j]);
			else
				printf("      ");
		}
		printf("\n");
	}
}

static void print_mul(int start, int end, int depth)
{
	int k = (int)optimal_k[start][end];
	if (start + 1 == end)
	{
		printf("(");
		printf("A%dA%d", start, end);
		printf(")");
	}
	else if (start == end)
	{
		printf("A%d", start);
	}
	else
	{
		if (depth > 0)
			printf("(");
		print_mul(start, k, depth + 1);
		print_mul(k + 1, end, depth + 1);
		if (depth > 0)
			printf(")");
	}
}

static void print_result(int mat_cnt)
{
	printf("\ntable of opt[i,j]\n");
	print_table_opt(mat_cnt);
	printf("\ntable of k[i,j]\n");
	print_table_k(mat_cnt);
	printf("\noptimal chained matrix multiplication\n");
	print_mul(1, mat_cnt, 0);
	printf("\n");
}