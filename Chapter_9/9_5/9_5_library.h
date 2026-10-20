#pragma once
#include <string>
#include <vector>
#include "9_5.h"
#include "9_5_Patron.h"

/*
9. Create a Library class. Include vectors of Books and Patrons. Include a struct called Transaction. Have it include a
Book, a Patron, and a Date from the chapter. Make a vector of Transactions. Create functions to add books to the
library, add patrons to the library, and check out books. Whenever a user checks out a book, have the library make sure
that both the user and the book are in the library. If they aren’t, report an error. Then check to make sure that the user
owes no fees. If the user does, report an error. If not, create a Transaction, and place it in the vector of Transactions.
Also write a function that will return a vector that contains the names of all Patrons who owe fees.
*/

namespace library {

	struct Transaction {
		Book specificBook;
		Patron specificPatron;
		std::tm Date = {};

		Transaction(const Book&, const Patron&, const std::tm&);

	};

	class Library {
	public:

		//nonmodifying operations:
		bool userHasFees(const Patron&) const;
		std::vector<Patron> whoOwesFees() const;

		// modifying operations :
		void addBook(const Book&);
		void addPatron(const Patron&);
		void chekoutBook(Book&, const Patron&);
				
	private:
		std::vector<Book> allBooks;
		std::vector<Patron> allPatrons;
		std::vector<Transaction> allTransactions;

		void createTransaction(const Book&, const Patron&, const std::tm&);
	};

	std::tm createDate();
}