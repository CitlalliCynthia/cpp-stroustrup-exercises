#include <iostream>
#include <vector>

/*
9. Write a function that given two vector<double>s price and weight computes a value (an “index”) that is the sum of
all price[i]*weight[i]. Make sure to have weight.size()==price.size().
*/

void error(std::string s) {
	throw std::runtime_error(s);
}

double index(const std::vector<double>& price, const std::vector<double>& weight) {

	double result = 0;

	if (weight.size() == price.size()) {
		for (int i = 0; i < weight.size(); i++) {
			result += weight[i] * price[i];
		}
	}
	else error("Not same size!");

	return result;
}

int main() {

	std::vector<double> weight = {0.1,0.2,0.3,0.4,0.5};
	std::vector<double> price = { 1,2,3,4,5 };

	try {
		double result = index(price, weight);

		std::cout << result;
	}
	catch (const std::runtime_error& e) {
		std::cout << "[EXCEPCION CAPTURADA CON EXITO]\n";
		std::cout << "Mensaje del error: " << e.what() << "\n\n";
	}

	return 0;
}