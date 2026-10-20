#pragma once
#include <iostream>
#include <string>

/*
14. Design and implement a Money class for calculations involving dollars and cents where arithmetic has to be accurate
to the last cent using the 4/5 rounding rule (.5 of a cent rounds up; anything less than .5 rounds down). Represent a
monetary amount as a number of cents in a long int, but input and output as dollars and cents, e.g., $123.45. Do not
worry about amounts that don’t fit into a long int.

15. Refine the Money class by adding a currency (given as a constructor argument). Accept a floating-point initializer as
long as it can be exactly represented as a long int. Don’t accept illegal operations. For example, Money*Money
doesn’t make sense, and USD1.23+DKK5.00 makes sense only if you provide a conversion table defining the
conversion factor between U.S. dollars (USD) and Danish kroner (DKK).

16. Define an input operator (>>) that reads monetary amounts with currency denominations, such as USD1.23 and
DKK5.00, into a Money variable. Also define a corresponding output operator (>>).
*/
namespace Finance {
	
	class Invalid {};

	class Money {

	public:
		Money() {};
		Money(const std::string&);
		Money(const double, const std::string&); //money
		Money(long int, const std::string&);

		//Consult operations
		long int getCents() const { return cents; }
		double getMoney() const { return cents / 100.0; }
		std::string getCurrency() const { return currency; }

	private:
		long int cents = 0;
		std::string currency = "USD";

		long int roundToCents(double); //double to long int via 4/5 rule
	};

	double convertionMultiplier(std::string);

	Money operator+(const Money&, const Money&);
	Money operator-(const Money&, const Money&);

	Money operator*(const Money&, const double);

	std::ostream& operator<<(std::ostream&, const Money&);
	std::istream& operator>>(std::istream&, Money&);
}