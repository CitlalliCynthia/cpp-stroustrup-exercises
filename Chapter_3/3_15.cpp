#include <iostream>
#include <string>
#include <vector>

int main() {
	std::vector<std::string> dislike = {"Sampo", "Nihilux","Aha"};

	std::vector<std::string> words;

	for (std::string temp; std::cin >> temp;) {
		if (temp == "quit") break;
		else words.push_back(temp);
	}

	std::cout << "The number of words you entered (without 'quit') is: " << words.size() << "\n";

	for (std::string temp : words) {
		int flag = 0;
		for (std::string tempDislike : dislike) {
			if (tempDislike == temp) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) std::cout << "BLEEP! \n";
		else std::cout << temp << "\n";
	}
}
