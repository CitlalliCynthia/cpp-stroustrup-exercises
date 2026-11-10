#include <iostream>
#include <stdexcept>

/*
5. Define a class Int having a single member of class int. Define constructors, assignment, and operators +, –,
*, / for it. Test it, and improve its design as needed (e.g., define operators << and >> for convenient I/O).

6. Repeat the previous exercise, but with a class Number<T> where T can be any numeric type. Try adding % to
Number and see what happens when you try to use % for Number<double> and Number<int>.
*/

template<typename T>
class Number {
public:
	Number() : val() {}
	Number(T v) : val(v) {}
	Number(const Number& v) : val(v.val) {}

	Number& operator=(const Number& v) {
		val = v.val;
		return *this;
	}

	friend Number operator+(const Number<T>& a, const Number<T>& b) {
		return Number<T>(a.val + b.val);
	}

	friend Number operator-(const Number<T>& a, const Number<T>& b) {
		return Number<T>(a.val - b.val);
	}

	friend Number operator*(const Number<T>& a, const Number<T>& b) {
		return Number<T>(a.val * b.val);
	}

	friend Number operator/(const Number<T>& a, const Number<T>& b) {
		if (b.val == 0) throw std::runtime_error("Cannot divide by zero!");

		return Number<T>(a.val / b.val);
	}

	friend Number operator%(const Number<T>& a, const Number<T>& b) {
		if (b.val == 0) throw std::runtime_error("Cannot modulo by zero!");
		return Number<T>(a.val % b.val);
	}

	friend std::istream& operator>>(std::istream& ist, Number<T>& v) {
		ist >> v.val;
		return ist;
	}

	friend std::ostream& operator<<(std::ostream& ost, const Number<T>& v) {
		ost << v.val;
		return ost;
	}

private:
	T val;
};

int main() {

	Number<int> var1;
	Number<int> var2(2);
	Number<int> var3(var2);

	Number<int> var4;
	var4 = var3;

	try {
		std::cout << var1 << " + " << var2 << " = " << var1 + var2 << "\n";
		std::cout << var2 << " - " << var2 << " = " << var2 - var3 << "\n";
		std::cout << var3 << " * " << var4 << " = " << var3 * var4 << "\n";
		std::cout << 5 << " * " << var4 << " = " << 5 * var4 << "\n";

		std::cout << "Introduce a number: ";
		std::cin >> var2;

		std::cout << var2 << " / " << var3 << " = " << var2 / var3 << "\n";
		//std::cout << var3 << " / " << var1 << " = ";
		//std::cout << var3 / var1 << "\n"; //error

		Number<double> var5;
		Number<double> var6(2.5);
		std::cout << var5 << " / " << var6 << " = ";
		std::cout << var5 / var6 << "\n";

		var5 = 3.6;
		var6 = 0.0;
		std::cout << var5 << " % " << var6 << " = ";
		//std::cout << var5 % var6 << "\n"; //error
		std::cout << "Prints an error as % doesn't exist for decimals.\n";
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	return 0;
}