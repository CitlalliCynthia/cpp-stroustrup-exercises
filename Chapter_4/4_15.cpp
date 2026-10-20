#include <iostream>

int main() {

	int grains = 1;
	//double grains = 1;

	constexpr int SQUARES = 64;

	for (int counter = 1; counter < SQUARES; counter++) {
		grains *= 2;
		std::cout << "Square " << counter << " is " << grains << " grains\n";
	}

	std::cout << "The number of grain needed for " << SQUARES << " is : " << grains;

	return 0;
}