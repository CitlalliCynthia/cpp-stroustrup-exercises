#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>

/*
6. In the Fruit example in §21.6.5, we copy Fruits into the set. What if we didn’t
want to copy the Fruits? We could have a set<Fruit*> instead. However, to do that,
we’d have to define a comparison operation for that set. Implement the Fruit
example using a set<Fruit*, Fruit_comparison>. Discuss the differences between the
two implementations.
*/

struct Fruit {
	std::string name;
	int count;
	double unit_price;

	Fruit(const std::string& n, int c = 1, double up = 0.0)
		: name(n), count(c), unit_price(up) {}

	friend std::ostream& operator<<(std::ostream& ost, const Fruit& f) {
		ost << f.name << " " << f.count << " " << f.unit_price;
		return ost;
	}
};

struct Fruit_comparison {
	bool operator()(const Fruit* a, const Fruit* b) const
	{
		return a->name < b->name;
	}
};

int main() {

	Fruit f1("grapes", 5, 1.50);
	Fruit f2("apple", 200, 0.37);
	Fruit f3("orange", 100, 0.50);

	std::set<Fruit*, Fruit_comparison> inventory;

	inventory.insert(&f1);
	inventory.insert(&f2);
	inventory.insert(&f3);
	
	for (std::set<Fruit*, Fruit_comparison>::const_iterator p = inventory.begin();
		p != inventory.end(); ++p) {
		
		std::cout << (**p) << "\n";
	}

	return 0;
}