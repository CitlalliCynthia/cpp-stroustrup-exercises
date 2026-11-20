#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

/*
8. Take the word-frequency example from §21.6.1 and modify it to output its lines 
in order of frequency (rather than in lexicographical order). An example line 
would be 3: C++ rather than C++: 3.
*/

/*
SUGGESTED INPUT: 
C++ is a general purpose programming language designed to make programming more
enjoyable for the serious
programmer. Except for minor details, C++ is a superset of the C programming 
language. In addition to the facilities
provided by C, C++ provides flexible and efficient facilities for defining new 
types.
*/

struct Sort_by_freq {
	bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
		return a.second < b.second;
	}
};

int main()
{
	std::map<std::string, int> words; // keep (word,frequency) pairs
	for (std::string s; std::cin >> s; )
		++words[s]; // note: words is subscripted by a string
	
	std::vector<std::pair<std::string, int> > freq_words(words.begin(), words.end());
	
	std::sort(freq_words.begin(), freq_words.end(), Sort_by_freq());

	for (std::vector<std::pair<std::string, int> >::const_iterator p = freq_words.begin(); p != freq_words.end(); ++p) {
		std::cout << p->second << ": " << p->first << '\n';
	}
}