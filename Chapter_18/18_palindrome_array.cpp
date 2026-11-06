#include <iostream>

bool isPalindrome(const char s[], int n) {

	const char* left = s;
	const char* right = &s[n - 1];

	while (left < right) {
		if (*left != *right) return false;

		left++;
		right--;
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
		if (!isPalindrome(s, strlen(s))) std::cout << " not";
		std::cout << " a palindrome\n";
	}

	return 0;
}