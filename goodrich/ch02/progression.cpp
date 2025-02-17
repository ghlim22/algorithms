#include <iostream>

class Progression {
public:
  Progression(long f = 0) : _first(f), _cur(f) {}
  virtual ~Progression() {}
  void printProgression(int n) {
    std::cout << firstValue();
    for (int i = 1; i < n; ++i)
      std::cout << ' ' << nextValue();
    std::cout << std::endl;
  }

protected:
  virtual long firstValue() {
    _cur = _first;
    return _cur;
  }
  virtual long nextValue()=0; 

protected:
  long _first;
  long _cur;
};

class ArithProgression : public Progression {
public:
  ArithProgression(long i = 1) : Progression(), _inc(i) {}
  virtual ~ArithProgression() {}

protected:
  virtual long nextValue() {
    _cur += _inc;
    return _cur;
  }

protected:
  long _inc;
};

class GeomProgression : public Progression {
public:
  GeomProgression(int b = 2) : Progression(1), _base(b) {}

protected:
  virtual long nextValue() {
    _cur *= _base;
    return _cur;
  }

protected:
  long _base;
};

class FibonacciProgression: public Progression {
public:
	FibonacciProgression(long f=0, long s=1): Progression(f), _second(s), _prev(_second - _first) {}
	virtual ~FibonacciProgression() {}
protected:
	virtual long firstValue() {
		_cur = _first;
		_prev = _second - _first;
		return _cur;
	}
	virtual long nextValue() {
		long t = _cur;
		_cur += _prev;
		_prev = t;
		return _cur;
	}

protected:
	long _second;
	long _prev;
};

class FibonacciProgression2: public FibonacciProgression {
	public:
		FibonacciProgression2(): FibonacciProgression() {
			_cur++;
		}
};

class DifferenceProgression: public Progression {
	public:
		DifferenceProgression(long f=2, long s=200): Progression(f), _second(s), _prev(s + f) {}
	protected:
		virtual long firstValue() {
			_cur = _first;
			_prev = _first + _second;
			return _cur;
		}
		virtual long nextValue() {
			long t = _cur;
			_cur = std::abs(_prev - _cur);
			_prev = t;
			return _cur;
		}
	private:
		long _second;
		long _prev;
};

// class SQRootProgression: public Progression {
// 	public:
// 		SQRootProgression(double f=65536): Progression(), _first(f) {}
// 	protected:
// 		double firstValue() {
//     	_cur = _first;
//     	return _cur;
//   		}
//    		double nextValue() {
// 			double t = _cur;
// 			_cur = std::sqrt(_cur);
// 		}
// 	protected:
// 		double _first;
// 		double _cur;

// }

int main() {
	Progression *prog;

	std::cout << "Arithmetic progression with default increment:\n";
	prog = new ArithProgression();
	prog->printProgression(10);
	std::cout << "Arithmetic progression with increment 5:\n";
	prog = new ArithProgression(5);
	prog->printProgression(10);

	std::cout << "Geometric progression with default base:\n";
	prog = new GeomProgression();
	prog->printProgression(10);
	std::cout << "Geometric progression with base 3:\n";
	prog = new GeomProgression();
	prog->printProgression(10);

	std::cout << "Fibonacci progression with default start values:\n";
	prog = new FibonacciProgression();
	prog->printProgression(10);
	std::cout << "Fibonacci progression with start values 4 and 6:\n";
	prog = new FibonacciProgression(4, 6);
	prog->printProgression(10);
	
	std::cout << "Difference progression with default start values:\n";
	prog = new DifferenceProgression();
	prog->printProgression(10);

	// std::cout << "Square root progression with default start values:\n";
	// prog = new FibonacciProgression();
	// prog->printProgression(10);

	return 0;
}