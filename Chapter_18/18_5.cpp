#include <iostream>
#include <string>

/*
5. Write a function, string cat_dot(const string& s1, const string& s2), that concatenates two strings with a dot
in between. For example, cat_dot("Niels", "Bohr") will return a string containing Niels.Bohr.

6. Modify cat_dot() from the previous exercise to take a string to be used as the separator (rather than dot) as
its third argument.
*/

/*//EXERCISE 5
std::string cat_dot(const std::string& s1, const std::string& s2) {
	return s1 + '.' + s2;
}
*/

//EXERCISE 6
std::string cat_dot(const std::string& s1, const std::string& s2, const std::string& s3) {
	return s1 + s3 + s2;
}

int main() {

	std::cout << cat_dot("Hello","World!","_");
	
	return 0;
}