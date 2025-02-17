class A {
public:
  A(int x = 0) : _x(x) {}

protected:
  int _x;
};

class B : public A {
public:
  B(int x = 1) : A(), _x(x) {}

private:
  int _x;
};

class C : public B {
public:
  C(int x = 2) : B(), _x(x) { A::_x = 7; }

private:
  int _x;
}
