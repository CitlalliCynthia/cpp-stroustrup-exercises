#include <iostream>
#include <vector>
#include <algorithm>

int main() {

	int max, min;
	std::cout << "First introduce two numbers: ";
	std::cin >> max >> min;

	if (max < min) {
		int temp = max;
		max = min;
		min = temp;
	}

	std::cout << "The largest is " << max << " and the smallest is " << min << "\n";

	std::cout << "Please write another number: ";

	for (int temp; std::cin >> temp;) {
		if (temp > max) {
			max = temp;
			std::cout << max << " is the largest so far \n";
		}
		else if (temp < min) {
			min = temp;
			std::cout << min << " is the smallest so far \n";
		}

		std::cout << "Please write another number: ";
	}
}