#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include <regex>
#include <chrono>
#include<fstream>
#include<iostream>
using namespace std;

/*
1. Get the email file example to run; test it using a larger file of your own
creation. Be sure to include messages that are likely to trigger errors, such as
messages with two address lines, several messages with the same address and/or
same subject, and empty messages. Also test the program with something that
simply isn’t a message according to that program’s specification, such as a
large file containing no –––– lines.
*/

/*
2. Add a multimap and have it hold subjects. Let the program take an input
string from the keyboard and print out every message with that string as its
subject.
*/

/*
3. Modify the email example from §23.4 to use regular expressions to find the
subject and sender.
*/

/*
4. Find a real email message file (containing real email messages) and modify
the email example to extract subject lines from sender names taken as input from
the user.
*/

/*
5. Find a large email message file (thousands of messages) and then time it as
written with a multimap and with that multimap replaced by an 
unordered_multimap. Note that our application does not take advantage of the 
ordering of the multimap.
*/

typedef vector<string>::const_iterator Line_iter;
class Message { // a Message points to the first and the last lines of a message
	Line_iter first;
	Line_iter last;
public:
	Message(Line_iter p1, Line_iter p2) :first{ p1 }, last{ p2 } { }
	Line_iter begin() const { return first; }
	Line_iter end() const { return last; }

	friend std::ostream& operator<<(std::ostream& ost, const Message& m) {
		for (Line_iter p = m.first; p != m.last; ++p) {
			ost << *p << "\n";
		}
		return ost;
	}
};

using Mess_iter = vector<Message>::const_iterator;
struct Mail_file { // a Mail_file holds all the lines from a file
	// and simplifies access to messages
	string name; // file name
	vector<string> lines; // the lines in order
	vector<Message> m; // Messages in order
	Mail_file(const string& n); // read file n into lines
	Mess_iter begin() const { return m.begin(); }
	Mess_iter end() const { return m.end(); }
};

Mail_file::Mail_file(const string& n)
// open file named n
// read the lines from n into lines
// find the messages in the lines and compose them in m
// for simplicity assume every message is ended by a –––– line
{
	ifstream in{ n }; // open the file
	if (!in) {
		cerr << "no " << n << '\n';
		exit(1); // terminate the program
	}
	for (string s; getline(in, s); ) // build the vector of lines
		lines.push_back(s);
	auto first = lines.begin(); // build the vector of Messages
	for (auto p = lines.begin(); p != lines.end(); ++p) {
		if (*p == "----") { // end of message
			m.push_back(Message(first, p));
			first = p + 1; // –––– not part of message
		}
	}
}

int is_prefix(const string& s, const string& p)
// is p the first part of s?
{
	int n = p.size();
	if (string(s, 0, n) == p) return n;
	return 0;
}
bool find_from_addr(const Message* m, string& s)
{
	static const regex pat{ R"(^From:\s*(.+))" };
	smatch matches;

	for (const auto& x : *m) {
		if (regex_match(x, matches, pat)) {
			s = matches[1];
			return true;
		}
	}
	return false;
}
string find_subject(const Message* m)
{
	static const regex pat{ R"(^Subject:\s*(.*))" };
	smatch matches;

	for (const auto& x : *m) {
		if (regex_match(x, matches, pat)) {
			return matches[1];
		}
	}
	return "";
}

int main()
{
	Mail_file mfile{ "my-mail-file.txt" }; // initialize mfile from a file
	// first gather messages from each sender together in a multimap:
	multimap<string, const Message*> subject;
	unordered_multimap<string, const Message*> subMap;
	for (const auto& m : mfile) {
		string sub = find_subject(&m);
		if (!sub.empty()) {
			subject.insert(make_pair(sub, &m));
			subMap.insert(make_pair(sub, &m));
		}
	}

	std::string subInput;
	std::cout << "Input the subject to find: ";
	std::getline(std::cin, subInput);

	std::cout << "\nMails found with said subject (map):\n\n";
	auto t1 = std::chrono::steady_clock::now();
	typedef multimap<string, const Message*>::iterator Subject_iter;
	std::pair<Subject_iter, Subject_iter> it = subject.equal_range(subInput);
	for (Subject_iter p = it.first; p != it.second; ++p) {
		std::cout << *(p->second) << "----\n";
	}
	auto t2 = std::chrono::steady_clock::now();

	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	auto us = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	std::cout << "\nTime with multimap: " << ms << " ms (" << us << " us)\n";

	std::cout << "\nMails found with said subject (unordered_map):\n\n";
	auto t3 = std::chrono::steady_clock::now();
	typedef unordered_multimap<string, const Message*>::iterator Subject_iterM;
	std::pair<Subject_iterM, Subject_iterM> it1 = subMap.equal_range(subInput);
	for (Subject_iterM p = it1.first; p != it1.second; ++p) {
		std::cout << *(p->second) << "----\n";
	}
	auto t4 = std::chrono::steady_clock::now();

	auto ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count();
	auto us1 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();

	std::cout << "\nTime with unordered_multimap: " << ms1 << " ms (" << us1 << " us)\n";

	return 0;
}