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

int main() {

	for (std::string s; std::cin >> s;) {
		std::cout << s << " is";
		if (!isPalindrome(s)) std::cout << " not";
		std::cout << " a palindrome\n";
	}

	return 0;
}