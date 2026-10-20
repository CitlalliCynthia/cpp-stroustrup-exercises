#pragma once
#include <string>

/*
8. Create a Patron class for the library. The class will have a user’s name, library card number, and library fees (if
owed). Have functions that access this data, as well as a function to set the fee of the user. Have a helper function that
returns a Boolean (bool) depending on whether or not the user owes a fee.
*/

namespace library {

	class Patron {

	public:
		Patron(const std::string&, int);

		//nonmodifying operations:
		std::string getUserName() const { return userName; }
		int getlibraryCardNumber() const { return libraryCardNumber; }
		int getlibraryFees() const { return libraryFees; }
		bool owesFee() const { return libraryFees > 0; }

		//modifying operations:
		void addFee(int);

	private:
		std::string userName;
		const int libraryCardNumber;
		int libraryFees = 0;
	};

	bool operator==(const Patron&, const Patron&);

	bool operator!=(const Patron&, const Patron&);
}
