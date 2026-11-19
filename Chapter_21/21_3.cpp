#include <iostream>
#include <vector>
#include <string>
#include <list>

/*
3. Implement count() yourself. Test it.
*/

//x=count(b,e,v)
//x is the number of ocurrences of v in [b:e).
template<typename In, typename T>
//// requires Input_iterator<In>() && Equality_comparable<Value_type<T>>()
int count1(In first, In last, const T& v) {
	int counter = 0;
	while (first != last) {
		if(*first == v) counter++;
		++first;
	}

	return counter;
}

int main() {

	std::vector<char> vec = {'a','b','c','d','a'}; //4 elements
	std::list<char> lst = { 'a','b','c','d','a' }; //4 elements
	std::string str = "hello world!";
	char arr[] = "hello world!";

	std::cout << "The number of ocurrences of 'a' in 'vector' is: " << count1(vec.begin(), vec.end(), 'a') << "\n";

	std::cout << "The number of ocurrences of 'a' in 'list' is: " << count1(lst.begin(), lst.end(), 'a') << "\n";

	std::cout << "The number of ocurrences of 'l' in 'string' is: " << count1(str.begin(),str.end(), 'l') << "\n";

	std::cout << "The number of ocurrences of 'l' in 'char array' is: " << count1(arr, arr + sizeof(arr) - 1, 'l') << "\n";
	
	return 0;
}