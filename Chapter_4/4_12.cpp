#include <iostream>
#include <vector>
#include <string>

/*
Make a vector holding the ten string values "zero", "one", . . . "nine". Use that in a program that converts a digit to
its corresponding spelled-out value; e.g., the input 7 gives the output seven. Have the same program, using the same
input loop, convert spelled-out numbers into their digit form; e.g., the input seven gives the output 7.
*/

int main() {

	int answer;
	std::vector<std::string> words =
	{"zero","one", "two", "three", "four", "five", "six","seven","eight","nine"};

	std::cout << "Please introduce a number [0-9]: ";

	std::cin >> answer;

	std::cout << "The number you've chosen is: " << words[answer];

	return 0;
}