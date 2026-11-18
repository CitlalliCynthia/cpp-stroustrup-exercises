#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <numeric>

/*
Now try a map :
1. Define a map<string, int> called msi.
2. Insert ten(name, value) pairs into it, e.g., msi["lecture"] = 21.
3. Output the(name, value) pairs to cout in some format of your choice.
4. Erase the(name, value) pairs from msi.
5. Write a function that reads value pairs from cin and places them in msi.
6. Read ten pairs from input and enter them into msi.
7. Write the elements of msi to cout.
8. Output the sum of the(integer) values in msi.
9. Define a map<int, string> called mis.
10. Enter the values from msi into mis; that is, if msi has an element("lecture",
21), mis should have an element
(21, "lecture").
11. Output the elements of mis to cout.
*/

template<typename T>
void print_all(const T& msi) {
	for (typename T::const_iterator p = msi.begin();
		p != msi.end(); ++p) {
		std::cout << "Key: " << p->first << ", Value: " << p->second << "\n";
	}
}

void getInput(std::istream& ist, std::map<std::string,int>& map) {
	std::string key;
	int val;
	//std::cout << "Introduce a key (spaced) and a value until you enter Contrl+Z+Enter or a bad input: ";
	while (ist >> key >> val) {
		map[key] = val;
	}

	if (ist.fail() && !ist.eof()) {
		std::cout << "\nBad input!\n";
		ist.clear();
		ist.ignore(1000, '\n');
	}
	else ist.clear();

	std::cout << "\n";
}

struct Sum_values {
	int operator()(int accumulated, const std::pair<const std::string, int>&p) const {
		return accumulated + p.second;
	}
};

int main() {

	std::map<std::string, int> msi;

	msi["lecture"] = 21;
	msi["red"] = 28;
	msi["blue"] = 20;
	msi["pink"] = 89;
	msi["purple"] = 56;
	msi["black"] = 30;
	msi["white"] = 12;
	msi["gray"] = 67;
	msi["yellow"] = 45;
	msi["teal"] = 54;
	
	print_all(msi);

	msi.clear();

	try {
		std::ifstream ist("input21_2.txt");
		if (!ist) throw std::runtime_error("Can't open input file!");

		getInput(ist, msi);

		print_all(msi);

		std::cout << "\nThe sum of all values in the map is: " <<
		std::accumulate(msi.begin(),msi.end(),0,Sum_values()) << "\n";

		std::map<int, std::string> mis;

		for (std::map<std::string,int>::const_iterator p = msi.begin();
			p != msi.end(); ++p) {
			mis[p->second] = p->first;
		}

		std::cout << "\nNEW MAP WITH KEY/VALUES INVERTED:\n";
		print_all(mis);

	}
	catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	
	return 0;
}