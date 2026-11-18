#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>

/*
More vector use :
1. Read some floating - point values(at least 16 values) from a file into a
vector<double> called vd.
2. Output vd to cout.
3. Make a vector vi of type vector<int> with the same number of elements as vd;
copy the elements from vd into vi.
4. Output the pairs of(vd[i], vi[i]) to cout, one pair per line.
5. Output the sum of the elements of vd.
6. Output the difference between the sum of the elements of vd and the sum of the
elements of vi.
7. There is a standard library algorithm called reverse that takes a sequence(pair
of iterators) as arguments; reverse vd, and output vd to cout.
8. Compute the mean value of the elements in vd; output it.
9. Make a new vector<double> called vd2 and copy all elements of vd with values
lower than(less than) the mean into vd2.
10. Sort vd; output it again.
*/

template<typename T>
void print_all(const std::vector<T>& vec) {
	std::cout << "\n{";
	for (int i = 0; i < vec.size(); i++) {
		if (i == vec.size() - 1) std::cout << vec[i] << "}\n";
		else std::cout << vec[i] << ", ";
	}
}

template<typename T, typename A>
void print_all(const std::vector<T>& a, const std::vector<A>& b) {
	for (int i = 0; i < a.size(); i++) {
		std::cout << "\n(" << a[i] << "," << b[i] << ")";
	}
}

struct copyByMean {
	double mean;

	copyByMean(double m) : mean(m) {}
	bool operator()(double elem) const {
		return elem < mean;
	}
};

int main() {

	try {
		std::ifstream ist("input21_3.txt");
		if (!ist) throw std::runtime_error("Can't open input file.");
		
		std::vector<double> vd;

		for (double val; ist >> val;) {
			vd.push_back(val);
		}

		if (vd.empty()) throw std::runtime_error("Empty input file.");

		print_all(vd);

		std::vector<int> vi(vd.begin(), vd.end()); //This truncates the decimal

		std::cout << "\n-- (vd[i],vi[i]) --\n";
		print_all(vd,vi);

		std::cout << "\nThe sum of elements of vd is: " <<
		std::accumulate(vd.begin(),vd.end(),0.0) << "\n";

		std::cout << "\nThe difference between the sum of elements of vd and the sum of elements in vi, is: " <<
			std::accumulate(vd.begin(), vd.end(), 0.0) - std::accumulate(vi.begin(), vi.end(), 0) << "\n";

		std::reverse(vd.begin(), vd.end());

		std::cout << "\nVD REVERSED:";
		print_all(vd);

		double mean = std::accumulate(vd.begin(), vd.end(), 0.0) / vd.size();
		std::cout << "\nThe mean value in vd is: " << mean << "\n";

		std::vector<double> vd2;
		std::copy_if(vd.begin(), vd.end(), std::back_inserter(vd2), copyByMean(mean));

		std::sort(vd2.begin(), vd2.end());

		std::cout << "\nLESSER THAN MEAN, AND SORTED:";
		print_all(vd2);

		std::sort(vd.begin(), vd.end());

		std::cout << "\nORIGINAL SORTED:";
		print_all(vd);

	}
	catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
	
	return 0;
}