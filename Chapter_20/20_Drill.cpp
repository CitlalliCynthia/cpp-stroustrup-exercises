#include <iostream>
#include <vector>
#include <list>

/*
1. Define an array of ints with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.
2. Define a vector<int> with those ten elements.
3. Define a list<int> with those ten elements.
4. Define a second array, vector, and list, each initialized as a copy of the 
first array, vector, and list, respectively.
5. Increase the value of each element in the array by 2; increase the value of 
each element in the vector by 3; increase the
value of each element in the list by 5.
6. Write a simple copy() operation,
Click here to view code image
template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2);
that copies [f1,e1) to [f2,f2+(e1–f1)) and returns f2+(e1–f1) just like the 
standard library copy function. Note that if f1==e1 the sequence is empty, so that
there is nothing to copy.
7. Use your copy() to copy the array into the vector and to copy the list into the
array.
8. Use the standard library find() to see if the vector contains the value 3 and
print out its position if it does; use find() to see if the list contains the 
value 27 and print out its position if it does. The “position” of the first 
element is 0, the position of the second element is 1, etc. Note that if find() 
returns the end of the sequence, the value wasn’t found.
Remember to test after each step.
*/

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy1(Iter1 f1, Iter1 e1, Iter2 f2) {
	//if (f1 == e1) return f1;
	std::cout << "Copy: ";
	while (f1 != e1) {
		*f2 = *f1;
		std::cout << *f2 << " ";
		++f2;
		++f1;
	}

	return f2;
}

int main() {
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	std::vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
	std::list<int> lst = {0,1,2,3,4,5,6,7,8,9};
	
	int arr2[10];
	for (int i = 0; i < 10; i++) {
		arr2[i] = arr[i];
	}

	std::vector<int> vec2(vec);
	std::list<int> lst2(lst);

	for (int i = 0; i < 10; i++) {
		arr[i] += 2;
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < vec.size(); i++) {
		vec[i] += 3;
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
	for (std::list<int>::iterator i = lst.begin(); i != lst.end(); i++) {
		*i += 5;
		std::cout << *i << " ";
	}
	std::cout << "\n";

	copy1(arr, arr + 10, vec.begin());
	std::cout << "\n";

	copy1(lst.begin(), lst.end(), arr);
	std::cout << "\n";

	std::vector<int>::iterator p_vec = std::find(vec.begin(), vec.end(), 3);
	if (p_vec != vec.end()) {
		std::cout << "3 found in position: " << std::distance(vec.begin(), p_vec) << "\n";
	}
	else {
		std::cout << "3 not found.\n";
	}

	std::list<int>::iterator p_lst = std::find(lst.begin(), lst.end(), 27);
	if (p_lst != lst.end()) {
		std::cout << "27 found in position: " << std::distance(lst.begin(), p_lst) << "\n";
	}
	else {
		std::cout << "27 not found.\n";
	}

	return 0;
}