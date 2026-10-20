#pragma once
#include <iostream>

/*
13. Design and implement a rational number class, Rational. A rational number has two parts: a numerator and a
denominator, for example, 5/6 (five-sixths, also known as approximately .83333). Look up the definition if you need to.
Provide assignment, addition, subtraction, multiplication, division, and equality operators. Also, provide a conversion to
double. Why would people want to use a Rational class?
*/
namespace Rational {
	
	class Invalid {};
	
	class Rational {

	public:
		Rational(int, int);

		//nonmodifying operation
		int getNumerator() const { return numerator; }
		int getDenominator() const { return denominator; }

		explicit operator double() const; //modern C++ (explicit), to prevent from being used outside from an explicit static_cast<double>(xxx).

	private:
		int numerator;
		int denominator;

		//nonmodifying operation
		bool isValid(const int) const;
	};

	bool operator==(const Rational&, const Rational&);
	bool operator!=(const Rational&, const Rational&);

	Rational operator+(const Rational&, const Rational&);
	Rational operator-(const Rational&, const Rational&);
	Rational operator*(const Rational&, const Rational&);
	Rational operator/(const Rational&, const Rational&);

	std::ostream& operator<<(std::ostream&, const Rational&);

	int calculateGCD(int, int);
}
