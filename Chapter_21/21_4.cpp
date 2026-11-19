#include <iostream>
#include <vector>
#include <string>
#include <list>

/*
4. Implement count_if() yourself. Test it.
*/

//x=count_if(b,e,p)
//x is the number of elements in [b:e) so that p(x) is true
template<typename In, typename BinOp>
// requires Input_iterator<In>()
// && Predicate<Pred, Value_type<In>>()
int count_if1(In first, In last, BinOp op) {
	int counter = 0;
	while (first != last) {
		if (op(*first)) counter++;
		++first;
	}

	return counter;
}

//Only returns those values lesser than the one specified
template<typename T>
struct lesserThan {
	T elem;
	
	lesserThan(T v) : elem(v) {}
	bool operator()(const T& v) const {
		return v < elem;
	}
};

int main() {

	std::vector<char> vec = { 'a','b','c','d','a' }; //5 elements
	std::list<char> lst = { 'a','b','c','d','a' }; //5 elements
	std::string str = "hello world!";
	char arr[] = "hello world!";

	std::cout << "The number of ocurrences lesser than 'd' in 'vector' is: " << 
	count_if1(vec.begin(), vec.end(), lesserThan<char>('d')) << "\n";

	std::cout << "The number of ocurrences lesser than 'd' in 'list' is: " << 
	count_if1(lst.begin(), lst.end(), lesserThan<char>('d')) << "\n";

	std::cout << "The number of ocurrences lesser than 'i' in 'string' is: " << 
	count_if1(str.begin(), str.end(), lesserThan<char>('i')) << "\n";

	std::cout << "The number of ocurrences lesser than 'i' in 'char array' is: " << 
	count_if1(arr, arr + sizeof(arr) - 1, lesserThan<char>('i')) << "\n";

	return 0;
}