#include <iostream>
#include <cmath>

int main() {

	double a, b, c;
	double x1, x2;

	std::cout << "Please introduce the value of a, b, and c."
		<< " For example (12 34 52): ";

	std::cin >> a >> b >> c;

	double discriminant = (b * b) - (4 * a * c);

	if (a == 0) {
		std::cout << "\nError: 'a' cannot be 0 (it's not a quadratic equation).\n";
	}
	else if (discriminant < 0) {
		std::cout << "\nError: The equation has no real roots (the discriminant is negative).\n";
	}
	else {

		x1 = (-b + sqrt(discriminant)) / (2 * a);
		x2 = (-b - sqrt(discriminant)) / (2 * a);

		std::cout << "\nX1 = " << x1 << "\nX2 = "
			<< x2;
	}

	return 0;
}