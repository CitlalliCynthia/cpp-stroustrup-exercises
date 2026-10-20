#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
13. Write a function that takes a vector<string> argument and returns a vector<int> containing the number of characters
in each string. Also find the longest and the shortest string and the lexicographically first and last string. How many
separate functions would you use for these tasks? Why?
*/

struct Statistics {
	std::string longest;
	std::string shortest;
	std::string first;
	std::string last;
};

void error(std::string s) {
	throw std::runtime_error(s);
}

Statistics operations(const std::vector<std::string>& words, const std::vector<int>& quantity) {
	if (words.empty() || quantity.empty()) error("operations(): El vector no puede estar vacio.");
	
	Statistics results;

	int n = words.size();
	int max = quantity[0];
	int min = quantity[0];

	results.longest = words[0];
	results.shortest = words[0];

	for (int i = 1; i < n; i++) {
		if (quantity[i] > max) {
			max = quantity[i];
			results.longest = words[i];
		}
		if (quantity[i] < min) 
		{
			min = quantity[i];
			results.shortest = words[i];
		}
	}

	std::vector<std::string> wordsSorted = words;
	sort(wordsSorted.begin(), wordsSorted.end());

	results.first = wordsSorted[0];
	results.last = wordsSorted[n-1];

	return results;
}

std::vector<int> numCaracters(const std::vector<std::string>& words) {
	if(words.empty()) error("numCaracters(): El vector no puede estar vacio.");
	
	int n = words.size();
	std::vector<int> quantity(n);

	for (int i = 0; i < n; i++) {
		quantity[i] = words[i].size();
	}

	return quantity;
}

int main() {

	std::vector<std::string> words = { "hello","world","!" };

	try {
		Statistics results = operations(words, numCaracters(words));

		std::cout << "First: " << results.first
			<< ", Last: " << results.last
			<< ", Shortest: " << results.shortest
			<< ", Longest: " << results.longest << "\n";
	}
	catch (const std::runtime_error& e) {
		std::cout << "[ERROR]: " << e.what() << "\n";
	}

	return 0;
}