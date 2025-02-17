#include <codecvt>
#include <iostream>
#include <string>

class ParallelException {
public:
  ParallelException() : _msg("The lines are parellel.") {}

private:
  std::string _msg;
};

class Line {
public:
  Line (double a, double b) : _a(a), _b(b) {}

  double intersect(const Line &l) const throw(ParallelException) {
	double e = 1e-9;
	if (std::fabs(l._a - _a) <= e) {
		throw ParallelException();
	}
    return (_b - l._b) / (l._a - _a);
  }

private:
  double _a;
  double _b;
};

int main(void) {
	Line a(0.5, 0.5);
	Line b(0.5, 0.4);
	Line c(0.4, 0.1);

	try {
	if (a.intersect(b)) {
		std::cout << "Intersect\n";
	}
	} catch (ParallelException &e) {
		std::cout << "Parellel\n";
	}

	try {
	if (b.intersect(c)) {
		std::cout << "Intersect\n";
	}
	} catch (ParallelException &e) {
		std::cout << "Parellel\n";
	}


	try {
	if (c.intersect(a)) {
		std::cout << "Intersect\n";
	}
	} catch (ParallelException &e) {
		std::cout << "Parellel\n";
	}

	double x = 0.5;
	double y = 0.5;
	if (std::fabs(x - y) <= 1e-9) {
		std::cout << "x and y are the same.\n";
	}

	return 0;
}