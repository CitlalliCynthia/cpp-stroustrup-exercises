#include <iostream>
#include <vector>

/*
16. In the drill, you wrote a program that, given a series of numbers, found the max and min of that series. The number that
appears the most times in a sequence is called the mode. Create a program that finds the mode of a set of positive
integers.
*/

int main() {

	std::vector<int> numbers;

	std::cout << "Please introduce a positive number: ";

	for (int entry; std::cin >> entry;) {
		
		if (entry >= 0) {
			numbers.push_back(entry);
		}

		std::cout << "Please introduce a positive number: ";
	}

	int maxNumber;
	int maxOcurrences = 0;

	for (int number : numbers) {
		std::cout << number << " ";

		int counter = 0;

		for (int comparison : numbers) {
			if (number == comparison) {
				counter++;
			}
		}

		if (counter > maxOcurrences) {
			maxNumber = number;
			maxOcurrences = counter;
		}

	}

	std::cout << "\nThe mode is: " << maxNumber << " and it appeared " << maxOcurrences << " times!";

	return 0;
}