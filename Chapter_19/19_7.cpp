#include <iostream>
#include <vector>
#include <stdexcept>

/*
7. Try your solution to exercise 2 with some Numbers.
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

	friend Number& operator+=(Number<T>& a, const Number<T>& b) {
		a.val += b.val;
		return a;
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

template<typename R, typename T, typename U>
R f(const std::vector<T>& vt, const std::vector<U>& vu) {

	if (vt.size() != vu.size()) throw std::runtime_error("Vectors of different sizes!");

	R sum = R();

	for (int i = 0; i < vt.size(); i++) {
		sum += vt[i] * vu[i];
	}

	return sum;
}

int main() {

	try {
		std::vector<Number<double> > v_num1;
		v_num1.push_back(Number<double>(2.0));
		v_num1.push_back(Number<double>(3.0));

		std::vector<Number<double> > v_num2;
		v_num2.push_back(Number<double>(1.5));
		v_num2.push_back(Number<double>(2.5));

		Number<double> res = f<Number<double> >(v_num1, v_num2);
		std::cout << "Result con Number: " << res << "\n";
	}
	catch (const std::runtime_error& e) {
		std::cout << "\nError: " << e.what() << "\n";
	}

	return 0;
}