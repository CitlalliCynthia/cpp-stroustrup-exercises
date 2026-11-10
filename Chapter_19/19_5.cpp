#include <iostream>
#include <stdexcept>

/*
5. Define a class Int having a single member of class int. Define constructors, assignment, and operators +, –,
*, / for it. Test it, and improve its design as needed (e.g., define operators << and >> for convenient I/O).
*/

class Int {
public:
	Int() : val(0) {}
	Int(int v) : val(v) {}
	Int(const Int& v) : val(v.val) {}

	Int& operator=(const Int& v) {
		val = v.val;
		return *this;
	}

	friend Int operator+(const Int& a, const Int& b) {
		return Int(a.val + b.val);
	}

	friend Int operator-(const Int& a, const Int& b) {
		return Int(a.val - b.val);
	}
	
	friend Int operator*(const Int& a, const Int& b) {
		return Int(a.val * b.val);
	}

	friend Int operator/(const Int& a, const Int& b) {
		if (b.val == 0) throw std::runtime_error("Cannot divide by zero!");
		
		return Int(a.val / b.val);
	}

	friend std::istream& operator>>(std::istream& ist, Int& v) {
		ist >> v.val;
		return ist;
	}

	friend std::ostream& operator<<(std::ostream& ost, const Int& v) {
		ost << v.val;
		return ost;
	}

private:
	int val;
};

int main() {

	Int var1;
	Int var2(2);
	Int var3(var2);
	
	Int var4;
	var4 = var3;
	
	try {
		std::cout << var1 << " + " << var2 << " = " << var1 + var2 << "\n";
		std::cout << var2 << " - " << var2 << " = " << var2 - var3 << "\n";
		std::cout << var3 << " * " << var4 << " = " << var3 * var4 << "\n";
		std::cout << 5 << " * " << var4 << " = " << 5 * var4 << "\n";

		std::cout << "Introduce a number: ";
		std::cin >> var2;

		std::cout << var2 << " / " << var3 << " = " << var2 / var3 << "\n";
		std::cout << var3 << " / " << var1 << " = ";
		std::cout << var3 / var1 << "\n"; //error
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	return 0;
}