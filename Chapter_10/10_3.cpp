#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>

struct Reading { // a temperature reading
	int hour; // hour after midnight [0:23]
	double temperature; // in Fahrenheit
};

struct Parameters {
	double mean;
	double median;
};

void getReading(std::istream& ist, std::vector<Reading>& readings) {
	Reading temp;
	char waste;

	while (ist >> temp.hour >> temp.temperature >> waste) {
		if (waste == 'c' or waste == 'C') temp.temperature = (temp.temperature * 9.0 / 5.0) + 32.0;
		else if (waste != 'f' && waste != 'F')  throw std::runtime_error("Not a correct temperature unit!");
		readings.push_back(temp);
	}

	if(ist.bad()) throw std::runtime_error("Ocurred an unexpected error!");
}

bool compareByTemperature(const Reading& a, const Reading& b) {
	return a.temperature < b.temperature;
}

Parameters getParameters(const std::vector<Reading>& vec) {
	if (vec.empty()) throw std::runtime_error("Cannot calculate parameters for empty data.");

	std::vector<Reading> sorted = vec;
	Parameters tempParam;
	int size = sorted.size();
	double sum = 0.0;
	
	sort(sorted.begin(), sorted.end(), compareByTemperature);

	for (const Reading& temp : sorted) {
		sum += temp.temperature;
	}

	tempParam.mean = sum / size;

	if (sorted.size() % 2 != 0) {
		tempParam.median = sorted[size / 2].temperature;
	}
	else {
		tempParam.median = (sorted[size / 2].temperature + sorted[size / 2 -1].temperature)/2.0;
	}

	return tempParam;
}


int main() {
	std::vector<Reading> readings;
	
	try {
		std::ifstream ist("raw_temps.txt");
		if (!ist) throw std::runtime_error("Can't open input file.");

		getReading(ist, readings);

		if (ist.fail() && !ist.eof()) throw std::runtime_error("Not a correct input.");
		
		Parameters param = getParameters(readings);

		std::cout << "Mean: " << param.mean << "\n";
		std::cout << "Median: " << param.median << "\n";

	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	return 0;
}