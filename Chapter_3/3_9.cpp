//Spelling numbers with strings! 
#include <iostream>
#include <string>

int main() {
	std::cout << "Please spell out the name of a numerical digit: ";
	std::string number;
	std::cin >> number;

	std::cout << "Your number is: ";
	if (number == "zero") std::cout << "0";
	else if (number == "one") std::cout << "1";
	else if (number == "two") std::cout << "2";
	else if (number == "three") std::cout << "3";
	else if (number == "four") std::cout << "4";
	else std::cout << "Not a number I know!";
}