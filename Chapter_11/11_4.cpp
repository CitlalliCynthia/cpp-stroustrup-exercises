#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

/*
4. Write a program called multi_input.cpp that prompts the user to enter several integers in any combination of octal, decimal, or hexadecimal, using the 0 and 0x base suffixes; interprets the numbers correctly; and converts them to decimal form. Then your program should output the values in properly spaced columns like this:
Click here to view code image
0x43 hexadecimal converts to 67 decimal
0123 octal converts to 83 decimal
65 decimal converts to 65 decimal
*/

struct NotationData {
	int decimal;
	char suffix; //'h' (hexadecimal),'o' (octal),'d' (decimal)
};

NotationData readNotation(std::string& s) {
	NotationData temp;
	std::istringstream ss(s);
	if (s.size() > 1) {
		if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
			ss >> std::hex >> temp.decimal;
			temp.suffix = 'h';
		}
		else if (s[0] == '0') {
			ss >> std::oct >> temp.decimal;
			temp.suffix = 'o';
		}
		else {
			ss >> std::dec >> temp.decimal;
			temp.suffix = 'd';
		}
	}
	else {
		ss >> std::dec >> temp.decimal;
		temp.suffix = 'd';
	}

	char leftover;
	if (ss.fail() || ss >> leftover) { //There are chars not read (invalid input)
		throw std::runtime_error("Not a valid input!\n\n");
	}

	return temp;
}

void printNotations(const NotationData& inputData) {
	
	std::cout << std::showbase;
	
	switch (inputData.suffix) {
	case 'd':
		std::cout << std::dec << inputData.decimal << " decimal converts to " << inputData.decimal << " decimal\n";
		break;
	case 'h':
		std::cout << std::hex << inputData.decimal << " hexadecimal converts to " << std::dec << inputData.decimal << " decimal\n";
		break;
	case 'o':
		std::cout << std::oct << inputData.decimal << " octal converts to " << std::dec << inputData.decimal << " decimal\n";
		break;
	default: 
		std::cout << "Not a valid data type!\n";
	}
}

int main() {
	
	std::vector<NotationData> vec;
	
	try {
		for (std::string s; std::cin >> s;) {
			NotationData ndTemp = readNotation(s);
			vec.push_back(ndTemp);
		}
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what();
	}

	for (int i = 0; i < vec.size(); i++) {
		printNotations(vec[i]);
	}

	return 0;
}