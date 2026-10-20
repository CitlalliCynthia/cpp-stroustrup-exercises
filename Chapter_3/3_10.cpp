//Basic operations
#include <iostream>

int main() {
	std::cout << "Please introduce an operation followed by two operands, separated by an space: ";
	char operation;
	double operand1, operand2;
	double result = 0.0;
	std::cin >> operation >> operand1 >> operand2;

	if (operation == '+') result = operand1 + operand2;
	else if (operation == '-') result = operand1 - operand2;
	else if (operation == '*') result = operand1 * operand2;
	else if (operation == '/') result = operand1 / operand2;
	else return 0;

	std::cout << "Your result is: " << result;
}