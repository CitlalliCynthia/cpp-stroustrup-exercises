#include <iostream>

const int BUFFER_SIZE = 5;

class CircularBuffer {
public:
	CircularBuffer()
		:buffer(new int[BUFFER_SIZE]), position(0) {}

	//modifying operations
	void addTo(int value) {
		buffer[position] = value;

		position = (position + 1) % BUFFER_SIZE;
	}

	//nonmodifying operations
	void printBuffer() const {
		const int* ptr = buffer;
		
		std::cout << "[ ";
		for (int i = 0; i < BUFFER_SIZE; i++) {
			if (i == BUFFER_SIZE - 1) std::cout << *(ptr + i) << " ]";
			else std::cout << *(ptr + i) << ", ";
		}
	}

	~CircularBuffer() {
		delete[] buffer;
	}

private:
	int* buffer;
	int position;
};


int main() {

	CircularBuffer buffer;
	for (int i = 0; i < 6; i++) {
		buffer.addTo(i+1);
	}

	buffer.printBuffer();
	
	return 0;
}