#include <iostream>

/*
1. Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free
store. Do not use any standard library functions. Do not use subscripting; use the dereference operator *
instead.
*/

char* strdup1(const char* cString) {
	
	if (cString == NULL) return NULL;
	
	const char* temp = cString;
	int size = 0;
	while (*temp) {
		size++;
		temp++;
	}

	char* newString = new char[size+1];

	temp = cString;
	char* stringIterator = newString;

	while (*temp) {
		*stringIterator = *temp;
		temp++;
		stringIterator++;
	}

	*stringIterator = '\0';
	
	return newString;
}


int main() {

	char array[] = "Hello World!";
	
	char* copyArray = strdup1(array);

	for (int i = 0; *(copyArray+i); i++) {
		std::cout << *(copyArray + i);
		
	}

	delete[] copyArray;
	
	return 0;
}