#include <stdio.h>
#include <assert.h>
#define MAX_SIZE (300)
#define PARENT(x) ((x) / 2)
#define LEFT(x) ((x) * 2)
#define RIGHT(x) ((x) * 2 + 1)

typedef struct
{
	int size;
	int min_heap[MAX_SIZE];
} heap;


static void push(heap *h, int item);
static int pop(heap *h);
static void construct_heap(heap *h);
static void solve(heap *h);

int main(void)
{
	heap h;
	h.size = 0;
	construct_heap(&h);
	solve(&h);
	return (0);
}

static void push(heap *h, int item)
{
	int i = ++(h->size);
	while (i > 0 && item < h->min_heap[PARENT(i)])
	{
		h->min_heap[i] = h->min_heap[PARENT(i)];
		i = PARENT(i);
	}
	h->min_heap[i] = item;
}

static int pop(heap *h)
{
	if (h->size < 1)
		return (-1);
	int top = h->min_heap[1];
	int last = h->min_heap[h->size--];
	int parent = 1;
	int child = 2;
	while (child <= h->size)
	{
		if (child < h->size && h->min_heap[child] > h->min_heap[child + 1])
			child++;
		if (last <= h->min_heap[child])
			break;
		h->min_heap[parent] = h->min_heap[child];
		parent = child;
		child *= 2;
	}
	h->min_heap[parent] = last;
	return (top);
}

static void construct_heap(heap *h)
{
	int count[128] = {0, };
	int c;

	while ((c = getchar()) != EOF)
	{
		count[c]++;
	}
	for (int i = 0; i < 128; ++i)
	{
		if (count[i])
			push(h, count[i]);
	}
}

static void solve(heap *h)
{
	int a;
	int b;
	int sum;
	int total_sum;

	total_sum = 0;
	while (h->size > 1)
	{
		a = pop(h);
		b = pop(h);
		sum = a + b;
		total_sum += sum;
		push(h, sum);
	}
	printf("%d\n", total_sum);
}
