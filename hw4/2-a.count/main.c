#include <stdio.h>
#define MAX_SIZE (128)

int main(void)
{
    int count[MAX_SIZE] = {
        0,
    };
    int c;

    while ((c = getchar()) != EOF)
        count[c]++;

    for (int i = 0; i < MAX_SIZE; ++i)
        printf("count[%d]: %d\n", i, count[i]);

    return (0);
}