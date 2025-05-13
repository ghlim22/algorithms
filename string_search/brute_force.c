#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 512

char BUF[BUFSIZE];

int brute_force(char *line, char *pattern)
{
	int n = strlen(line);
	int m = strlen(pattern);

	for (int i = 0; i <= n - m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (line[i + j] != pattern[j])
				break;
			if (j == m - 1)
				return i;
		}
	}

	return -1;
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("usage: %s <filepath> <pattern>\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *path = argv[1];
	char *pattern = argv[2];

	FILE *fp = fopen(path, "r");
	if (fp == NULL) {
		return EXIT_FAILURE;
	}

	int line = 0;
	while (fgets(BUF, BUFSIZE, fp) != NULL) {
		int col = brute_force(BUF, pattern);
		line++;
		if (col != -1) {
			printf("line: %d, column: %d : %s", line, col + 1, BUF);
			break;
		}
	}

	fclose(fp);

	return 0;
}