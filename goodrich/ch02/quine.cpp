#include <fstream>
#include <iostream>
#include <string>

int main(void) {
	std::ifstream ifs("./quine.cpp");
	if (!ifs) {
		return 1;
	}

	std::string line;
	while (std::getline(ifs, line)) {
		std::cout << line << '\n';
	}

	ifs.close();

	return 0;
}