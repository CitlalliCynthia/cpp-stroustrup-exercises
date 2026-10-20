#include <iostream>
#include <vector>

/*
Write a program to play a numbers guessing game. The user thinks of a number between 1 and 100 and your program
asks questions to figure out what the number is (e.g., “Is the number you are thinking of less than 50?”). Your program
should be able to identify the number after asking no more than seven questions. Hint: Use the < and <= operators and the
if-else construct.
*/

int main() {

	int number, guessed = 50, numberGuesses = 0;
	int maxLimit = 100, minLimit = 1;
	char answer;

	std::cout << "We'll play a guessing game! Think of a number between 1 and 100: ";
	
	while (std::cin >> number) {
		if (number < 1 || number > 100) {
			std::cout << "That one didn't count! Choose a valid number!\n";
			std::cout << "\nThink of a number between 1 and 100: ";
		}
		else break;
	}

	std::cout << "\nAlright! I'll try to guess it!\n";

	while (number != guessed) {

		std::cout << "\nIs your number less than " << guessed << "?"
			<< " If yes, write 'y'; if no, write 'n': ";

		std::cin >> answer;

		if (answer == 'y') {
			maxLimit = guessed;
			guessed = minLimit + ((maxLimit - minLimit - 1) / 2);
		}
		else {
			minLimit = guessed;
			guessed = minLimit + ((maxLimit - minLimit + 1) / 2);
		}

		numberGuesses++;
	}

	std::cout << "\nYour number is " << guessed << ", and it took me " 
		<< numberGuesses << " guesses!";

	return 0;
}