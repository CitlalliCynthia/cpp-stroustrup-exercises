#include <iostream>
#include <vector>

/*
1. Define a global vector<int> gv; initialize it with ten ints, 1, 2, 4, 8, 16, etc.
2. Define a function f() taking a vector<int> argument.
3. In f():
a. Define a local vector<int> lv with the same number of elements as the argument vector.
b. Copy the values from gv into lv.
c. Print out the elements of lv.
d. Define a local vector<int> lv2; initialize it to be a copy of the argument vector.
e. Print out the elements of lv2.
4. In main():
a. Call f() with gv as its argument.
b. Define a vector<int> vv, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
c. Call f() with vv as its argument.
*/

std::vector<int> gv(10);

void f(const std::vector<int>& param) {

	std::vector<int> lv(param.size());

	for (size_t i = 0; i < lv.size(); ++i) {
		lv[i] = gv[i];
	}

	for (int i = 0; i < lv.size(); i++) {
		std::cout << lv[i] << " ";
	}
	std::cout << "\n";

	std::vector<int> lv2 = param;

	for (int i = 0; i < lv2.size(); i++) {
		std::cout << lv2[i] << " ";
	}
	std::cout << "\n";
}

int main() {

	for (int i = 0; i < 10; i++) {
		gv[i] = 1 << i;
		std::cout << gv[i] << " ";
	}
	std::cout << "\n";

	f(gv);

	std::vector<int> vv;

	int current_factorial = 1;
	for (int i = 0; i < 10; i++) {
		current_factorial *= i + 1;
		vv.push_back(current_factorial);
	}
	
	f(vv);

	return 0;
}