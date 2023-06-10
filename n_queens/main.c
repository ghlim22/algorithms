#include <stdio.h>

static void tuples(int arr[], int k, int n);

int main(void)
{
    int arr[4] = {
        0,
    };
    tuples(arr, 0, 4);
    return (0);
}

static void print_tuple(int arr[], int n)
{
    int i;

    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

static int check(int arr[], int k)
{
    for (int i = k - 1; i > 0; --i)
    {
        if (arr[k] == arr[i])
            return (0);
    }
    return (1);
}

static void tuples(int arr[], int k, int n)
{
    if (k == n)
    {
        print_tuple(arr, n);
        return;
    }
    for (arr[k] = 1; arr[k] <= n; ++arr[k])
    {
        tuples(arr, k + 1, n);
    }
}