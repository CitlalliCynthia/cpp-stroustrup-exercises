#include <iostream>
#include <string>
#include <vector>

/*
17. Write a program that finds the min, max, and mode of a sequence of strings.
*/

int main() {

	std::vector<std::string> allanswers;
	std::string answer;

	
	do {
		std::cout << "Please introduce a string: ";
		std::cin >> answer;
		allanswers.push_back(answer);
	} while (answer != "quit");

	int mode = 0;
	std::string modeString;
	std::string max = allanswers[0];
	std::string min = allanswers[0];

	for (std::string word : allanswers) {
		std::cout << word << " ";
		int counter = 0;

		for (std::string actualWord : allanswers) {
			if (word == actualWord) {
				counter++;
			}
		}

		if (counter > mode) {
			mode = counter;
			modeString = word;
		}

		if (word > max) max = word;
		if (word < min) min = word;
	}

	std::cout << "\nThe max word entered is: " << max << "\n";
	std::cout << "The min word entered is: " << min << "\n";
	std::cout << "The mode word entered is: '" << modeString << "' and it appeared " 
		<< mode << " times";

	return 0;
}