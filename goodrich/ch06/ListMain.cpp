#include "List.hpp"
#include <iostream>

int main() {
	List<int> l;
	for (int i = 0; i < 10; ++i) {
		l.push_back(i);
	}
	List<int>::Iterator it = l.begin();
	for (; it != l.end(); ++it) {
		std::cout << *it << ' ';
	}

	std::cout << std::endl;

	List<int> l2;
	for (int i = 0; i < 10; ++i)
		l2.push_front(i);
	l2.pop_back();
	List<int>::Iterator it2 = l2.begin();
	for (; it2 != l2.end(); ++it2)
		std::cout << *it2 << ' ';

	return 0;
}