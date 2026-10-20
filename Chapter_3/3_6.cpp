//To sort three given integers
#include <iostream>
#include <string>

int main() {

	std::cout << "Please enter three integer values separated by a space: ";
	int val1, val2, val3;
	std::cin >> val1 >> val2 >> val3;

	int temp;
	while (true) {
		if (val1 > val2) {
			temp = val2;
			val2 = val1;
			val1 = temp;
		}
		else if (val2 > val3) {
			temp = val3;
			val3 = val2;
			val2 = temp;
		}
		else break;
	}

	std::cout << "The numbers arranged are: " << val1 << ", " << val2 << ", " << val3;
}