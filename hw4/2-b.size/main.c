#include <stdio.h>
#define MAX_SIZE (128)
#define PARENT(x) ((x) / 2)
#define LEFT(x) ((x) * 2)
#define RIGHT(x) ((x) * 2 + 1)

static int min_heap[MAX_SIZE * 2] = {0, };
static int rear = 1;

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int is_empty(void)
{
    return (rear < 2);
}

static void push(int item)
{
    int i;

    min_heap[rear++] = item;
    i = rear - 1;
    while (i > 1 && min_heap[PARENT(i)] >= min_heap[i])
    {
        swap(&min_heap[PARENT(i)], &min_heap[i]);
        i = PARENT(i);
    }
}

static int pop(void)
{
    int i;
    int res;

    if (rear <= 1)
        return (-1);
    res = min_heap[1];
    min_heap[1] = min_heap[--rear];
    i = 1;
    while (LEFT(i) < rear - 1 && min_heap[i] > min_heap[LEFT(i)])
    {
        if (RIGHT(i) < rear - 1 && min_heap[LEFT(i)] > min_heap[RIGHT(i)])
        {
            swap(&min_heap[i], &min_heap[RIGHT(i)]);
            i = RIGHT(i);
        }
        else
        {
            swap(&min_heap[i], &min_heap[LEFT(i)]);
            i = LEFT(i);
        }
    }
    return (res);
}

int main(void)
{
    int count[MAX_SIZE] = {
        0,
    };
    int c = 0;
    int size = 0;

    while ((c = getchar()) != EOF)
        count[c]++;
    
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        if (count[i])
            push(count[i]);
    }

    while (!is_empty())
        printf("%d, rear: %d\n", pop(), rear);

    return (0);
}
