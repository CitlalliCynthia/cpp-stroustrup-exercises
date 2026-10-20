#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> sortAges(const std::vector<std::string>& namesSorted,
								const std::vector<std::string>& namesOriginal,
								const std::vector<int>& agesOriginal) {
	
	int n = namesOriginal.size();
	std::vector<int> agesSorted(n);

	//i --> namesSorted
	for (int i = 0; i < n; i++) {
		//j --> namesOriginal
		for (int j = 0; j < n; j++) {
			if (namesSorted[i] == namesOriginal[j])
				agesSorted[i] = agesOriginal[j];
				break;
		}
	}

	return agesSorted;
}

int main() {

	std::vector<std::string> names(5);
	std::vector<int> ages(5);

	for (int i = 0; i < 5; i++) {
		std::cout << "Please introduce a name and an age"
			<< "\nExample (Cynthia 23): ";

		std::cin >> names[i] >> ages[i];
	}

	std::cout << "\n\nIntroduced:\n";

	for (int i = 0; i < 5; i++) {
		std::cout << "Name: " << names[i] << ", Age: " << ages[i] << "\n";
	}

	std::vector<std::string> namesCopy = names;

	sort(names.begin(),names.end());

	std::vector<int> agesSorted = sortAges(names,namesCopy,ages);

	std::cout << "\n\nSorted:\n";

	for (int i = 0; i < 5; i++) {
		std::cout << "Name: " << names[i] << ", Age: " << agesSorted[i] << "\n";
	}

	return 0;
}