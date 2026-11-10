#include <iostream>
#include <vector>
#include <stdexcept>

/*
1. Write a template function f() that adds the elements of one vector<T> to the elements of another; for 
example, f(v1,v2) should do v1[i]+=v2[i] for each element of v1.
*/

template<typename T>
void f(std::vector<T>& v1, const std::vector<T>& v2) {
	int s1 = v1.size();
	int s2 = v2.size();

	if(s1 != s2) throw std::runtime_error("Vectors of different sizes!");

	for (int i = 0; i < s1; i++) {
		v1[i] += v2[i];
	}
}

int main() {

	try {
		std::vector<int> vec1 = { 1,2,3,4,5 };
		std::vector<int> vec2 = { 1,2,3,4,5 };

		f(vec1, vec2);

		for (int i = 0; i < vec1.size(); i++) {
			std::cout << vec1[i] << " ";
		}
		std::cout << "\n";

		for (int i = 0; i < vec2.size(); i++) {
			std::cout << vec2[i] << " ";
		}
		std::cout << "\n";

		std::vector<char> vec3 = { 'a','b','c' };
		std::vector<char> vec4 = { 'a','b','c' };

		f(vec3, vec4);

		for (int i = 0; i < vec3.size(); i++) {
			std::cout << vec3[i] << " ";
		}
		std::cout << "\n";

		for (int i = 0; i < vec4.size(); i++) {
			std::cout << vec4[i] << " ";
		}

		std::vector<char> vec5 = { 'a','b','c' };
		std::vector<char> vec6 = { 'a','b' };

		f(vec5, vec6);
	}
	catch (const std::runtime_error& e) {
		std::cout << "\nError: " << e.what() << "\n";
	}

	return 0;
}