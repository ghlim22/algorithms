#include "PriorityQueue.hpp"
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>



int main() {
	PriorityQueue<int, Less<int> > pq;
	std::srand(std::time(NULL));
	for (int i = 0; i < 100000; ++i) {
		pq.push(std::rand() % 1000000000);
	}

	int x = pq.top();
	pq.pop();
	while (!pq.empty()) {
		std::cout << x << std::endl;
		int y = pq.top();
		pq.pop();
		assert(x <= y);
		x = y;
	}

	return 0;
}