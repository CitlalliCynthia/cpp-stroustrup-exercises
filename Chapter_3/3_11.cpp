#include <iostream>

int main() {
	int numPennies, numNickels, numDimes,
		numQuarters, numHalfDollars, numOneDollars;
	double result;
	
	std::cout << "Please introduce the number of pennies you have: ";
	std::cin >> numPennies;
	std::cout << "Please introduce the number of nickels you have: ";
	std::cin >> numNickels;
	std::cout << "Please introduce the number of dimes you have: ";
	std::cin >> numDimes;
	std::cout << "Please introduce the number of quarters you have: ";
	std::cin >> numQuarters;
	std::cout << "Please introduce the number of half-dollars you have: ";
	std::cin >> numHalfDollars;
	std::cout << "Please introduce the number of one-dollars you have: ";
	std::cin >> numOneDollars;

	result = (numPennies + numNickels * 5 + numDimes * 10 + numQuarters * 25 +
		numHalfDollars * 50 + numOneDollars * 100)/100.0;

	if (numPennies > 1) std::cout << "\nYou have " << numPennies << " pennies \n";
	else if (numPennies > 0) std::cout << "\nYou have " << numPennies << " penny \n";

	if (numNickels > 1) std::cout << "You have " << numNickels << " nickels \n";
	else if (numNickels > 0) std::cout << "You have " << numNickels << " nickel \n";

	if (numDimes > 1) std::cout << "You have " << numDimes << " dimes \n";
	else if (numDimes > 0) std::cout << "You have " << numDimes << " dime \n";

	if (numQuarters > 1) std::cout << "You have " << numQuarters << " quarters \n";
	else if (numQuarters > 0) std::cout << "You have " << numQuarters << " quarter \n";

	if (numHalfDollars > 1) std::cout << "You have " << numHalfDollars << " half-dollars \n";
	else if (numHalfDollars > 0) std::cout << "You have " << numHalfDollars << " half-dollar \n";

	if (numOneDollars > 1) std::cout << "You have " << numOneDollars << " one-dollars \n";
	else if (numOneDollars > 0) std::cout << "You have " << numOneDollars << " one-dollar \n";
 
	std::cout << "The value of all your coins is $" << result << " dollars";

}