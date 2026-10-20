#include <cmath>
#include <iostream>
#include "9_13.h"

namespace Rational {

	Rational::Rational(const int a, const int b){
		if (!isValid(b)) throw Invalid();
		int shared = calculateGCD(a, b);
		numerator = a / shared;
		denominator = b / shared;
	}

	bool Rational::isValid(const int b) const {
		if (b > 0) return true;
		else return false;
	}

	Rational::operator double() const {
		return static_cast<double>(numerator) / denominator;
	}

	bool operator==(const Rational& a, const Rational& b) {
		if (a.getNumerator() * b.getDenominator() == b.getNumerator() * a.getDenominator())
			return true;
		else return false;
	}

	bool operator!=(const Rational& a, const Rational& b) {
		if (a == b) return false;
		else return true;
	}

	Rational operator+(const Rational& a, const Rational& b) {
		int tempNume, tempDeno;
		int aNume = a.getNumerator(), aDeno = a.getDenominator();
		int bNume = b.getNumerator(), bDeno = b.getDenominator();

		if (aDeno == bDeno) {
			tempNume = aNume + bNume;
			tempDeno = aDeno;
		}else {
			tempNume = aNume * bDeno + bNume * aDeno;
			tempDeno = aDeno * bDeno;
		}

		return Rational(tempNume, tempDeno);
	}

	Rational operator-(const Rational& a, const Rational& b) {
		int tempNume, tempDeno;
		int aNume = a.getNumerator(), aDeno = a.getDenominator();
		int bNume = b.getNumerator() * -1, bDeno = b.getDenominator();

		if (aDeno == bDeno) {
			tempNume = aNume + bNume;
			tempDeno = aDeno;
		}
		else {
			tempNume = aNume * bDeno + bNume * aDeno;
			tempDeno = aDeno * bDeno;
		}

		return Rational(tempNume, tempDeno);
	}

	Rational operator*(const Rational& a, const Rational& b) {
		int tempNume, tempDeno;

		tempNume = a.getNumerator() * b.getNumerator();
		tempDeno = a.getDenominator() * b.getDenominator();

		return Rational(tempNume,tempDeno);
	}

	Rational operator/(const Rational& a, const Rational& b) {
		int tempNume, tempDeno;

		tempNume = a.getNumerator() * b.getDenominator();
		tempDeno = a.getDenominator() * b.getNumerator();

		return Rational(tempNume, tempDeno);
	}

	std::ostream& operator<<(std::ostream& os, const Rational& fraction) {
		os << fraction.getNumerator() << "/" << fraction.getDenominator();
		return os;
	}

	int calculateGCD(int a, int b) { //The Greatest Common Divisor
		//Absolute values to avoid problems with negative numbers
		a = std::abs(a);
		b = std::abs(b);

		while (b != 0) {
			int temp = b;
			b = a % b; // Residue is the newer divisor
			a = temp;
		}
		return a; // When 'b' reaches 0, 'a' holds the GCD
	}
}