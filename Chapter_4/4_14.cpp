#include <iostream>
#include <vector>

int calculateSquares(int grain) {
	int squares = 1;
	int counterGrains = 1;

	while (counterGrains <= grain) {
		counterGrains *= 2;
		squares++;
	}

	return squares;
}

int main() {

	std::vector<int> grains = {1000,1000000,1000000000};

	for (int grain : grains) {
		std::cout << "The number of squares required for " << grain << " grains is "
			<< calculateSquares(grain) << "\n\n";
	}

	return 0;
}