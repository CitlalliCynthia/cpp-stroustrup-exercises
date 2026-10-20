#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> values(2);
	while (std::cin >> values[0] >> values[1]) {
		std::cout << "The numbers entered are: " << values[0] << " and " << values[1] << "\n";
		if (values[0] == values[1]) std::cout << "The numbers are equal! \n";
		else {
			sort(values.begin(), values.end());
			std::cout << "The smaller value is: " << values[0] << " and the larger value is: " << values[1] << "\n";
		}
	}
}
