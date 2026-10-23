#include <iostream>
#include <string>
#include <stdexcept>
#include <regex>

/*
6. Define a Roman_int class for holding Roman numerals (as ints) with a << and >>. Provide Roman_int with an
as_int() member that returns the int value, so that if r is a Roman_int, we can write cout << "Roman" << r << "
equals " << r.as_int() << '\n';.
*/

namespace Roman {
	
	int romanValues(char);
	
	class Roman_int {

	public:
		Roman_int() {};
		Roman_int(const std::string& s) {
			setRomanChar(s);
		}
	
		//nonmodifying operations
		const std::string& getRoman() const { return romanChar; }
		
		int as_int() const {
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

		//modifying operations
		void setRomanChar(const std::string& s) {
			std::regex patron("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");

			if (!std::regex_match(s, patron) || s == "") {
				throw std::runtime_error("Invalid Roman notation!");
			}

			romanChar = s;
		}

	private:
		std::string romanChar;
	};

	std::ostream& operator<<(std::ostream& ost, const Roman_int& roman) {
		ost << roman.getRoman();
		return ost;
	}

	std::istream& operator>>(std::istream& ist, Roman_int& roman) {
		std::string temp;
		ist >> temp;
		roman.setRomanChar(temp);
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
		std::cout << romanValue << " " << romanValue.as_int();
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what();
	}	

	return 0;
}