#include <iostream>
#include <vector>
#include <algorithm>

/*
11. Write a function that finds the smallest and the largest element of a vector argument and also computes the mean and the
median. Do not use global variables. Either return a struct containing the results or pass them back through reference
arguments. Which of the two ways of returning several result values do you prefer and why?
*/

void error(std::string s) {
	throw std::runtime_error(s);
}

void operations(const std::vector<int>& vec, int& max, int& min, double& mean, double& median) {

	if (vec.empty()) error("operations(): El vector no puede estar vacio.");

	std::vector<int> sortedVec = vec;
	sort(sortedVec.begin(), sortedVec.end());

	int n = vec.size();
	max = sortedVec[n-1];
	min = sortedVec[0];
	
	int sum = 0;
	for (int element : sortedVec) {
		sum += element;
	}
	mean = static_cast<double>(sum)/vec.size();

	//odd
	if (n % 2 != 0) median = sortedVec[n / 2];
	//even
	else {
		median = (sortedVec[n / 2] + sortedVec[n / 2 - 1]) / 2.0;
	}
}

int main() {

	std::vector<int> vec = { 1,2,3,4 };
	int max, min;
	double mean, median;

	try {
		operations(vec, max, min, mean, median);
		std::cout << "Max: " << max << ", Min: " << min << ", Mean: " << mean << ", Median: " << median;
	}
	catch (const std::runtime_error& e) {
		std::cout << "[ERROR]: " << e.what() << "\n";
	}

	return 0;
}