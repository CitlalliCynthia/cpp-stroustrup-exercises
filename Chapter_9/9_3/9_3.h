#pragma once

#include <iostream>
#include <string>
#include <vector>

/*
2. Design and implement a Name_pairs class holding (name,age) pairs where name is a string and age is a double.
Represent that as a vector<string> (called name) and a vector<double> (called age) member. Provide an input
operation read_names() that reads a series of names. Provide a read_ages() operation that prompts the user for an age
for each name. Provide a print() operation that prints out the (name[i],age[i]) pairs (one per line) in the order
determined by the name vector. Provide a sort() operation that sorts the name vector in alphabetical order and
reorganizes the age vector to match. Implement all “operations” as member functions. Test the class (of course: test early
and often).

3. Replace Name_pair::print() with a (global) operator << and define == and != for Name_pairs.
*/

namespace pairs {

	class Name_pairs {

	public:

		//class Invalid {};

		//NON-MODIFIYING OPERATIONS

		//void print(std::string);

		std::vector<std::string> getNames() const { return name; }

		std::vector<double> getAges() const { return age; }

		//MODIFYING OPERATIONS

		void sortNameAndAge();

		void read_names();

		void read_ages();

	private:
		std::vector<std::string> name;
		std::vector<double> age;
	};

	std::ostream& operator<<(std::ostream&, const Name_pairs&);

	bool operator==(const Name_pairs&, const Name_pairs&);

	bool operator!=(const Name_pairs&, const Name_pairs&);
}
