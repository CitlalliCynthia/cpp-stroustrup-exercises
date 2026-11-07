#include <iostream>
#include <string>

bool isPalindrome(const std::string& s) {

	std::string copy;

	for (int i = s.length() - 1; i >= 0; i--) {
		copy += s[i];
	}

	for (int i = 0; i < s.length(); i++) {
		if (copy[i] != s[i]) return false;
	}

	return true;
}

std::istream& read_word(std::istream& ist, char* buffer, int max) {
	ist.width(max);
	ist >> buffer;
	return ist;
}

int main() {

	const int max = 128;
	for (char s[max]; read_word(std::cin, s, max);) {
		std::cout << s << " is";
		if (!isPalindrome(s)) std::cout << " not";
		std::cout << " a palindrome\n";
	}

	return 0;
}