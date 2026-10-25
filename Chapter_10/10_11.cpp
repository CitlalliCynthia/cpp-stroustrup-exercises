#include <iostream>
#include <fstream>
#include <stdexcept>

/*
11. Write a program that produces the sum of all the whitespace-separated integers in a text file. For example, bears: 17 elephants 9 end should output 26.
*/

int getSumOfInput(std::istream& ist) {
    int temp = 0;
    int sum = 0;

    while (true) {
        ist >> temp;
        if (ist.fail()) {
            if (ist.eof()) break;

            ist.clear();
            ist.ignore(1000, ' ');
            continue;
        }
        sum += temp;
    }
    return sum;
}

int main() {

	try {
		std::ifstream ist("input.txt");
		if (!ist) throw std::runtime_error("Can't open input file.");
		
		int sum = getSumOfInput(ist);

		std::cout << "The sum of the integers in the text is: " << sum;

	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what();
	}

	return 0;
}