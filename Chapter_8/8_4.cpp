#include <iostream>
#include <vector>
#include <string>

/*
5. Write two functions that reverse the order of elements in a vector<int>. For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1.
The first reverse function should produce a new vector with the reversed sequence, leaving its original vector
unchanged. The other reverse function should reverse the elements of its vector without using any other vectors (hint:
swap).

6. Write versions of the functions from exercise 5, but with a vector<string>.
*/

std::vector<std::string> reverse1(const std::vector<std::string>& vec) {
	int n = vec.size();
	std::vector<std::string> newVec(n);

	for (int i = 0; i < n; i++) {
		newVec[i] = vec[n - 1 - i];
	}

	return newVec;
}

void reverse2(std::vector<std::string>& vec) {
	int n = vec.size();

	//También se puede utilizar swap de la biblioteca <utility>
	for (int i = 0; i < n / 2; i++) {
		//std::swap(vec[i], vec[n - 1 - i]); 
		std::string temp = vec[i];
		vec[i] = vec[n - 1 - i];
		vec[n - 1 - i] = temp;
	}
}

void print(const std::string& string, const std::vector<std::string>& vector) {

	std::cout << string << " ";

	for (std::string element : vector) {
		std::cout << element << " ";
	}
}

int main() {

	std::vector<std::string> vec = { "hola", "jeje", "Vyn", "Artem"};
	std::vector<std::string> newVec = reverse1(vec);

	reverse2(vec);

	print("New Vector: ", newVec);
	print("Same Vector: ", vec);

	return 0;
}