#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

/*
1. Write a program that produces the sum of all the numbers in a file of whitespace-separated integers.
*/

//If the file contains a value other tan a number, it will stop the sum at that point
int main() {
	int sum = 0;
	const std::string FILE_NAME = "numbers.txt";

	try {
		std::ifstream ist(FILE_NAME);
		if (!ist) throw std::runtime_error("Can't open input file.");

		for (int i; ist >> i;) {
			sum += i;
		}
		std::cout << "The sum of the numbers in " << FILE_NAME << " file is: " << sum;
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	return 0;
}