#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

class FileProcessor {

public:
	virtual void process(const std::string& route) = 0;
	virtual ~FileProcessor() {}
};

class LineCounter : public FileProcessor {

public: 
	void process(const std::string& route) {
		std::ifstream ist(route);
		if (!ist) throw std::runtime_error("Can't open input file.");

		int counter = 0;
		for (std::string temp; std::getline(ist, temp);counter++) {}

		std::cout << "The file " << route << " has " << counter << " lines\n\n";
	}
};

class WordsFilter : public FileProcessor {
public:
	WordsFilter(const std::string& word)
		:keyWord(word) {}

	void process(const std::string& route) {
		std::ifstream ist(route);
		if (!ist) throw std::runtime_error("Can't open input file.");

		std::cout << "Lines with the word '" << keyWord << "':\n\n";
		
		for (std::string line; std::getline(ist, line);) {
			std::istringstream ss(line);
			std::string word;
			while (ss >> word) {
				if (word == keyWord) {
					std::cout << ">: " << line << "\n";
					break;
				}
			}
		}
	}

private:
	std::string keyWord;
};

int main() {

	try {
		LineCounter ln;
		ln.process("input.txt");

		WordsFilter wf("ICE");
		wf.process("input.txt");
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what();
	}

	return 0;
}