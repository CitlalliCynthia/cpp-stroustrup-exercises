#include <iostream>
#include <vector>

// read some temperatures into a vector
int main()
{
	std::vector<double> temperatures; // temperatures
	for (double temp; std::cin >> temp; ) // read into temp
		temperatures.push_back(temp); // put temp into vector
	// . . . do something . . .

	for (double temp : temperatures) {
		std::cout << temp << "\n";
	}
}