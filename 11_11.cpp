#include <iostream>
#include <string>
#include <vector>

/*
11. Write a function vector<string> split(const string& s, const string& w) that returns a vector of whitespaceseparated substrings from the argument s, where whitespace is defined as “ordinary whitespace” plus the characters in w.
*/

std::vector<std::string> split(const std::string& s, const std::string& w) {
	std::vector<std::string> substringsVec;
	std::string fullSeparators = " " + w;
	std::string substr = "";
	bool flag = false;

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < fullSeparators.size(); j++) {
			if (s[i] == fullSeparators[j]) {
				flag = true;
				break;
			}
		}

		if (flag) {
			if (!substr.empty()) substringsVec.push_back(substr);
			substr = "";
			flag = !flag;
		}
		else {
			substr += s[i];
		}
	}
	if (!substr.empty()) substringsVec.push_back(substr);

	return substringsVec;
}

int main() {
	std::vector<std::string> result = split(" I love,cats!;they:are so, , ,cute!: ",";,:");

	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << "\n";
	}
	
	return 0;
}