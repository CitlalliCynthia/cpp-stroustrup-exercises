#include <iostream>
#include <vector>

/*
5. Write two functions that reverse the order of elements in a vector<int>. For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1.
The first reverse function should produce a new vector with the reversed sequence, leaving its original vector
unchanged. The other reverse function should reverse the elements of its vector without using any other vectors (hint:
swap).
*/

std::vector<int> reverse1(const std::vector<int>& vec) {
	int n = vec.size();
	std::vector<int> newVec(n);
	
	for (int i = 0; i < n; i++) {
		newVec[i] = vec[n - 1 - i];
	}

	return newVec;
}

void reverse2(std::vector<int>& vec) {
	int n = vec.size();

	//También se puede utilizar swap de la biblioteca <utility>
	for (int i = 0; i < n/2; i++) {
		//std::swap(vec[i], vec[n - 1 - i]); 
		int temp = vec[i];
		vec[i] = vec[n - 1 - i];
		vec[n - 1 - i] = temp;
	}
}

void print(const std::string& string, const std::vector<int>& vector) {

	std::cout << string << " ";

	for (int element : vector) {
		std::cout << element << " ";
	}
}

int main() {

	std::vector<int> vec = {1,2,3,4,5,6,7,8,9};
	std::vector<int> newVec = reverse1(vec);

	reverse2(vec);

	print("New Vector: ", newVec);
	print("Same Vector: ", vec);

	return 0;
}