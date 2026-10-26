#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

/*
2. Write a program that given a file name and a word outputs each line that contains that word together with the line number. Hint: getline()
*/

void printCounterLines(std::istream& ist, const std::string& word) {
	std::string s;
	int count = 0;

	while (std::getline(ist, s)) {
		int times = 0;
		count++;

		std::stringstream ss(s);
		for (std::string sTemp; ss >> sTemp;) {
			if (sTemp == word) {
				times++;
			}
		}
		if(times > 1) std::cout << "Line (" << count << ") (" << times << " appeareances): " << s << "\n";
		else if (times > 0) std::cout << "Line (" << count << "): " << s << "\n";
	}
}

int main() {

	try {
		std::ifstream ist("input.txt");
		if (!ist) throw std::runtime_error("Can't open input file.");

		std::string word;
		std::cout << "Please introduce the word to search: ";
		std::cin >> word;

		printCounterLines(ist, word);
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what();
	}

	return 0;
}