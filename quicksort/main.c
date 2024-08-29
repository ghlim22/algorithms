#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(a, b)                                                             \
    do {                                                                       \
        int tmp = a;                                                           \
        a = b;                                                                 \
        b = tmp;                                                               \
    } while (0)

#define SIZE (10)

void quicksort(int a[], int low, int high);

int main(void)
{
    int a[SIZE];
    const int size = SIZE;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; ++i) {
        a[i] = rand() % 100;
    }

    printf("Unsorted:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d\n", a[i]);
    }

    quicksort(a, 0, size - 1);

    printf("Sorted:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d\n", a[i]);
    }

    return 0;
}

/*
 * a: a list of integers.
 * a[low..high]
 */
void quicksort(int a[], int low, int high)
{
    int p = a[(low + high) / 2];
    int i = low;
    int j = high;

    while (i <= j) {
        while (a[i] < p) { // pivot의 왼쪽에서 pivot보다 크거나 같은 값을 찾는다.
            ++i;
        }
        while (a[j] > p) { // pivot의 오른쪽에서 pivot보다 작거나 같은 값을 찾는다.
            --j;
        }
        if (i <= j) { // i <= j 이면, 두 값을 교환해야 한다.
            SWAP(a[i], a[j]);
            ++i;
            --j;
        }
    }

    if (low < j) {
        quicksort(a, low, j);
    }
    if (i < high) {
        quicksort(a, i, high);
    }
}
