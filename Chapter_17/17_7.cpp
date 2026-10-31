#include <iostream>

/*
7. Write a program that reads characters from cin into an array that you allocate on the free store. Read individual characters until an exclamation mark (!) is entered. Do not use a std::string. Do not worry about memory exhaustion
*/

//Assumes new array is bigger than the old array
void copyArray(const char* copyFrom, int sizeOriginal, char* copyTo) {
	for (int i = 0; i < sizeOriginal; i++) {
		copyTo[i] = copyFrom[i];
	}
}

int main() {

	const int SIZE_ARRAY = 10;

	char* array = new char[SIZE_ARRAY];
	int size = SIZE_ARRAY;
	int counter = 0;
	
	for (char temp; std::cin >> temp;) {
		if (temp == '!')  break;

		if (counter <= size - 1) {
			array[counter] = temp;
		}
		else {
			char* copiedArray = new char[size * 2];
			copyArray(array, size, copiedArray);
			size *= 2;
			delete[] array;
			array = copiedArray;

			array[counter] = temp;
		}

		counter++;
	}
	
	for(int i = 0; i < counter; i++) {
		std::cout << array[i] << " ";
	}

	delete[] array;
}