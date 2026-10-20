#include <iostream>
#include <vector>

/*
10. Write a function maxv() that returns the largest element of a vector argument.
*/

void error(std::string s) {
	throw std::runtime_error(s);
}

int maxv(const std::vector<int>& vec) {
	
	if (vec.empty()) error("maxv(): El vector no puede estar vacio.");
	
	int max = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] > max) max = vec[i];
	}

	return max;
}

int main() {

	std::vector<int> vec = {6,2,3,4,5};
	
	try {
		std::cout << maxv(vec);
	}
	catch (const std::runtime_error& e) {
		std::cout << "[ERROR]: " << e.what() << "\n";
	}

	return 0;
}