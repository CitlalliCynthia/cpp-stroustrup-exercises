#include "9_5_library.h"

namespace library {

	Transaction::Transaction(const Book& b, const Patron& p, const std::tm& date) :
		specificBook(b), specificPatron(p), Date(date) {
	}

	//nonmodifying operations:
	bool Library::userHasFees(const Patron& p) const {
		if (p.getlibraryFees() > 0) return true;
		else return false;
	}

	std::vector<Patron> Library::whoOwesFees() const {
		std::vector<Patron> tempVector;
		for (Patron patronTemp : allPatrons) {
			if (patronTemp.owesFee()) tempVector.push_back(patronTemp);
		}

		return tempVector;
	}

	// modifying operations :
	void Library::addBook(const Book& b) {
		allBooks.push_back(b);
	}

	void Library::addPatron(const Patron& p) {
		allPatrons.push_back(p);
	}

	void Library::createTransaction(const Book& b, const Patron& p, const std::tm& date) {
		Transaction newTransaction = Transaction(b, p, date);

		allTransactions.push_back(newTransaction);
	}

	void Library::chekoutBook(Book& b, const Patron& p) {
		bool flagBook = false;
		bool flagPatron = false;

		for (const Book& bookTemp : allBooks) {
			if (bookTemp == b) {
				flagBook = true;
				break;
			}
		}

		for (const Patron& patronTemp : allPatrons) {
			if (patronTemp == p) {
				flagPatron = true;
				break;
			}
		}

		if (flagBook && flagPatron && !userHasFees(p)) {
			std::cout << b << "\n";
			std::cout << "You've checked out the book!\n";
			createTransaction(b, p, createDate());
			b.checkingOut();
		}
		else throw Invalid{};
	}

	//Extra
	std::tm createDate() {
		std::cout << "Introduce your date (dd/mm/yyyy): ";
		std::tm temp;

		// Usamos std::cin para leer la consola y le pasamos la dirección del atributo
		if (std::cin >> std::get_time(&temp, "%d/%m/%Y")) {
			std::cout << "Date updated successfully!\n";
		}
		else {
			std::cout << "Invalid date format. Please use dd/mm/yyyy\n";

			// Si la lectura falla, limpiamos el estado de cin para evitar bucles infinitos
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		return temp;
	}
}