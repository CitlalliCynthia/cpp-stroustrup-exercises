#include <iostream>

/*
Write a function void copy(int* f1, int* e1, int* f2) that copies the elements of an array of ints
defined by [f1:e1) into another [f2:f2+(e1–f1)). Use only the iterator operations mentioned above (not
subscripting).
*/

void copy(int* f1, int* e1, int* f2) {
	while (f1 != e1) {
		*f2 = *f1;

		++f1;
		++f2;
	}
}

int main() {

	int from[5] = { 10, 20, 30, 40, 50 };
	int to[5] = { 0 };

	copy(from, from + 5, to);

	for (int i = 0; i < 5; ++i) {
		std::cout << to[i] << ' ';
	}
	
	return 0;
}