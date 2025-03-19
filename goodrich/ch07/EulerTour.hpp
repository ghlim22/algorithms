#pragma once

#include "BinaryTree.hpp"
#include <iostream>

template <typename T, typename R> class EulerTour
{
protected:
  struct Result {
    R left_result;
    R right_result;
    R final_result;
  };

  typedef BinaryTree<T>           tree;
  typedef typename tree::Position position;

public:
  //void init(const tree *t) { _tree = t; }

protected:
  virtual void visit_external(const position &p, Result &r) {}

  virtual void visit_left(const position &p, Result &r) {}

  virtual void visit_right(const position &p, Result &r) {}

  virtual void visit_below(const position &p, Result &r) {}

  Result init_result() { return Result(); }

  int result(const Result &r) const { return r.final_result; }

  int euler_tour(const position &p) const
  {
    Result r = init_result();
    if (p.is_external()) {
      visit_external(p, r);
    } else {
      visit_left(p, r);
      r.left_result = euler_tour(p.left());
      visit_below(p, r);
      r.right_result = euler_tour(p.right());
      visit_right(p, r);
    }

    return result(r);
  }

protected:
  //const tree *_tree;
};

template <typename T, typename R>
class EvaluateExpressionTour : public EulerTour<T, R>
{
protected:
  typedef typename EulerTour<T, R>::tree     tree;
  typedef typename EulerTour<T, R>::position position;
  typedef typename EulerTour<T, R>::Result Result;

public:
  void execute(const tree &t) {
	//init(t);
	std::cout << "result: " << EulerTour<T, R>::euler_tour(t.root()) << std::endl;
  }
protected:
  virtual void visit_external(const position &p, Result &r) {
	r.final_result = (*p).value();
  }


  virtual void visit_right(const position &p, Result &r) {
	r.final_result = (*p).operation(r.left_result, r.right_result);
  }

};