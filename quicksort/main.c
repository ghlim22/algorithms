#include <stdio.h>

#define SWAP(ARRAY, A, B) \
do \
{ \
	int tmp = ARRAY[(A)];\
	ARRAY[(A)] = ARRAY[(B)];\
	ARRAY[(B)] = tmp;\
} while (0)

static void quicksort(int *arr, int lower, int upper)
{
	int left = lower;
	int right = upper;
	int pivot = arr[(lower + upper) / 2];

	do
	{
		while (left <= upper && arr[left] < pivot)
			left++;
		while (right >= lower && arr[right] > pivot)
			right--;
		if (left <= right)
		{
			SWAP(arr, left, right);
			left++;
			right--;
		}
	} while (left <= right);
	if (lower < right)
		quicksort(arr, lower, right);
	if (left < upper)
		quicksort(arr, left, upper);
}

int main(void)
{
	int N;
	int arr[1000];

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	quicksort(arr, 0, N - 1);
	for (int i = 0; i < N; ++i)
		printf("%d\n", arr[i]);
	return 0;
}

