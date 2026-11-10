#include <iostream>
#include <string>
#include <vector>

/*
1. Define template<typename T> struct S { T val; };.
2. Add a constructor, so that you can initialize with a T.
3. Define variables of types S<int>, S<char>, S<double>, S<string>, and S<vector<int>>; initialize them with
values of your choice.
4. Read those values and print them.
5. Add a function template get() that returns a reference to val.
6. Put the definition of get() outside the class.
7. Make val private.
8. Do 4 again using get().
9. Add a set() function template so that you can change val.
10. Replace set() with an S<T>::operator=(const T&). Hint: Much simpler than §19.2.5.
11. Provide const and non-const versions of get().
12. Define a function template<typename T> read_val(T& v) that reads from cin into v.
13. Use read_val() to read into each of the variables from 3 except the S<vector<int>> variable.
14. Bonus: Define input and output operators (>> and <<) for vector<T>s. For both input and output use a { val,
val, val }
format. That will allow read_val() to also handle the S<vector<int>> variable.
Remember to test after each step.
*/

template<typename T>
std::ostream& operator<<(std::ostream& ost, const std::vector<T>& v) {
	ost << "{ ";
	for (int i = 0; i < v.size(); i++) {
		ost << v[i];
		if (i < v.size() - 1) {
			ost << ", ";
		}
	}
	ost << " }";
	return ost;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
	char ch;
	is >> ch;
	if (ch != '{') {
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}

	std::vector<T> temp;

	is >> ch;
	if (ch == '}') {
		v = temp;
		return is;
	}
	else {
		is.unget();
	}

	for (T val; is >> val; ) {
		temp.push_back(val);

		is >> ch;
		if (ch == '}') {
			v = temp;
			return is;
		}
		if (ch != ',') {
			is.clear(std::ios_base::failbit);
			return is;
		}
	}

	return is;
}


template<typename T> struct S { 
public:
	S(T t) : val(t) {}

	T& get();
	const T& get() const;

	//modifying operations
	void operator=(const T&);
		
	friend std::ostream& operator<<(std::ostream& ost, const S& s) {
		ost << s.val;
		return ost;
	}

private:
	T val;
};

template<typename T>
T& S<T>::get() {
	return val;
}

template<typename T>
const T& S<T>::get() const {
	return val;
}

template<typename T>
void S<T>::operator=(const T& t) {
	val = t;
}

template<typename T>
void read_val(T& v) {
	std::cin >> v;
}

int main() {

	S<int> var1(1);
	S<char> var2('a');
	S<double> var3(1.1);
	S<std::string> var4("Hello World!");
	S<std::vector<int> > var5(std::vector<int>(3));
	
	std::cout << var1 << "\n";
	std::cout << var2 << "\n";
	std::cout << var3 << "\n";
	std::cout << var4 << "\n";
	
	/*
	for (int i = 0; i < var5.val.size(); i++) {
		std::cout << var5.val[i] << " ";
	}
	std::cout << "\n";
	*/

	std::cout << var1.get() << "\n";
	std::cout << var2.get() << "\n";
	std::cout << var3.get() << "\n";
	std::cout << var4.get() << "\n";

	for (int i = 0; i < var5.get().size(); i++) {
		std::cout << var5.get()[i] << " ";
	}


	std::cout << "\n\nWrite an int, a char, a double and a string:\n";

	read_val(var1.get());
	read_val(var2.get());
	read_val(var3.get());
	read_val(var4.get());

	std::cout << var1.get() << "\n";
	std::cout << var2.get() << "\n";
	std::cout << var3.get() << "\n";
	std::cout << var4.get() << "\n";

	std::cout << "\nWrite a new vector with format { 10, 20, 30 }: \n";

	read_val(var5.get());

	std::cout << "\n" << var5.get() << "\n";

	return 0;
}