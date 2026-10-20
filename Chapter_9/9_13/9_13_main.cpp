#include <iostream>
#include "9_13.h"

int main() {
	Rational::Rational a(1,2);
	Rational::Rational b(1, 2);

	std::cout << a + b << "\n";

	std::cout << a * b << "\n";

	std::cout << a / b << "\n";

	std::cout << a - b << "\n";

	std::cout << static_cast<double>(a) << "\n";

	return 0;
}