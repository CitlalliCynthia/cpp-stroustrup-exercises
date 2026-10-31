#include <iostream>

/*
5. Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C-style string x in s.
*/

//'s' is the string to search and 'x' is the substring to find
char* findx(const char* s, const char* x) {
	if (s == NULL || x == NULL) {
		return NULL;
	}

	if(*x == '\0') { //empty string
		return (char*)s;
	}

	while (*s != '\0') {
		const char* pS = s;
		const char* pX = x;

		while (*pS != '\0' && *pX != '\0' && *pS == *pX) {
			pS++;
			pX++;
		}

		if (*pX == '\0') {
			return (char*)(s);
		}

		s++;
	}

	return NULL;
}

int main() {
	char string1[] = "Hello woworld!";
	char string2[] = "worl";
	char* coincidence = findx(string1,string2);
	if(coincidence != NULL) 
		std::cout << (void*)coincidence << " == " << (void*)&(string1[8]) << "\n";
	else std::cout << "No coincidence found!\n";
}