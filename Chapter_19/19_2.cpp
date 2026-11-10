#include <iostream>
#include <vector>
#include <stdexcept>

/*
2. Write a template function that takes a vector<T> vt and a vector<U> vu as arguments and returns the sum of all
vt[i]*vu[i]s.
*/

template<typename R, typename T, typename U>
R f(const std::vector<T>& vt, const std::vector<U>& vu) {
	
	if (vt.size() != vu.size()) throw std::runtime_error("Vectors of different sizes!");

	R sum = R();

	for (int i = 0; i < vt.size(); i++) {
		sum += vt[i] * vu[i];
	}

	return sum;
}

int main() {

	try {
		std::vector<int> v_int;
		v_int.push_back(2);
		v_int.push_back(3);

		std::vector<double> v_double;
		v_double.push_back(1.5);
		v_double.push_back(2.5);

		double result = f<double>(v_int, v_double);

		std::cout << "Result: " << result << "\n";

		v_double.push_back(3.5);

		result = f<double>(v_int, v_double);

		std::cout << "Result: " << result << "\n";
	}
	catch (const std::runtime_error& e) {
		std::cout << "\nError: " << e.what() << "\n";
	}

	return 0;
}