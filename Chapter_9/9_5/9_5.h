#pragma once
#include <string>
#include <iomanip> // Necesario para std::get_time
#include <ctime>
#include <cctype>
#include <iostream>

/*
5. This exercise and the next few require you to design and implement a Book class, such as you can imagine as part of
software for a library. Class Book should have members for the ISBN, title, author, and copyright date. Also store data
on whether or not the book is checked out. Create functions for returning those data values. Create functions for checking
a book in and out. Do simple validation of data entered into a Book; for example, accept ISBNs only of the form n-n-nx
where n is an integer and x is a digit or a letter. Store an ISBN as a string.

6. Add operators for the Book class. Have the == operator check whether the ISBN numbers are the same for two books.
Have != also compare the ISBN numbers. Have a << print out the title, author, and ISBN on separate lines.

7. Create an enumerated type for the Book class called Genre. Have the types be fiction, nonfiction, periodical,
biography, and children. Give each book a Genre and make appropriate changes to the Book constructor and member
functions.
*/

namespace library {
	
	class Invalid{};

	enum class Genre {
		fiction, nonfiction, periodical, biography, children
	};

	struct Isbn {
		std::string value;

		Isbn(const std::string& s) :
			value(s)
		{
			if (!isValid(s)) throw Invalid{};
		}

	private:
		bool isValid(std::string s) {
			if (s.size() == 7) {
				if (s[1] == '-' && s[3] == '-' && s[5] == '-')
					if (std::isdigit(s[0]) && std::isdigit(s[2]) && std::isdigit(s[4]))
						return true;
			}
			return false;
		}
	};

	class Book {
	public:
		Book(Isbn, const std::string&, const std::string&, const Genre&);

		//nonmodifying operations:
		std::string getIsbn() const { return isbn.value; }
		std::string getTitle() const { return title; }
		std::string getAuthor() const { return author; }
		std::tm getCopyright() const { return copyrightDate; }
		bool  getIfCheckedOut() const { return checkedOut; }
		std::string getGenre() const;

		//modifying operations:
		void checkingIn();	
		void checkingOut();
		void actualiceCopyright();

	private:
		Isbn isbn;
		std::string title;
		std::string author;
		Genre genreBook;
		std::tm copyrightDate = {};
		bool checkedOut = false;
	};

	std::ostream& operator<<(std::ostream&, const Book&);

	bool operator==(const Book&, const Book&);

	bool operator!=(const Book&, const Book&);
}