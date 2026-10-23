#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>

/* DRILL:
1. Start a program to work with points, discussed in §10.4. Begin by defining the data type Point that has two coordinate
members x and y.
2. Using the code and discussion in §10.4, prompt the user to input seven (x,y) pairs. As the data is entered, store it in a
vector of Points called original_points.
3. Print the data in original_points to see what it looks like.
4. Open an ofstream and output each point to a file named mydata.txt. On Windows, we suggest the .txt suffix to make
it easier to look at the data with an ordinary text editor (such as WordPad).
5. Close the ofstream and then open an ifstream for mydata.txt. Read the data from mydata.txt and store it in a new
vector called processed_points.
6. Print the data elements from both vectors.
7. Compare the two vectors and print Something's wrong! if the number of elements or the values of elements differ.
*/


/*
void error(const std::string& s) {
	throw std::runtime_error(s);
}
*/

namespace Points {
	struct Point {
		int x, y;

		//nonmodifying operation
		bool operator==(const Point& otherPoint) const {
			return (x == otherPoint.x && y == otherPoint.y);
		}

		bool operator!=(const Point& otherPoint) const {
			return !(*this == otherPoint);
		}
	};

	//Overload of >> so that a Point can be read
	std::istream& operator>>(std::istream& is, Point& p) {
		is >> p.x >> p.y;
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const std::vector<Point>& vec) {
		os << "\n[";
		for (Point p : vec) {
			os << p.x << " " << p.y << "\n";
		}
		os << "]\n";
		return os;
	}
}

//Asking for points and adding them to the vector
void addingPoints(std::istream& ist, std::vector<Points::Point>& vec) {
	
	for (Points::Point p; ist >> p; ) {
		vec.push_back(p);
		std::cout << "\n";
	}
}

int main() {

	try {
		std::vector<Points::Point> original_points;
		std::vector<Points::Point> processed_points;

		std::cout << "Please introduce a set of x, y (numbers separated by a space) until you no longer want to add any more, then introduce whatever else\nExample (1 3):\n\n";

		addingPoints(std::cin, original_points);

		//For the program to reach this point, cin.fail() is true, and has bad data stucked,
		//if one wanted to keep asking for data, it should me managed
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}

		std::ofstream ost("mydata.txt");
		if (!ost) throw std::runtime_error("Can't open output file.");

		for (Points::Point p : original_points) {
			ost << p.x << " " << p.y << "\n";
		}
		ost.close(); //closing it explicilty even though it will be closed once it gets out of scope

		std::ifstream ist("mydata.txt");
		if (!ist) throw std::runtime_error("Can't open input file.");

		addingPoints(ist, processed_points);

		std::cout << "Original_points: " << original_points << "Processed_points: " << processed_points;

		if (original_points != processed_points) std::cout << "Something's wrong!";
		else std::cout << "Both vectors are equal!";
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	}
}
