#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

/*
7. Write a binary search function for a vector<int> (without using the standard
one). You can choose any interface you like. Test it. How confident are you that
your binary search function is correct? Now write a binary search function for a
list<string>. Test it. How much do the two binary search functions resemble each
other? How much do you think they would have resembled each other if you had not 
known about the STL?
*/

template<typename Ran, typename T>
bool binary_search1(Ran first, Ran last, const T& val) {
    while (first != last) {
        Ran mid = first + (last - first) / 2;

        if (*mid < val) {
            first = mid + 1;
        }
        else if (val < *mid) {
            last = mid;
        }
        else {
            return true;
        }
    }
    return false;
}

template<typename Ran, typename T, typename Cmp>
bool binary_search1(Ran first, Ran last, const T& val, Cmp cmp) {
    while (first != last) {
        Ran mid = first + (last - first) / 2;

        if (cmp(*mid, val)) { //mid < val
            first = mid + 1;
        }
        else if (cmp(val, *mid)) { //val < mid
            last = mid;
        }
        else {
            return true;
        }
    }
    return false;
}

template<typename In, typename T>
// requires Forward_iterator<In>() && Less_than_comparable<Value_type<In>, T>()
bool list_binary_search(In first, In last, const T& val) {
    while (first != last) {
        In mid = first;
        std::advance(mid, std::distance(first, last) / 2);

        if (*mid < val) {
            first = mid;
            ++first;
        }
        else if (val < *mid) {
            last = mid;
        }
        else {
            return true;
        }
    }
    return false;
}

template<typename In, typename T, typename Cmp>
// requires Forward_iterator<In>() && Less_than_comparable<Cmp, Value_type<In>, T>()
bool list_binary_search(In first, In last, const T& val, Cmp cmp) {
    while (first != last) {
        In mid = first;
        std::advance(mid, std::distance(first, last) / 2);

        if (cmp(*mid, val)) { //mid < val
            first = mid;
            ++first;
        }
        else if (cmp(val, *mid)) { //val < mid
            last = mid;
        }
        else {
            return true;
        }
    }
    return false;
}

int main() {
    
    std::vector<std::string> vec;
    vec.push_back("kiwi");
    vec.push_back("apple");
    vec.push_back("orange");
    vec.push_back("banana");

    std::sort(vec.begin(),vec.end());
    
    std::cout << "-- VECTOR --\n";
    std::cout << "Search 'kiwi': " << list_binary_search(vec.begin(), vec.end(), std::string("kiwi")) << "\n";
    std::cout << "Search 'grape': " << list_binary_search(vec.begin(), vec.end(), std::string("grape")) << "\n";
    
    std::list<std::string> lst;
    lst.push_back("kiwi");
    lst.push_back("apple");
    lst.push_back("orange");
    lst.push_back("banana");

    lst.sort();

    std::cout << "\n-- LIST --\n";
    std::cout << "Search 'kiwi': " << list_binary_search(lst.begin(), lst.end(), std::string("kiwi")) << "\n";
    std::cout << "Search 'grape': " << list_binary_search(lst.begin(), lst.end(), std::string("grape")) << "\n";

    return 0;
}

