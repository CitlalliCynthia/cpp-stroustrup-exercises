#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm> //To use std::equal and std::lexicographical_compare
#include <iterator>  //To usestd::begin, std::end and std::distance

template<typename Iter>
void test_STL(Iter first, Iter last) {
    std::cout << "\nElements: " << std::distance(first, last) << "\n";

    const std::string hello("Hello");
    const std::string howdy("Howdy");

    if (std::distance(first, last) == static_cast<std::ptrdiff_t>(hello.size()) &&
        std::equal(first, last, hello.begin())) {
        std::cout << "It's equal to 'Hello'\n";
    }

    if (std::lexicographical_compare(first, last, howdy.begin(), howdy.end())) {
        std::cout << "Hello comes before Howdy in the dictionary\n";
    }

    std::vector<char> copy;
    std::copy(first, last, std::back_inserter(copy));

    std::cout << "Copy: ";
    for (std::vector<char>::const_iterator it = copy.begin(); it != copy.end(); ++it) {
        std::cout << *it;
    }
    std::cout << "\n";
}

int main() {
    const char arr[] = "Hello";
    const char temp[] = { 'H', 'e', 'l', 'l', 'o' };

    std::vector<char> vec(temp, temp + 5);
    std::list<char> lst(temp, temp + 5);
    std::string str("Hello");

    std::cout << "ARR";
    test_STL(arr, arr + 5);
    std::cout << "\nVECTOR";
    test_STL(vec.begin(), vec.end());
    std::cout << "\nLIST";
    test_STL(lst.begin(), lst.end());
    std::cout << "\nSTRING";
    test_STL(str.begin(), str.end());

    return 0;
}