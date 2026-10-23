#include <iostream>
#include <fstream>
#include <stdexcept>

int main() {

	try {
		std::ofstream ost("raw_temps.txt");
		if (!ost) throw std::runtime_error("Can't open output file.");

		double temperature = 0.0;
		char suffix = 'c';
		for (int hour = 0, i = 0; i <= 50; i++, hour++) {
			if (hour > 23) hour = 1;
			if (temperature > 56.7) temperature = 0.0;
			if (hour % 2 == 0) suffix = 'c';
			else suffix = 'f';

			ost << hour << " " << temperature << " " << suffix <<"\n";
			temperature += 0.5;
		}
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	return 0;
}