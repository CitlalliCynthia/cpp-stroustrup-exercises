#include <iostream>
#include <string>
#include <stdexcept>
#include <regex>
#include "10_6.h"

/*
6. Define a Roman_int class for holding Roman numerals (as ints) with a << and >>. Provide Roman_int with an
as_int() member that returns the int value, so that if r is a Roman_int, we can write cout << "Roman" << r << "
equals " << r.as_int() << '\n';.

7. Make a version of the calculator from Chapter 7 that accepts Roman numerals rather than the usual Arabic ones, for example, XXI + CIV == CXXV.
*/

namespace Roman {
	
	//Constructors
	Roman_int::Roman_int(const std::string& s) {
		setRomanChar(s);
	}
	Roman_int::Roman_int(int i) {
		setRomanInt(i);
	}
	
	//nonmodifying operations
	//const std::string& getRoman() const { return romanChar; }
	int Roman_int::as_int() const {
		int sum = 0;
		size_t size = romanChar.size();
			
		if (size == 0) throw std::runtime_error("Nothing was introduced.");
			
		for (size_t i = 0; i < size; i++) {
			int current = romanValues(romanChar[i]);

			//if there is a lesser number (and not multiples of 5) before a greater number, sustract it
			if (i + 1 < size && current < romanValues(romanChar[i + 1])) sum -= current;	
			else sum += current;
		}
			
		return sum;
	}

	//std::string romanChar;
	//modifying operations
	void Roman_int::setRomanChar(const std::string& s) {
		std::regex patron("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");

		if (!std::regex_match(s, patron) || s == "") {
			throw std::runtime_error("Invalid Roman notation!");
		}

		romanChar = s;
	}

	void Roman_int::setRomanInt(int number) {
		if (number <= 0 || number > 3999) {
			throw std::runtime_error("Number out of range (1-3999).");
		}

		std::string result = "";

		//Extract thousands (e.g., 2026 -> 2)
		int thousands = number / 1000;
		result += generateRomanDigit(thousands, 'M', '?', '?'); //? are placeholders here

		//Extract hundreds (e.g., 900 -> 9)
		int hundreds = (number % 1000) / 100;
		result += generateRomanDigit(hundreds, 'C', 'D', 'M');

		//Extract tens (e.g., 40 -> 4)
		int tens = (number % 100) / 10;
		result += generateRomanDigit(tens, 'X', 'L', 'C');

		//Extract units (e.g., 7 -> 7)
		int units = number % 10;
		result += generateRomanDigit(units, 'I', 'V', 'X');

		romanChar = result;
	}

	//nonmodifying operations
	std::string Roman_int::generateRomanDigit(int digit, char unit, char five, char ten) const{
		std::string res = "";
		if (digit == 0) return res;

		if (digit <= 3) {
			res.append(digit, unit);
		}
		else if (digit == 4) {
			res += unit;
			res += five;
		}
		else if (digit <= 8) {
			res += five;
			res.append(digit - 5, unit);
		}
		else if (digit == 9) {
			res += unit;
			res += ten;
		}
		return res;
	}

	std::ostream& operator<<(std::ostream& ost, const Roman_int& roman) {
		ost << roman.getRoman();
		return ost;
	}

	std::istream& operator>>(std::istream& ist, Roman_int& roman) {
		std::string temp;
		ist >> temp;
		if (temp.empty()) return ist;

		if (std::isdigit(temp[0])) {
			roman = Roman_int(std::stoi(temp));
		}
		else {
			roman = Roman_int(temp);
		}
		return ist;
	}

	int romanValues(char c) {
		switch (c) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return -1;
		}
	}
}

int main() {

	try {
		Roman::Roman_int romanValue("XIX");
		std::cout << romanValue << " " << romanValue.as_int() << "\n";

		Roman::Roman_int romanValue2(19);
		std::cout << romanValue2 << " " << romanValue2.as_int();
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what();
	}	

	return 0;
}