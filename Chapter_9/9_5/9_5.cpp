#include <iostream>
#include <string>
#include <iomanip> // Necesario para std::get_time
#include <ctime>
#include <sstream>
#include "9_5.h"
#include "9_5_library.h"

namespace library {

	Book::Book(Isbn isbn_val, const std::string& title_val, const std::string& author_val, const Genre& genre_val)
		:isbn(isbn_val), title(title_val), author(author_val), genreBook(genre_val) {
	}

	std::string Book::getGenre() const {
		switch (genreBook) {
		case Genre::fiction:    return "Fiction";
		case Genre::nonfiction: return "Non-Fiction";
		case Genre::periodical: return "Periodical";
		case Genre::biography:  return "Biography";
		case Genre::children:   return "Children";
		default:                return "Unknown";
		}
	}

	void Book::checkingIn() {
		std::cout << "You checked in the book " << title << "\n";
		checkedOut = false;
	}

	void Book::checkingOut(){
		std::cout << "You checked out the book " << title << "\n";
		checkedOut = true;
	}

	void Book::actualiceCopyright() {
		copyrightDate = createDate();
	}

	std::ostream& operator<<(std::ostream& os, const Book& book) {
		os << "Book " << book.getIsbn() << ", title " << book.getTitle() << ", author " << book.getAuthor() << ", genre " << book.getGenre();

		return os;
	}

	bool operator==(const Book& a, const Book& b){
		if (a.getIsbn() == b.getIsbn()) return true;
		else return false;
	}

	bool operator!=(const Book& a, const Book& b) {
		if (a == b) return false;
		else return true;
	}
}
