#include <iostream>
#include <vector>
#include <string>
#include <list>

/*
5. What would we have to do if we couldn’t return end() to indicate “not found”?
Redesign and re-implement find() and count() to take iterators to the first and
last elements. Compare the results to the standard versions.
*/

template<typename In>
struct Result{
	In elem;
	bool flag;
	
	Result(const In& e, bool f) : elem(e), flag(f) {}
};

template<typename In, typename T>
// requires Input_iterator<In>()
// && Equality_comparable<Value_type<T>>()
Result<In> my_find(In first, In last, const T& val)
// find the first element in [first,last) that equals val
{
	bool flag = true;
	while (first != last && *first != val) ++first;
	if (first == last && *first != val) flag = false;
	return Result<In>(first,flag);
}

//x=count(b,e,v)
//x is the number of ocurrences of v in [b:e).
template<typename In, typename T>
//// requires Input_iterator<In>() && Equality_comparable<Value_type<T>>()
int count1(In first, In last, const T& v) {
	int counter = 0;
	while (first != last) {
		if (*first == v) counter++;
		++first;
	}

	if (*first == v) counter++;

	return counter;
}

int main() {
    std::vector<int> v = { 10, 20, 30, 40 };

    if (!v.empty()) {
        Result<std::vector<int>::iterator> r1 = my_find(v.begin(), v.end() - 1, 40);
        if (r1.flag) std::cout << "Found: " << *r1.elem << "\n";
        else std::cout << "Not Found\n";

        Result<std::vector<int>::iterator> r2 = my_find(v.begin(), v.end() - 1, 99);
        if (r2.flag) std::cout << "Found: " << *r2.elem << "\n";
        else std::cout << "Not found\n";

		std::cout << "Count of 40 (closed): " << count1(v.begin(), v.end() - 1, 40) << "\n";
		std::cout << "Count of 99 (closed): " << count1(v.begin(), v.end() - 1, 99) << "\n";
    }

    return 0;
}