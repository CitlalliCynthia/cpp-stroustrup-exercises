#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

/*
12. Define a File_handle class with a constructor that takes a string argument (the file name), opens
the file in the constructor, and closes it in the destructor.
*/

class File_handle {
	std::ifstream fs;
	File_handle(const File_handle&);
	File_handle& operator=(const File_handle&);

public:
	File_handle(const std::string& f) : fs(f) {
		if (!fs) throw std::runtime_error("Can't open input file!\n");
	}

	std::ifstream& accessFile() {
		return fs;
	}

	~File_handle() {
		fs.close();
	}
};

int main() {

	try {
		File_handle file("input.txt");

		for (std::string temp; file.accessFile() >> temp;) {
			std::cout << temp << " ";
		}
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what();
	}

	return 0;
}