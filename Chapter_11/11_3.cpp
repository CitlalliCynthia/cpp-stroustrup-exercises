#include <iostream>
#include <fstream>
#include <stdexcept>

/*
3. Write a program that removes all vowels from a file (“disemvowels”). For example, Once upon a time! becomes nc
pn tm!. Surprisingly often, the result is still readable; try it on your friends.
*/

bool isVowel(char c) {
	switch (c) {
	case 'a': case 'e': case 'i': case 'o': case 'u':
	case 'A': case 'E': case 'I': case 'O': case 'U':
		return true;
	default:
		return false;
	}
}

void removeVowels(std::istream& ist, std::ostream& ost) {
	char currentChar;
	while (ist.get(currentChar)) {
		if (!isVowel(currentChar)) ost << currentChar;
	}
}


int main() {
	
	try {
		std::ifstream ist("disemvowels.txt");
		if (!ist) throw std::runtime_error("Can't open input file.");

		removeVowels(ist, std::cout);
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what();
	}

	return 0;
}