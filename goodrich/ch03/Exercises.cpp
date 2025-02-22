#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

void findSubset(int *set, int *subset, int n, int cursor, int index)
{
  if (index == n) {
    for (int i = 0; i < cursor; ++i) {
      std::cout << subset[i] << ' ';
    }
    std::cout << '\n';
    return;
  }

  findSubset(set, subset, n, cursor, index + 1);
  subset[cursor] = set[index];
  findSubset(set, subset, n, cursor + 1, index + 1);
}

void printAllSubsets(int *set, int n)
{
  int  *subset = new int[n];
  std::memset(subset, 0, n * sizeof(int));

  findSubset(set, subset, n, 0, 0);
}

int main(void)
{
  std::srand(std::time(NULL));

  int array[3];
  for (int i = 0; i < 3; ++i) {
    array[i] = std::rand() % 19837;
  }
  std::cout << FindMax(array, 0, 11);
  std::cout << "\n\n";

  printAllSubsets(array, sizeof(array) / sizeof(int));

  return 0;
}