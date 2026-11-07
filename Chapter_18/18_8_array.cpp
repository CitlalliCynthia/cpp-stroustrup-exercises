#include <iostream>
#include <string>

/*
8. Rewrite all the functions in §18.7 to use the approach of making a backward copy of the string and then 
comparing; for example, take "home", generate "emoh", and compare those two strings to see that they are 
different, so home isn’t a palindrome.
*/

bool isPalindrome(const char s[], int n) {

	const char* left = s;

	char* copy = new char[n+1]; //End terminator
	char* endCopy = &copy[n-1];
	copy[n] = '\0';

	while (endCopy >= copy) 
		*endCopy-- = *left++;

	const char* p_orig = s;
	const char* p_copy = copy;
	bool result = true;

	for (int i = 0; i < n; i++) {
		if (*p_copy++ != *p_orig++) {
			result = false;
			break;
		}
	}

	delete[] copy;

	return result;
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