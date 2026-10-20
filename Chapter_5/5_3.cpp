#include <iostream>
#include <vector>

/*
Read a sequence of double values into a vector. Think of each value as the distance between two cities along a given
route. Compute and print the total distance (the sum of all distances). Find and print the smallest and greatest distance
between two neighboring cities. Find and print the mean distance between two neighboring cities.
*/

int main() {

	std::vector<double> travelRecord;
	double minDistance, maxDistance;
	double sum = 0, mean = 0;
	bool flag = false;

	std::cout << "Introduce a distance: ";

	for (double distance = 0; std::cin >> distance;) {
		if (distance >= 0) {

			if (flag) {
				if (distance > maxDistance)
					maxDistance = distance;
				else if (distance < minDistance)
					minDistance = distance;
			}
			else {
				minDistance = distance;
				maxDistance = distance;
				flag = true;
			}

			travelRecord.push_back(distance);
			sum += distance;
		}

		std::cout << "Introduce a distance: ";
	}

	std::cout << "\nThe biggest distance between two cities was: " << maxDistance << "\n";
	std::cout << "The smallest distance between two cities was: " << minDistance << "\n";
	std::cout << "The total distance is: " << sum << "\n";
	std::cout << "The mean distance is: " << sum/travelRecord.size() << "\n";

	return 0;
}