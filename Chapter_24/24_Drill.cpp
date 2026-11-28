#include <iostream>
#include <iomanip>
#include <vector>
#include <complex>
#include <cmath>
#include <string>
#include <stdexcept>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

/*
1. Print the size of a char, a short, an int, a long, a float, a double, an int*, 
and a double* (use sizeof, not <limits>).
2. Print out the size as reported by sizeof of Matrix<int> a(10), Matrix<int> b
(100), Matrix<double> c(10), Matrix<int,2> d(10,10), Matrix<int,3> e(10,10,10).
3. Print out the number of elements of each of the Matrixes from 2.
4. Write a program that takes ints from cin and outputs the sqrt() of each int, or
“no square root” if sqrt(x) is illegal for some x (i.e., check your sqrt() return 
values).
5. Read ten floating-point values from input and put them into a Matrix<double>. 
Matrix has no push_back() so be careful to handle an attempt to enter a wrong 
number of doubles. Print out the Matrix.
6. Compute a multiplication table for [0,n)*[0,m) and represent it as a 2D Matrix.
Take n and m from cin and print out the table nicely (assume that m is small 
enough that the results fit on a line).
7. Read ten complex<double>s from cin (yes, cin supports >> for complex) and put 
them into a Matrix. Calculate and output the sum of the ten complex numbers.
8. Read six ints into a Matrix<int,2> m(2,3) and print them out.
*/

int main() {
	std::cout << "The size of a char (" << sizeof(char) <<
		"), the size of a short (" << sizeof(short) << "), the size of an int (" 
		<< sizeof(int) << "), the size of a long ("
		<< sizeof(long) << "), the size of a float (" << sizeof(float) <<
		"), the size of a double (" << sizeof(double) << "), the size of a pointer to int (" << sizeof(int*) << "), the size of a pointer to double (" <<
		sizeof(double*) << ")\n";
	
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10, 10);
	Matrix<int, 3> e(10, 10, 10);

	std::cout << "\nThe size of a Matrix<int>(10) is (" << sizeof(a) <<
		"), the size of Matrix<int>(100) is (" << sizeof(b) <<
		"), the size of Matrix<double>(10) is (" << sizeof(c) <<
		"), the size of Matrix<int,2>(10, 10) is (" << sizeof(d) <<
		"), the size of Matrix<int,3>(10, 10, 10) is (" << sizeof(e) << ")\n\n";

	std::cout << "Size of a: " << a.size() << ", size of b: " << b.size() <<
		", size of c: " << c.size() << ", size of d: " << d.size() <<
		", size of e: " << e.size() << ".\n";

	std::vector<int> vec;
	std::cout << "\nIntroduce integer values:\n";
	for (int temp; std::cin >> temp;) {
		errno = 0;
		int sqr = sqrt(temp);
		if (errno == EDOM)
			std::cerr << "sqrt() not defined for negative argument";
		else {
			std::cout << "The square root of " << temp << " is: " <<
				sqr << "\n";
		}
	}
	
	std::cin.clear();
	std::cin.ignore(1000,'\n');

	Matrix <double> mat(10);
	std::cout << "\nIntroduce 10 float values:\n";
	for (int i = 0; i < 10; i++) {
		double temp; 
		std::cin >> temp;
		mat[i] = temp;
	}
	std::cout << mat;
	
	try {
		int n, m;
		std::cout << "\nIntroduce two numbers: ";
		std::cin >> n >> m;

		Matrix<int, 2> multTable(n,m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				multTable[i][j] = i*j;
			}
		}

		int max_val = (n - 1) * (m - 1);
		int ancho = std::to_string(max_val).length() + 2;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::cout << std::setw(ancho) << multTable(i, j);
			}
			std::cout << '\n';
		}
	
		Matrix <std::complex<double> > mComplex(10);
	
		for (int i = 0; i < 10; i++) {
			double re, im;
			std::cout << "\nEnter two numbers for the complex number, the real part and the imaginary part: ";
			if (std::cin >> re >> im) {
				mComplex[i] = std::complex<double>(re, im);
			}
			else throw std::runtime_error("Bad input.");
		}

		std::complex<double> sum;
		for (int i = 0; i < 10; i++) {
			sum += mComplex[i];
		}

		std::cout << "\nThe sum of the 10 complex numbers is: " << sum << "\n";
	}
	catch (const Matrix_error& e) {
		std::cerr << "Error: " << e.name;
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}

	Matrix<int, 2> sixInts(2,3);

	for (int i = 0; i < 6; i++) {
		std::cin >> sixInts.data()[i];
	}

	std::cout << sixInts << "\n";

	return 0;
}