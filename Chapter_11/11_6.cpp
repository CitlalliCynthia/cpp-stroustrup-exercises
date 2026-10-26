#include <iostream>
#include <string>

/*
6. Write a program that replaces punctuation with whitespace. Consider . (dot), ; (semicolon), , (comma), ? (question mark), - (dash), ' (single quote) punctuation characters. Don’t modify characters within a pair of double quotes ("). For example, “- don't use the as-if rule.” becomes “ don t use the as if rule ”
*/

/*
Assumption: double quotes always come in perfect, well-ordered pairs (one opens, one closes), and there will be no identical nested double quotes inside the quotation. This isn't handled: "she said "don't do that" to me"
*/

bool replaceable(char c) {
	switch (c) {
	case '.': case ';': case ',': case '?': case '-': case '\'':
		return true;
	default: return false;
	}
}

void replacePunctuation(std::string& s) {
	std::string finalWord = "";
	bool flag = false;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '\"') {
			flag = !flag;
			finalWord += s[i];
		}
		else if (flag) {
			finalWord += s[i];
		}
		else {
			if (replaceable(s[i])) {
				finalWord += " ";
			}
			else finalWord += s[i];
		}
	}

	std::cout << "Final phrase: " << finalWord;
}

int main() {

	std::cout << "Introduce a phrase: ";
	std::string phrase;
	std::getline(std::cin, phrase);

	replacePunctuation(phrase);

}