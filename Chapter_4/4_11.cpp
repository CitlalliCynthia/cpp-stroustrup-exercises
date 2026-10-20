#include <iostream>

/*
Write a program that performs as a very simple calculator. Your calculator should be able to handle the four basic math
operations — add, subtract, multiply, and divide — on two input values. Your program should prompt the user to enter
three arguments: two double values and a character to represent an operation. If the entry arguments are 35.6, 24.1, and
'+', the program output should be The sum of 35.6 and 24.1 is 59.7. In Chapter 6 we look at a much more
sophisticated simple calculator.
*/

int main() {

	double number1, number2, result = 0;
	char sign;

	std::cout << "Please enter two numbers and a sign (+, -, *, /)."
		<< " For example (2.3 + 5): ";

	std::cin >> number1 >> sign >> number2;

	switch (sign) {
	case '+':
		result = number1 + number2;
		break;
	case '-':
		result = number1 - number2;
		break;
	case '*':
		result = number1 * number2;
		break;
	case '/':
		if(number2 != 0) result = number1 / number2;
	}

	if (number2 != 0) std::cout << "\nThe result is: " << result;
	else std::cout << "\nYou can't divide by 0!";

	return 0;
}