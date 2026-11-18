#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>

/*
After each operation (as defined by a line of this drill) print the vector.
1. Define a struct Item { string name; int iid; double value; ////// }; , make a 
vector<Item>, vi, and fill it with
ten items from a file.
2. Sort vi by name.
3. Sort vi by iid.
4. Sort vi by value; print it in order of decreasing value(i.e., largest value 
first).
5. Insert Item("horse shoe", 99, 12.34) and Item("Canon S400", 9988, 499.95).
6. Remove(erase) two Items identified by name from vi.
7. Remove(erase) two Items identified by iid from vi.
8. Repeat the exercise with a list<Item> rather than a vector<Item>.
*/

struct Item {
	std::string name;
	int iid;
	double value;

	//Item() {}
	Item(const std::string& s, int i, double d) 
		: name(s), iid(i), value(d) {}

	friend std::ostream& operator<<(std::ostream& ost, const Item& it) {
		ost << "Name: " << it.name <<
			", Iid: " << it.iid << ", Value: " << it.value;
		return ost;
	}
};

struct Cmp_by_name {
	bool operator()(const Item& a, const Item& b) const
	{
		return a.name < b.name;
	}
};

struct Cmp_by_iid {
	bool operator()(const Item& a, const Item& b) const
	{
		return a.iid < b.iid;
	}
};

struct Cmp_by_value {
	bool operator()(const Item& a, const Item& b) const
	{
		return a.value > b.value;
	}
};

struct Find_by_name {
	std::string name;
	Find_by_name(const std::string& n) : name(n) {}
	bool operator()(const Item& it) const {
		return it.name == name;
	}
};

struct Find_by_iid {
	int iid;
	Find_by_iid(int id) : iid(id) {}
	bool operator()(const Item& it) const {
		return it.iid == iid;
	}
};

template<typename T>
void print_all(const std::string& label, const T& vi) {
	std::cout << "\n--- " << label << " ---\n";
	for (typename T::const_iterator p = vi.begin(); p != vi.end(); ++p) {
		std::cout << *p << "\n";
	}
}

int main() {

	try {
		std::vector<Item> vi;
		std::list<Item> lst;
		
		std::ifstream ist("input21_1.txt");
		if (!ist) throw std::runtime_error("Can't open input file");

		for (std::string str; getline(ist, str);) {
			int id;
			double val;
			std::string nam;
			std::istringstream ss(str);

			ss >> nam >> id >> val;

			if (ss.fail()) throw std::runtime_error("Bad input!");

			vi.push_back(Item(nam,id,val));
			lst.push_back(Item(nam, id, val));
		}

		std::cout << "/// VECTOR ///\n\n";

		print_all("ORIGINAL", vi);

		std::sort(vi.begin(), vi.end(),Cmp_by_name());
		print_all("SORTED BY NAME", vi);

		std::sort(vi.begin(), vi.end(), Cmp_by_iid());
		print_all("SORTED BY IID", vi);

		std::sort(vi.begin(), vi.end(), Cmp_by_value());
		print_all("SORTED BY VALUE (DECREASING)", vi);
		
		vi.push_back(Item("horse shoe", 99, 12.34));
		vi.push_back(Item("Canon S400", 9988, 499.95));

		print_all("AFTER ADDING ITEMS", vi);
		
		std::vector<Item>::iterator it_name1 = std::find_if(vi.begin(), vi.end(), Find_by_name("horse shoe"));
		if (it_name1 != vi.end()) vi.erase(it_name1);

		std::vector<Item>::iterator it_name2 = std::find_if(vi.begin(), vi.end(), Find_by_name("Canon S400"));
		if (it_name2 != vi.end()) vi.erase(it_name2);

		print_all("AFTER ERASING BY NAME", vi);

		std::vector<Item>::iterator it_id1 = std::find_if(vi.begin(), vi.end(), Find_by_iid(10));
		if (it_id1 != vi.end()) vi.erase(it_id1);

		std::vector<Item>::iterator it_id2 = std::find_if(vi.begin(), vi.end(), Find_by_iid(9));
		if (it_id2 != vi.end()) vi.erase(it_id2);

		print_all("AFTER ERASING BY IID", vi);

		////////////////////////////////////////////////////

		std::cout << "\n\n/// LIST ///\n\n";

		lst.sort(Cmp_by_name());
		print_all("SORTED BY NAME", lst);

		lst.sort(Cmp_by_iid());
		print_all("SORTED BY IID", lst);

		lst.sort(Cmp_by_value());
		print_all("SORTED BY VALUE (DECREASING)", lst);

		lst.push_back(Item("horse shoe", 99, 12.34));
		lst.push_back(Item("Canon S400", 9988, 499.95));

		print_all("AFTER ADDING ITEMS", lst);

		std::list<Item>::iterator lit_name1 = std::find_if(lst.begin(), lst.end(), Find_by_name("horse shoe"));
		if (lit_name1 != lst.end()) lst.erase(lit_name1);

		std::list<Item>::iterator lit_name2 = std::find_if(lst.begin(), lst.end(), Find_by_name("Canon S400"));
		if (lit_name2 != lst.end()) lst.erase(lit_name2);

		print_all("AFTER ERASING BY NAME", lst);

		std::list<Item>::iterator lit_id1 = std::find_if(lst.begin(), lst.end(), Find_by_iid(10));
		if (lit_id1 != lst.end()) lst.erase(lit_id1);

		std::list<Item>::iterator lit_id2 = std::find_if(lst.begin(), lst.end(), Find_by_iid(9));
		if (lit_id2 != lst.end()) lst.erase(lit_id2);

		print_all("AFTER ERASING BY IID", lst);

	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	}
	
	return 0;
}