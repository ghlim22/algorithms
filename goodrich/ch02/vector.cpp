#include <cstring>
#include <exception>
#include <iostream>

class Complex {
public:
  Complex(int r = 0, int i = 0) : _real(r), _imag(i) {}
  ~Complex() {}
  Complex(const Complex &other) : _real(other._real), _imag(other._imag) {}
  Complex &operator=(const Complex &rhs) {
    if (this == &rhs) {
      return *this;
    }

    _real = rhs._real;
    _imag = rhs._imag;
    return *this;
  }
  friend Complex operator+(const Complex &lhs, const Complex &rhs);
  friend Complex operator-(const Complex &lhs, const Complex &rhs);
  friend Complex operator*(const Complex &lhs, const Complex &rhs);

private:
  int _real;
  int _imag;
};

Complex operator+(const Complex &lhs, const Complex &rhs) {
  return Complex(lhs._real + rhs._real, lhs._imag + rhs._imag);
}

Complex operator-(const Complex &lhs, const Complex &rhs) {
  return Complex(lhs._real - rhs._real, lhs._imag - rhs._imag);
}

Complex operator*(const Complex &lhs, const Complex &rhs) {
  return Complex(lhs._real * rhs._real - lhs._imag * rhs._imag,
                 lhs._real * rhs._imag + lhs._imag * rhs._real);
}

template <typename T> class Vector {
public:
  Vector(int capacity = 10)
      : _capacity(capacity), _size(0), _container(new T[capacity]()) {}

  Vector(const Vector<T> &other)
      : _capacity(other._capacity), _size(other._size),
        _container(new T[other._capacity]()) {
    std::memmove(_container, other._container, _capacity * sizeof(T));
  }

  ~Vector() { delete[] _container; }

  int size() { return _size; }

  void push_back(T elem) {
    if (_size == _capacity) {
      T *temp = new T[_capacity * 2];
      std::memmove(temp, _container, _size * sizeof(T));
      delete[] _container;
      _container = temp;
      _capacity *= 2;
    }
    _container[_size++] = elem;
  }

  T &operator[](int i) { return _container[i]; }
  const T &operator[](int i) const { return _container[i]; }

  friend Vector<T> operator+(const Vector<T> &lhs, const Vector<T> &rhs) {
    if (lhs._size != rhs._size) {
      throw std::exception();
    }
    Vector<T> temp(lhs);
    for (int i = 0; i < temp._size; ++i) {
      temp[i] += rhs[i];
    }
    return temp;
  }

  friend Vector<T> operator-(const Vector<T> &lhs, const Vector<T> &rhs) {
    if (lhs._size != rhs._size) {
      throw std::exception();
    }
    Vector<T> temp(lhs);
    for (int i = 0; i < temp._size; ++i) {
      temp[i] -= rhs[i];
    }
    return temp;
  }

  friend Vector<T> operator*(const T &lhs, const Vector<T> &rhs) {
    Vector<T> temp(rhs);
    for (int i = 0; i < temp._size; ++i) {
      temp[i] *= lhs;
    }
    return temp;
  }

  friend T DotProduct(const Vector<T> &lhs, const Vector<T> &rhs) {
    if (lhs._size != rhs._size) {
      throw std::exception();
    }

    T temp = T(0);
    for (int i = 0; i < lhs._size; ++i) {
      temp += lhs[i] * rhs[i];
    }
    return temp;
  }

private:
  int _capacity;
  int _size;
  T *_container;
};

int main() {
  Vector<int> vi;
  Vector<double> vd;
  Vector<Complex> vc;

  for (int i = 0; i < 100; ++i) {
    vi.push_back(i);
  }

  auto vi2(vi);
  auto vi3 = vi + vi2;
  auto vi4 = vi - vi2;
  auto vi5 = 5 * vi;

  auto res = DotProduct(vi, vi2);

  for (int i = 0; i < vi2.size(); ++i) {
    std::cout << vi2[i] << '\n';
  }
  std::cout << "\n\n";
  for (int i = 0; i < vi3.size(); ++i) {
    std::cout << vi3[i] << '\n';
  }
  std::cout << "\n\n";
  for (int i = 0; i < vi4.size(); ++i) {
    std::cout << vi4[i] << '\n';
  }
  std::cout << "\n\n";
  for (int i = 0; i < vi5.size(); ++i) {
    std::cout << vi5[i] << '\n';
  }
  std::cout << "\n\n";
  std::cout << res;
  std::cout << "\n\n";
  


}