#include <iostream>
#include <vector>
#include <string>

/*
2. Write a function print() that prints a vector of ints to cout. Give it two arguments: a string for “labeling” the output
and a vector.
3. Create a vector of Fibonacci numbers and print them using the function from exercise 2. To create the vector, write a
function, fibonacci(x,y,v,n), where integers x and y are ints, v is an empty vector<int>, and n is the number of
elements to put into v; v[0] will be x and v[1] will be y. A Fibonacci number is one that is part of a sequence where each
element is the sum of the two previous ones. For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, . . . . Your
fibonacci() function should make such a sequence starting with its x and y arguments.
*/

void fibonacci(int x, int y, std::vector<int>& v, int n) {

	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			v.push_back(x);
			sum = x;
		}
		else if (i == 1) {
			v.push_back(y);
			sum = x + y;
		}
		else {
			v.push_back(sum);
			sum = v[i] + v[i-1];
		}
	}
}

void print(const std::string& string, const std::vector<int>& vector) {

	std::cout << string << ": ";

	for (int element : vector) {
		std::cout << element << " ";
	}
}

int main() {

	const std::string label = "Fibonacci";
	std::vector<int> vec;
	int x = 1, y = 2, n = 10;

	fibonacci(x, y, vec, n);

	print(label, vec);
	
	return 0;
}