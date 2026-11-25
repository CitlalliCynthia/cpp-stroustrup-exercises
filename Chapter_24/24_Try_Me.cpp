#include <iostream>
#include <iomanip>

/*
Replace 333 in the example with 10 and run the example again. What result would 
you expect? What result did you get? You have been warned!
*/

int main() {
	float x = 1.0 / 10;
	float sum = 0;
	for (int i = 0; i < 10; ++i) sum += x;
	std::cout << std::setprecision(15) << sum << "\n";

	return 0;
}
