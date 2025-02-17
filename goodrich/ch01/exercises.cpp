#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

class Vector2 {
public:
  Vector2(double x, double y) : _x(x), _y(y) {}
  friend Vector2 operator+(const Vector2 &rhs, const Vector2 &lhs);
  friend double operator*(const Vector2 &rhs, const Vector2 &lhs);
  friend Vector2 operator*(double rhs, const Vector2 &lhs);

private:
  double _x;
  double _y;
};

Vector2 operator+(const Vector2 &rhs, const Vector2 &lhs) {
  return Vector2(rhs._x + lhs._x, rhs._y + lhs._y);
}

double operator*(const Vector2 &rhs, const Vector2 &lhs) {
  return (rhs._x * lhs._x + rhs._y * lhs._y);
}

Vector2 operator*(double rhs, const Vector2 &lhs) {
  return Vector2(rhs * lhs._x, rhs * lhs._y);
}

bool isTwoPower(int i) {
  for (int j = 0; j < sizeof(int) * 8; ++j) {
    if ((i & (1 << j)) == i) {
      return true;
    }
  }
  return false;
}

int sum(int n) {
  int sum = 0;
  for (int i = 1; i < n; ++i) {
    sum += i;
  }
  return sum;
}

int sumOdds(int n) {
  int sum = 0;
  for (int i = 1; i < n; i += 2) {
    sum += i;
  }
  return sum;
}

int divideByTwo(double x) {
  int count = 0;
  while (x >= 2) {
    x /= 2;
    count++;
  }
  return count;
}

void reverse(int *arr, int n) {
  for (int i = 0; i < n / 2; ++i) {
    std::swap(arr[i], arr[n - 1 - i]);
  }
}

bool hasEvenProductPair(int *arr, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (arr[i] * arr[j] % 2 == 0)
        return true;
    }
  }
  return false;
}

void shuffle(int array[], int size) {
  int *cache = new int[size];
  bool *used = new bool[size];
  std::memmove(cache, array, sizeof(int) * size);
  std::memset(used, 0, sizeof(bool) * size);
  for (int i = 0; i < size;) {
    int idx = std::rand() % size;
	if (used[idx])
		continue;
    used[idx] = true;
    array[i] = cache[idx];
	++i;
  }
  delete[] cache;
  delete[] used;
}

// C-1.6
void c16(std::string s, int used) {
  if (s.size() == 6) {
    std::cout << s << '\n';
    return;
  }

  for (int i = 0; i < 6; ++i) {
    if (used & (1 << i))
      continue;
    c16(s + char('a' + i), used | (1 << i));
  }
}

// C-1.7

void c17() {
  std::vector<std::string> lines;

  std::string line;
  while (std::cin >> line)
    lines.push_back(line);

  auto rit = lines.rbegin();
  for (; rit != lines.rend(); ++rit) {
    std::cout << *rit << '\n';
  }
}

long twoPower(int i) {
	return long(1 << i);
}

void p1() {
	for (int i = 0; i < 100; ++i) {
		std::string s = "I will always use object-oriented design.";
		for (int j = 0; j < 8; ++j) {
			int idx = std::rand() % s.size();
			char c = ((rand() % 2 == 0) ? 'A' : 'a');
			c += rand() % 26;
			s[idx]=c;
		}
		std::cout << i << ": " << s << '\n';
	}
}

double birthday(int n) {
	std::vector<int> p;
	int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int i = 0; i < n; ++i) {
		int mo = rand() % 12 + 1;
		int day = rand() % (days[mo] - 1) + 1;
		p.push_back(mo * 100 + day);
	}

  for (int i = 0; i < p.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (p[i]==p[j]) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  std::srand(std::time(NULL));

  int arr[10];
  for (int i = 0; i < 10; ++i) {
	arr[i] = std::rand() % 100;
	std::cout << i << ": " << arr[i] << '\n';
  }
  
  shuffle(arr, 10);
  for (int i = 0; i < 10; ++i) {
	std::cout << i << ": " << arr[i] << '\n';
  }

  //p1();
  
  int test = 30;
  int cnt = 0;
  for (int i = 1; i < test; ++i) {
    if (birthday(5)) {
      cnt++;
    }
  }
  std::cout << double(cnt) / test;

  return 0;
}