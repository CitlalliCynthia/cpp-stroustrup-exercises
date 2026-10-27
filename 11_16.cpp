#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>

/*
16. Write a program to read a file of whitespace-separated numbers and output them in order (lowest value first), one value per line. Write a value only once, and if it occurs more than once write the count of its occurrences on its line. For example, 7 5 5 7 3 117 5 should give
*/
struct Ocurrences {
	int number;
	int ocurrences = 1;
};

bool compareOcurrences(const Ocurrences& a, const Ocurrences& b) {
	return a.number < b.number;
}

void getSorted(std::istream& ist, std::vector<Ocurrences>& vec) {
	Ocurrences temp;

	for (int number; ist >> number;) {
		bool flag = false;
		for (int i = 0; i < vec.size(); i++) {
			if (number == vec[i].number) {
				vec[i].ocurrences++;
				flag = true;
				break;
			}
		}

		if (!flag) {
			temp.number = number;
			vec.push_back(temp);
		}
	}

	std::sort(vec.begin(),vec.end(), compareOcurrences);
}

void printResults(const std::vector<Ocurrences>& oc) {
	for (int i = 0; i < oc.size(); i++) {
		if (oc[i].ocurrences > 1) std::cout << oc[i].number << " " << oc[i].ocurrences << "\n";
		else std::cout << oc[i].number << "\n";
	}
}

int main() {

	try {
		std::ifstream ist("input1.txt");
		if (!ist) throw std::runtime_error("Can't open input file.");

		std::vector<Ocurrences> numbers;
		getSorted(ist, numbers);
		printResults(numbers);
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what();
	}

	return 0;
}