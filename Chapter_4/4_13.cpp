#include <iostream>
#include <vector>
#include <string>

/*
Modify the “mini calculator” from exercise 5 to accept (just) 
single-digit numbers written as either digits or spelled out.
*/

int spelled(std::string answer) {

	std::vector<std::string> words =
	{"zero","one", "two", "three", "four", "five", "six","seven","eight","nine"};

	for (int i = 0; i < 10; i++) {
		if (answer == words[i]) return i;
	}

	return -1;
}

int main() {

	std::string number1, number2;
	int num1, num2;
	char sign;
	int result = 0;

	do {
		std::cout << "Please enter two numbers and a sign (+, -, *, /)."
			<< " For example (2 + 5) or (two + five): ";

		std::cin >> number1 >> sign >> number2;

		if (number1.size() > 1) num1 = spelled(number1);
		else num1 = std::stoi(number1);

		if (number2.size() > 1) num2 = spelled(number2);
		else num2 = std::stoi(number2);

	} while (num1 > 10 || num1 < 0 || num2 > 10 || num2 < 0);

	switch (sign) {
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		if (num2 != 0) result = num1 / num2;
	}

	if (num2 != 0) std::cout << "\nThe result is: " << result;
	else std::cout << "\nYou can't divide by 0!";

	return 0;
}