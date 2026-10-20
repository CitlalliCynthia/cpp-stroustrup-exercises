#include <iostream>

int square(int number) {
	int sum = 0;

	for (int i = 0; i < number; i++) {
		sum += number;
	}

	return sum;
}

int main() {
	constexpr int number = 4;

	std::cout << "The square of " << number << " is " << square(number);
}