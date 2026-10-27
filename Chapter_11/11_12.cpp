#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

/*
12. Reverse the order of characters in a text file. For example, asdfghjkl becomes lkjhgfdsa. Warning: There is no really good, portable, and efficient way of reading a file backward.
*/

void reverseOrder(std::istream& ist, std::ostream& ost) {
	std::vector<char> inputFile;
	for (char c; ist.get(c);) {
		inputFile.push_back(c);
	}

	for (int i = inputFile.size() - 1; i >= 0; i--) {
		ost << inputFile[i];
	}
}

int main() {

	try {
		std::ifstream ist("input.txt");
		if (!ist) throw std::runtime_error("Can't open input file.");

		std::ofstream ost("output.txt");
		if (!ost) throw std::runtime_error("Can't open output file.");

		reverseOrder(ist,ost);

		std::cout << "Output file created!\n";
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what();
	}
	return 0;
}
