#pragma once
#include <iostream>
#include <string>

namespace Roman {

	int romanValues(char);

	class Roman_int {

	public:
		Roman_int() {};
		Roman_int(const std::string&);
		Roman_int(int);

		//nonmodifying operations
		const std::string& getRoman() const { return romanChar; }
		int as_int() const;

	private:
		std::string romanChar;

		//modifying operations
		void setRomanChar(const std::string&);
		void setRomanInt(int);

		//nonmodifying operations
		std::string generateRomanDigit(int, char, char, char) const;
	};

	std::ostream& operator<<(std::ostream&, const Roman_int&);
	std::istream& operator>>(std::istream&, Roman_int&);
}