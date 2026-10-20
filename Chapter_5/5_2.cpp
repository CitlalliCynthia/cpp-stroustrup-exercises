#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// compute mean and median temperatures
/*
2. If we define the median of a sequence as “a number so that exactly as many elements come before it in the sequence as
come after it,” fix the program in §4.6.3 so that it always prints out a median. Hint: A median need not be an element of
the sequence.
*/
int main()
{
	vector<double> temps; // temperatures
	for (double temp; cin >> temp; ) // read into temp
		temps.push_back(temp); // put temp into vector
	// compute mean temperature:
	double sum = 0;
	for (double x : temps) sum += x;
	cout << "Average temperature: " << sum / temps.size() << '\n';
	// compute median temperature:
	sort(temps.begin(),temps.end()); // sort temperatures

	double median;

	if (temps.size() % 2 != 0)
		median = temps[temps.size() / 2];
	else {
		median = (temps[temps.size() / 2] + temps[(temps.size() / 2) - 1]) / 2.0;
	}
	cout << "Median temperature: " << median << '\n';
}