#include <stdio.h>
#define MAX_SIZE (100)
#define INF (1000000)
#define MIN(x, y) ((x) < (y) ? (x) : (y))

static int W[MAX_SIZE + 1][MAX_SIZE + 1];
static int D[MAX_SIZE + 1][MAX_SIZE + 1];
static int P[MAX_SIZE + 1][MAX_SIZE + 1];
static int N;

static void input(void);
static void floyd(void);
static void path(int a, int d);
static void print_arr(int arr[][MAX_SIZE + 1]);

int main(void)
{
    input();
    floyd();
    path(1, 6);
    print_arr(P);
    return (0);
}

static void print_arr(int arr[][MAX_SIZE + 1])
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
            printf("%8d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

/*
 * input: adjacency matrix
 * edge = 0 if there's no edge from vertex i to vertex j.
 * edge = a positive integer if there's an edge from vertex i to vertex j.
 * W[i][j] = 0 if i = j
 *         = INF if there's no edge from vertex i to vertex j.
 *         = weight of edge i to j if there's a path from vertex i to vertex j.
 */
static void input(void)
{
    int edge, i, j;

    scanf("%d", &N);
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N; ++j)
        {
            scanf("%d", &edge);
            if (edge == 0 && i != j)
            {
                W[i][j] = INF;
            }
            else
            {
                W[i][j] = edge;
            }
        }
    }
}

/*
 * Init:
 * D = W (without using any intermediates.)
 * clear P with 0s.
 */
static void floyd(void)
{
    int i, j, k;

    /* D = W (k = 0)*/
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N; ++j)
        {
            D[i][j] = W[i][j];
        }
    }
    printf("step: %d\n", 0);
    print_arr(D);

    for (k = 1; k <= N; ++k)
    {
        for (i = 1; i <= N; ++i)
        {
            for (j = 1; j <= N; ++j)
            {
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
            }
        }
        printf("step: %d\n", k);
        print_arr(D);
    }
}

static void path_recursive(int a, int d)
{
    if (P[a][d] == 0)
        return;
    path_recursive(a, P[a][d]);
    printf("%d -> ", P[a][d]);
    path_recursive(P[a][d], d);
}

static void path(int a, int d)
{
    if (D[a][d] == INF)
    {
        printf("there's no path from %d to %d :(\n", a, d);
        return;
    }
    printf("the cost of path %d to %d: %d\n", a, d, D[a][d]);
    printf("path: ");
    printf("%d -> ", a);
    path_recursive(a, d);
    printf("%d\n", d);
}