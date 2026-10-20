//Even (par) or odd (impar)
#include <iostream>

int main() {
	std::cout << "Please introduce a number to validate whether is odd or even: ";
	int number;
	std::cin >> number;

	if (number % 2 == 0) std::cout << "The number " << number << " is even";
	else std::cout << "The number " << number << " is odd";
}