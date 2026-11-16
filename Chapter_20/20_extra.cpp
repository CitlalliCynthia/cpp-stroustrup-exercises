#include <iostream>
#include <vector>
#include <list>

/*
Return an iterator pointing to the highest value found in the range given
*/

template<typename Iter>
Iter high(Iter first, Iter last) {
    Iter highest = first;

    while (first != last) {
        if (*highest < *first) highest = first;
        ++first;
    }

    return highest;
}

int main() {
    double arr[] = { 12.5, 45.2, 8.9, 99.1, 3.4 };
    std::vector<int> vec = { 10, 20, 5, 40, 15 };
    std::list<char> lst = { 'a', 'z', 'm', 'b' };

    double* p_arr = high(arr, arr + 5);
    std::vector<int>::iterator p_vec = high(vec.begin(), vec.end());
    std::list<char>::iterator p_lst = high(lst.begin(), lst.end());

    if (p_arr != arr + 5) std::cout << "Mayor en array: " << *p_arr << "\n";
    if (p_vec != vec.end()) std::cout << "Mayor en vector: " << *p_vec << "\n";
    if (p_lst != lst.end()) std::cout << "Mayor en list: " << *p_lst << "\n";

    return 0;
}