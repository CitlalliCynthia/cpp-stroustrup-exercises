#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

/*
9. Write a program that takes two files containing sorted whitespace-separated words and merges them, preserving order.
*/

std::istream& getWords(std::istream& ist, std::vector<std::string>& vec) {
	std::string temp;
	while (ist >> temp) {
		vec.push_back(temp);
	}
	return ist;
}

void getSorted(std::vector<std::string>& vec) {
	sort(vec.begin(),vec.end());
}

int main() {
	
	try {
		std::ifstream ist1("file1.txt");
		std::ifstream ist2("file2.txt");
		
		if (!ist1 or !ist2) throw std::runtime_error("Can't open input file(s).");

		std::vector<std::string> words;

		getWords(ist1, words);
		getWords(ist2, words);

		getSorted(words);

		for (std::string& s : words) {
			std::cout << s << " ";
		}

	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what();
	}
	return 0;
}