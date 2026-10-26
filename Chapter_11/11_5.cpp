#include <iostream>
#include <string>
#include <cctype>

/*
5. Write a program that reads strings and for each string outputs the character classification of each character, as defined by the character classification functions presented in §11.6. Note that a character can have several classifications (e.g., x is both a letter and an alphanumeric).
*/

void printClassification(const std::string& s) {
	int alpha = 0, digit = 0, upper = 0, lower = 0, xdigit = 0, alnum = 0, print = 0, space=0;

	for (size_t i = 0; i < s.size(); i++) {
		char c = s[i];
		
		if (std::isalpha(c))  alpha++;
		if (std::isdigit(c))  digit++;
		if (std::isalnum(c))  alnum++;
		if (std::isupper(c))  upper++;
		if (std::islower(c))  lower++;
		if (std::isxdigit(c)) xdigit++;
		if (std::isprint(c))  print++;
		if (std::isspace(c))  space++;
	}
	
	if (alpha) std::cout << "\n\t(" << alpha << ") letters [isalpha()]";
	if (digit) std::cout << "\n\t(" << digit << ") digits [isdigit()]";
	if (alnum) std::cout << "\n\t\t(" << alnum << ") letters or digits [isalnum()]";
	if (upper) std::cout << "\n\t\t(" << upper << ") uppercase letters [isupper()]";
	if (lower) std::cout << "\n\t\t(" << lower << ") lowercase letters [islower()]";
	if (xdigit) std::cout << "\n\t\t(" << xdigit << ") hexadecimal digits [isxdigit()]";
	if (print) std::cout << "\n\t(" << print << ") printables [isprint()]";
	if (space) std::cout << "\n\t(" << space << ") spaces [isspace()]";

}

int main() {

	//'quit' to exit
	for (std::string s; std::cout << "\n\n: ";) {
		std::getline(std::cin >> std::ws, s); //to prevent unwanted '\n'
		if (s != "quit") printClassification(s);
		else break;
	}
	
	return 0;
}