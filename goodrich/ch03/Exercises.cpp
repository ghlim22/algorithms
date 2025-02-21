#include <algorithm>
#include <iostream>

int FindMax(int *array, int s, int n)
{
  if (n == 1) {
    return array[s];
  }
  if (n % 2 != 0) {
    return std::max(
      std::max(FindMax(array, s, n / 2), FindMax(array, s + n / 2 + 1, n / 2)),
      array[s + n / 2]);
  }
  return std::max(FindMax(array, s, n / 2), FindMax(array, s + n / 2, n / 2));
}

void subset(int *set, int *subset, bool *used, int n, int cursor) {
	
}

void PrintAllSubsets(int *set, int n) {}

int main(void)
{
  int array[11];
  for (int i = 0; i < 11; ++i) {
    array[i] = i;
  }
  std::cout << FindMax(array, 0, 11);
  return 0;
}