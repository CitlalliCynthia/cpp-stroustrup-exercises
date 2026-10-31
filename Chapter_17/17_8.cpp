#include <iostream>

/*
8. Do exercise 7 again, but this time read into a std::string rather than to memory you put on the free store (string knows how to use the free store for you).
*/

int main() {

	std::string str = "";

	for (char temp; std::cin.get(temp);) {
		if (temp == '!')  break;

		str += temp;
	}

	std::cout << str;

	return 0;
}