#include <iostream>

/*
4. Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free store. Do not use any standard library functions.
*/

char* strDup(const char* cString) {
	if (cString == NULL) return NULL;

	const char* s = cString;
	int size = 0;
	while (*s != '\0') {
		size++;
		s++;
	}
	size++; //to count the char terminator

	char* copy = new char[size];
	for (int i = 0; i < size; i++) {
		copy[i] = cString[i];
	}

	return copy;
}

int main() {

	char cString[] = "Hello World!";

	char* newString = strDup(cString);

	if (newString != NULL) {
		std::cout << "Copied string: " << newString;
		delete[] newString;
	}

	return 0;
}