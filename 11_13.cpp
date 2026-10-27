#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

/*
13. Reverse the order of words (defined as whitespace-separated strings) in a file. For example, Norwegian Blue parrot becomes parrot Blue Norwegian. You are allowed to assume that all the strings from the file will fit into memory at once.
*/

void reverseOrder(std::istream& ist, std::ostream& ost) {
	std::vector<std::string> inputFile;
	for (std::string temp; ist >> temp;) {
		inputFile.push_back(temp);
	}

	for (int i = inputFile.size() - 1; i >= 0; i--) {
		if (i == 0) ost << inputFile[i];
		else ost << inputFile[i] << " ";
	}
}

int main() {

	try {
		std::ifstream ist("input.txt");
		if (!ist) throw std::runtime_error("Can't open input file.");

		std::ofstream ost("output.txt");
		if (!ost) throw std::runtime_error("Can't open output file.");

		reverseOrder(ist, ost);

		std::cout << "Output file created!\n";
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what();
	}
	return 0;
}