#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Everything is managed in 'cm' internally!

double conversorToCm(double value, std::string unit) {
	if (unit == "cm") {
		return value;
	}
	else if (unit == "m") {
		return value * 100;
	}
	else if (unit == "in") {
		return value * 2.54;
	}
	else if (unit == "ft") {
		return value * 2.54 * 12;
	}
}

bool isValidThisUnit(std::string unit) {
	if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft")
		return true;
	else return false;
}

int main() {

	double max = 0, min = 0, tempValue, sum = 0;
	std::string unitMax = "cm", unitMin = "cm", tempUnit;
	bool flag = false;
	int quantity = 0;
	std::vector<double> valuesEntered;

	std::cout << "Introduce a number with their respective unit (cm, m, in, ft)"
		<< "\nExample of an input (3 cm): ";

	while (std::cin >> tempValue >> tempUnit) {
		if (isValidThisUnit(tempUnit) && tempValue >= 0) {
			if (flag) {
				if (conversorToCm(tempValue, tempUnit) > conversorToCm(max, unitMax)) {
					max = tempValue;
					unitMax = tempUnit;
					std::cout << max << " " << unitMax << " is the largest so far \n";
				}
				else if (conversorToCm(tempValue, tempUnit) < conversorToCm(min, unitMin)) {
					min = tempValue;
					unitMin = tempUnit;
					std::cout << min << " " << unitMin << " is the smallest so far \n";
				}
			}
			else {
				max = tempValue;
				unitMax = tempUnit;
				min = tempValue;
				unitMin = tempUnit;
				flag = 1;

				std::cout << tempValue << " " << tempUnit << " is both the largest and smallest! \n";
			}

			sum += conversorToCm(tempValue, tempUnit);
			quantity += 1;
			valuesEntered.push_back(conversorToCm(tempValue, tempUnit)/100);
		}
		else std::cout << "Not a valid unit or a non-positive value!\n";

		std::cout << "Please write another number (example, 5 cm): ";
	}

	std::cout << "\nThe largest value is " << max << " " << unitMax << "\n";
	std::cout << "\nThe smallest value is " << min << " " << unitMin << "\n";
	std::cout << "\nThe number of values entered are: " << quantity << "\n";
	std::cout << "\nThe sum of every number entered is: " << sum/100 << " m\n";

	sort(valuesEntered.begin(), valuesEntered.end());

	std::cout << "\nThe vector obtained in 'm' is: ";
	for (double temp : valuesEntered) std::cout << temp << " ";
}