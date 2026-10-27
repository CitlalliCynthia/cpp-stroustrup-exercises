#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/*
10. Write a function vector<string> split(const string& s) that returns a vector of whitespace-separated substrings from the argument s.
*/

std::vector<std::string> split(const std::string& s) {
	std::vector<std::string> substrings;
	std::istringstream ss(s);

	for (std::string temp; ss >> temp;) {
		substrings.push_back(temp);
	}

	return substrings;
}

int main() {
	
	std::vector<std::string> result = split("I love cats!");
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << "\n";
	}

	return 0;
}