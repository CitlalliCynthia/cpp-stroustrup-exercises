#include <iostream>
#include <string>

bool isPalindrome(const std::string& s) {

	if (s.length() <= 1) return true;

	const char* left = &s[0];
	const char* right = &s[s.length()-1];

	while (left < right) {
		if (*left != *right) return false;
		
		left++;
		right--;
	}

	return true;
}

int main() {

	std::string s = "anna";
	
	if (isPalindrome(s)) std::cout << "It's a palindrome!\n";
	else std::cout << "It's not a palindrome!\n";

	return 0;
}