#include "Deque.hpp"
#include <iostream>

int main() {
	Deque<int> d;

	for (int i = 0; i < 10; ++i) {
		d.push_back(i);
		std::cout << "size: " << d.size() << std::endl;
	}
	while (!d.empty()) {
		std::cout << d.front() << std::endl;
		std::cout << "size: " << d.size() << std::endl;
		d.pop_front();
	}

	for (int i = 0; i < 10; ++i) {
		d.push_front(i);
		std::cout << "size: " << d.size() << std::endl;
	}
	while (!d.empty()) {
		std::cout << d.back() << std::endl;
		std::cout << "size: " << d.size() << std::endl;
		d.pop_back();
	}
	return 0;
}