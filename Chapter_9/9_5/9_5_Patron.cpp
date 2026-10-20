#include <string>
#include "9_5_Patron.h"

namespace library {

	Patron::Patron(const std::string& name_val, int cad_val)
			: userName(name_val), libraryCardNumber(cad_val) {
	}

	//modifying operations:
	void Patron::addFee(int fee) {
		libraryFees += fee;
	}

	bool operator==(const Patron& a, const Patron& b) {
		if (a.getlibraryCardNumber() == b.getlibraryCardNumber()) return true;
		else return false;
	}

	bool operator!=(const Patron& a, const Patron& b) {
		if (a == b) return false;
		else return true;
	}

}