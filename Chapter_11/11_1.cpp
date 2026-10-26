#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cctype>

/*
1. Write a program that reads a text file and converts its input to all lower case, producing a new file.
*/

std::ostream& convertToLower(std::istream& ist, std::ostream& ost) {
	char ch;
	while (ist.get(ch)) {
		ost << static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
	}

	return ost;
}


int main() {

	try{
		std::ifstream ist("input.txt");
		if (!ist) throw std::runtime_error("Can't open input file.");

		std::ofstream ost("output.txt");
		if (!ost) throw std::runtime_error("Can't open output file.");

		convertToLower(ist, ost);

		std::cout << "Created output file successfully.";
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what();
	}
	
	return 0;
}