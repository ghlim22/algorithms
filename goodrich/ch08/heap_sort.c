#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE (100)

int parent(int k) {
	return (k - 1) / 2;
}

int left(int k) {
	return (2 * k) + 1;
}

int right(int k) {
	return (2 * k) + 2;
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// using a max-heap
void my_heapsort(int a[], int size, int (*compare)(int, int)) {
	for (int i = 0; i < size; ++i) {
		// insert into the heap
		int k = i;
		while (k > 0 && compare(a[parent(k)], a[k])) {
			swap(&a[k], &a[parent(k)]);
			k = parent(k);
		}
	}

	for (int i = size - 1; i >= 0; --i) {
		swap(&a[0], &a[i]);
		int k = 0;
		while (left(k) < i) {
			int child = left(k);
			if (right(k) < i) {
				if (compare(a[left(k)], a[right(k)])) {
					child = right(k);
				}
			}
			if (compare(a[k], a[child])) {
				swap(&a[k], &a[child]);
				k = child;
			} else {
				break;
			}
		}
	}
}

int less(int a, int b) {
	return a < b;
}

int main(void)
{
  srand(time(NULL));

  int arr[ARRAY_SIZE];
  for (int i = 0; i < ARRAY_SIZE; ++i) {
    arr[i] = rand();
  }

  my_heapsort(arr, ARRAY_SIZE, less);

  for (int i = 0; i < ARRAY_SIZE; ++i) {
	printf("%d\n", arr[i]);
  }

  for (int i = 1; i < ARRAY_SIZE; ++i) {
	assert(!less(arr[i], arr[i - 1]));
  }

  return 0;
}