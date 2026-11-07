#include <iostream>

/*
7. Write versions of the cat_dot()s from the previous exercises to take C-style strings as arguments and return a
free-storeallocated C-style string as the result. Do not use standard library functions or types in the
implementation. Test these functions with several strings. Be sure to free (using delete) all the memory you 
allocated from free store (using new).
Compare the effort involved in this exercise with the effort involved for exercises 5 and 6.
*/

/*//EXERCISE 5
std::string cat_dot(const std::string& s1, const std::string& s2) {
	return s1 + '.' + s2;
}
*/

/*//EXERCISE 6
std::string cat_dot(const std::string& s1, const std::string& s2, const std::string& s3) {
	return s1 + s3 + s2;
}
*/

//EXERCISE 5
char* cat_dot(const char s1[], const char s2[]) {
	
	const char* p1 = s1;
	while (*p1) p1++;
	int size1 = p1 - s1;

	const char* p2 = s2;
	while (*p2) p2++;
	int size2 = p2 - s2;

	char* duplicated = new char[size1 + size2 + 2]; //For the point and the end of string
	char* dupBeginning = duplicated;

	while(*s1) {
		*duplicated = *s1;
		duplicated++;
		s1++;
	}

	*duplicated = '.';
	duplicated++;
	
	while(*s2) {
		*duplicated = *s2;
		duplicated++;
		s2++;
	}

	*duplicated = '\0';

	return dupBeginning;
}

//EXERCISE 6
char* cat_dot(const char s1[], const char s2[], const char s3[]) {

	const char* p1 = s1;
	while (*p1) p1++;
	int size1 = p1 - s1;

	const char* p2 = s2;
	while (*p2) p2++;
	int size2 = p2 - s2;

	const char* p3 = s3;
	while (*p3) p3++;
	int size3 = p3 - s3;

	char* duplicated = new char[size1 + size2 + size3 + 1]; //For the end of string
	char* dupBeginning = duplicated;

	while (*s1) {
		*duplicated = *s1;
		duplicated++;
		s1++;
	}

	while (*s3) {
		*duplicated = *s3;
		duplicated++;
		s3++;
	}

	while (*s2) {
		*duplicated = *s2;
		duplicated++;
		s2++;
	}

	*duplicated = '\0';

	return dupBeginning;
}

int main() {

	char arr1[] = "Hello";
	char arr2[] = "World!";
	char arr3[] = "_._";

	char* p1 = cat_dot(arr1, arr2);

	std::cout << p1 << "\n";

	char* p2 = cat_dot(arr1, arr2, arr3);

	std::cout << p2 << "\n";

	delete[] p1;
	delete[] p2;

	return 0;
}