#include <stdio.h>

int upperbound(int *arr, int len, int key)
{
	int start;
	int end;
	int mid;

	start = 0;
	end = len;
	while (start < end)
	{
		mid = start + (end - start) / 2;
		if (arr[mid] > key)
			end = mid;
		else
			start = mid + 1;
	}
	return (start);
}

int lowerbound(int *arr, int len, int key)
{
	int start;
	int end;
	int mid;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		mid = start + (end - start) / 2;
		if (arr[mid] >= key)
			end = mid;
		else
			start = mid + 1;
	}
	return (start);
}


int main(void)
{
	int arr[10] = {0, 1, 2, 3, 3, 3, 4, 5, 6, 7};

	printf("lowerbound: %d\n upperbound: %d\n", lowerbound(arr, 10, 3), upperbound(arr, 10, 3));

	return (0);
}

