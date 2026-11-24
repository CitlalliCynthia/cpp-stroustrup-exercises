#include <regex>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	ifstream in{ "file.txt" }; // input file
	if (!in) cerr << "no file\n";
	regex pat{ R"(\w{2}\s*\d{5}(–\d{4})?)" }; // postal code pattern
	int lineno = 0;
	for (string line; getline(in, line); ) { // read input line into input buffer
		++lineno;
		smatch matches; // matched strings go here
		if (regex_search(line, matches, pat))
			cout << lineno << ": " << matches[0] << '\n';
	}
}