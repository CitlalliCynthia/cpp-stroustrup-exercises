#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <stdexcept>
#include <sstream>

/*
6. Write a program that replaces punctuation with whitespace. Consider . (dot), ; (semicolon), , (comma), ? (question mark), - (dash), ' (single quote) punctuation characters. Don’t modify characters within a pair of double quotes ("). For example, “- don't use the as-if rule.” becomes “ don t use the as if rule ”

7. Modify the program from the previous exercise so that it replaces don't with do not, can't with cannot, etc.; leaves hyphens within words intact (so that we get “ do not use the as-if rule ”); and converts all characters to lower case.
*/

/*
Assumption: double quotes always come in perfect, well-ordered pairs (one opens, one closes), and there will be no identical nested double quotes inside the quotation. This isn't handled: "she said "don't do that" to me"
*/

bool replaceable(char c) {
	switch (c) {
	case '.': case ';': case ',': case '?': case '-':
		return true;
	default: return false;
	}
}

std::string isContraction(std::string& s) {

	std::ifstream ifst("contractions.txt");

	if (!ifst) throw std::runtime_error("Can't open output file.");

	std::string compare;
	while (ifst >> compare){
		std::string fullContraction;
		ifst >> fullContraction;
		if (s == compare) {
			return fullContraction;
		}
	}
	return s;
}

std::string cleanPhrase(std::string& s) {
	std::istringstream ss(s);
	std::string finalPhrase = "";

	for (std::string wordTemp; ss >> wordTemp;) {
		finalPhrase += isContraction(wordTemp) + " ";
	}

	return finalPhrase;
}

std::string replacePunctuation(std::string& s) {
	std::string finalWord = "";
	bool flag = false;

	for (int i = 0; i < s.size(); i++) {
		s[i] = std::tolower(s[i]);
		if (s[i] == '\"') {
			flag = !flag;
			finalWord += s[i];
		}
		else if (flag) {
			finalWord += s[i];
		}
		else if (i < s.size() - 1 && i >= 1 && s[i] == '-') {
			if (isalnum(s[i - 1]) && isalnum(s[i + 1]))
				finalWord += s[i];
		}
		else {
			if (replaceable(s[i])) {
				finalWord += " ";
			}
			else finalWord += s[i];
		}
	}

	return finalWord;
}

int main() {//don't use the as-if rule.

	try {
		std::cout << "Introduce a phrase: ";
		std::string phrase;
		std::getline(std::cin, phrase);

		phrase = cleanPhrase(phrase);
		phrase = replacePunctuation(phrase);

		std::cout << "Final phrase: " << phrase;
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what();
	}
}