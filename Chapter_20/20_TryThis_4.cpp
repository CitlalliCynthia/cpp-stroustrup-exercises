#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // To use std::equal and std::lexicographical_compare

/*
Do the previous Try this for an array of int, vector<int>, and list<int> each with the value { 1, 2,
3, 4, 5 }.
*/

void test_STL(const int* arr, int size) {
    std::cout << "\nThe int array has " << size << " elements\n";

    int equal_arr[] = { 1, 2, 3, 4, 5 };
    int bigger_arr[] = { 1, 2, 4, 0, 0 };

    if (std::equal(arr, arr + size, equal_arr))
        std::cout << "I'ts equal to { 1, 2, 3, 4, 5 }\n";

    if (std::lexicographical_compare(arr, arr + size, bigger_arr, bigger_arr + 5))
        std::cout << "Goes before { 1, 2, 4, 0, 0 }\n";

    int copy[5];
    std::cout << "Copy: ";
    for (int i = 0; i < size; ++i) {
        copy[i] = arr[i];
        std::cout << copy[i] << " ";
    }   
    std::cout << "\n";
}

void test_STL(const std::vector<int>& vec) {
    std::cout << "\nThe vector<int> has " << vec.size() << " elements\n";

    std::vector<int> equal_arr = { 1, 2, 3, 4, 5 };
    std::vector<int> bigger_arr = { 1, 2, 4, 0, 0 };

    if (vec == equal_arr) std::cout << "I'ts equal to { 1, 2, 3, 4, 5 }\n";

    if (vec < bigger_arr) std::cout << "Goes before { 1, 2, 4, 0, 0 }\n";

    std::vector<int> copy(vec);
    std::cout << "Copy: ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << copy[i] << " ";
    }
    std::cout << "\n";
}

void test_STL(const std::list<int>& lst) {
    std::cout << "\nThe list<int> has " << lst.size() << " elements\n";

    std::list<int> equal_arr = { 1, 2, 3, 4, 5 };
    std::list<int> bigger_arr = { 1, 2, 4, 0, 0 };

    if (lst == equal_arr) std::cout << "I'ts equal to { 1, 2, 3, 4, 5 }\n";

    if (lst < bigger_arr) std::cout << "Goes before { 1, 2, 4, 0, 0 }\n";

    std::list<int> copy(lst);
    std::cout << "Copy: ";
    for(std::list<int>::const_iterator it = copy.begin(); it != copy.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main() {

    int arr[] = { 1, 2, 3, 4, 5 };
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    std::list<int> lst = { 1, 2, 3, 4, 5 };

    int sz = sizeof(arr) / sizeof(arr[0]);

    test_STL(arr, sz);
    test_STL(vec);
    test_STL(lst);
    
    return 0;
}