#include <iostream>

/*
3. Write a function, void to_lower(char* s), that replaces all uppercase characters in the C-style string s with their lowercase equivalents. For example, Hello, World! becomes hello, world!. Do not use any standard library functions. A C-style string is a zero-terminated array of characters, so if you find a char with the value 0 you are at the end.
*/

void to_lower(char* s) {
	while (*s != '\0') {
		if (*s >= 'A' && *s <= 'Z') {
			*s += 32;
		}
		s++;
	}
}

int main() {

	char cString[] = "Hello World! 234";
	to_lower(cString);
	std::cout << cString;
	
	return 0;
}