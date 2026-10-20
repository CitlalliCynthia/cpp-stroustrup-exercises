#include <iostream>

int main() {
	short i=0;

	while (i <= 25) {
		char actualChar = char('a' + i++);
		std::cout << actualChar << " " << short(actualChar) << "\n";
	}

	std::cout << "\n";

	for (i = 0; i <= 25; i++) {
		char actualChar = char('a' + i);
		std::cout << actualChar << " " << short(actualChar) << "\n";
	}

	std::cout << "\n";
	////////////////////////////////////////////////////////////////
	i = 0;
	while (i <= 25) {
		char actualChar = char('A' + i++);
		std::cout << actualChar << " " << short(actualChar) << "\n";
	}

	std::cout << "\n";

	for (i = 0; i <= 25; i++) {
		char actualChar = char('A' + i);
		std::cout << actualChar << " " << short(actualChar) << "\n";
	}
}