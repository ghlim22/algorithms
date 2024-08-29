#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utility>

#define SIZE (10)

void QuickSort(int a[], int low, int high)
{
    if (low >= high) {
        return;
    }

    int &p = a[high];
    int i = low;
    int j = low;

    for (; j < high; ++j) {
        if (a[j] < p) {
            std::swap(a[i++], a[j]);
        }
    }

    std::swap(a[i], p);

    QuickSort(a, low, i - 1);
    QuickSort(a, i + 1, high);
}

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

    QuickSort(a, 0, size - 1);

    printf("Sorted:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d\n", a[i]);
    }

    return 0;
}
