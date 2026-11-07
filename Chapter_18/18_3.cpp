#include <iostream>

/*
3. Write a function, int strcmp(const char* s1, const char* s2), that compares C-style strings. Let it return a
negative number if s1 is lexicographically before s2, zero if s1 equals s2, and a positive number if s1 is 
lexicographically after s2. Do not use any standard library functions. Do not use subscripting; use the 
dereference operator * instead.
*/

int strcmp1(const char* s1, const char* s2) {

	while (*s1 && *s2) {
		if (*s1 != *s2) return *s1 - *s2;

		s1++;
		s2++;
	}

	return *s1 - *s2;
}


int main() {

	
	char array[] = "helloa";
	char array2[] = "hello";

	//Positive
	std::cout << strcmp1(array, array2) << "\n";

	//Negative
	std::cout << strcmp1(array2, array) << "\n";

	//Zero
	std::cout << strcmp1(array, array) << "\n";
	
	return 0;
}