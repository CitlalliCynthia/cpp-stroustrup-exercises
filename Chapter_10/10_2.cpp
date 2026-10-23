#include <iostream>
#include <fstream>
#include <stdexcept>

/* 2. Write a program that creates a file of data in the form of the temperature Reading type defined in §10.5. For testing, fill
the file with at least 50 “temperature readings.” Call this program store_temps.cpp and the file it creates
raw_temps.txt.
*/

int main() {

	try {
		std::ofstream ost("raw_temps.txt");
		if (!ost) throw std::runtime_error("Can't open output file.");

		double temperature = 0.0; //Celcius
		for (int hour = 0, i = 0; i <= 50; i++, hour++) {
			if (hour > 23) hour = 1;
			if (temperature > 56.7) temperature = 0.0;

			ost << hour << " " << temperature << "\n";
			temperature += 0.5;
		}
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	return 0;
}
