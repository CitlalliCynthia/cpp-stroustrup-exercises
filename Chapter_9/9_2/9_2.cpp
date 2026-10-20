#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "9_2.h"

/*
2. Design and implement a Name_pairs class holding (name,age) pairs where name is a string and age is a double.
Represent that as a vector<string> (called name) and a vector<double> (called age) member. Provide an input
operation read_names() that reads a series of names. Provide a read_ages() operation that prompts the user for an age
for each name. Provide a print() operation that prints out the (name[i],age[i]) pairs (one per line) in the order
determined by the name vector. Provide a sort() operation that sorts the name vector in alphabetical order and
reorganizes the age vector to match. Implement all “operations” as member functions. Test the class (of course: test early
and often).
*/

namespace pairs {

	void Name_pairs::read_names() {
		std::string nameTemp;
	
		do {
			std::cout << "Please introduce a name until you write 'quit': ";
			std::cin >> nameTemp;
			if (nameTemp != "quit") name.push_back(nameTemp);
			else if (name.size() == 0) std::cout << "\nIntroduce at least one name! \n";
			else break;

		} while (true);

		read_ages(); //Is important to modify this call right here!
		//Just a matter of adding a few more conditions and validations to make it so read_names() and read_ages() can be call in whatever order
	}

	void Name_pairs::read_ages() {
		double ageTemp;
		std::cout << "\n";
		do {
			std::cout << "Please introduce an age until you have as many ages as names introduced : ";
			std::cin >> ageTemp;
			if (ageTemp >= 0) age.push_back(ageTemp);
		} while (age.size() < name.size());
	}

	void Name_pairs::print(std::string label) {
		std::cout << "\n" << label << "\n";
		for (int i = 0; i < name.size(); i++) {
			std::cout << "Pair No. " << i << ": " << name[i] << ", " << age[i] << "\n";
		}
	}

	void Name_pairs::sortNameAndAge() {
		std::vector<std::string> TempNames = name;
		std::vector<double> TempAges;

		sort(name.begin(),name.end());

		std::string EmptyString;
		for (std::string nameElement : name) {
			for (int i = 0; i < TempNames.size(); i++) {
				if (nameElement == TempNames[i]) {
					TempAges.push_back(age[i]);
					TempNames[i] = EmptyString;
					break;
				}
			}
		}

		age = TempAges;
	}

}
