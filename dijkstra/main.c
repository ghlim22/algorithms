#include <stdio.h>
#define SIZE (100)
#define INF (1000000)
#define LEFT(x) ((x) * 2)
#define RIGHT(x) ((x) * 2 + 1)
#define SWAP(x, y) \
    do{ \
    int tmp;    \
    tmp = x;    \
    x = y;  \
    y = tmp;    \
    } while (0)

int N;
int Y[SIZE + 1];
int heap[SIZE + 1];
int heap_size;

int main(void)
{

}

int pop(void)
{
    int root;
    int successor;

    if (heap_size == 0)
        return (-1);
    root = heap[1];
    successor = heap[heap_size];
    heap[heap_size--] = -1;
    heap[1] = successor;

    
}

void heapify(int idx)
{
    while(LEFT(idx) <= heap_size && heap[LEFT(idx)] < heap[idx])
    {
        if (RIGHT(idx) <= heap_size && heap[RIGHT(idx)] < heap[idx])
        {
            if (heap[LEFT(idx)] < heap[RIGHT(idx)])
            {
                SWAP(heap[LEFT(idx)], heap[idx]);
                idx = LEFT(idx);
            }
            else
            {
                SWAP(heap[RIGHT(idx)], heap[idx]);
                idx = RIGHT(idx);
            }
        }
        else
        {
            SWAP(heap[LEFT(idx)], heap[idx]);
            idx = LEFT(idx);
        }
    }
    
}