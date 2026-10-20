#include <iostream>
#include <vector>

/*
13. Create a program to find all the prime numbers between 1 and 100. There is a classic method for doing this, called the
“Sieve of Eratosthenes.” If you don’t know that method, get on the web and look it up. Write your program using this
method.
14. Modify the program described in the previous exercise to take an input value max and then find all prime numbers from
1 to max.
*/

std::vector<int> isPrime(int n) {

	std::vector<bool> primes(n+1, true);
	for (int p = 2; p * p <= n; p++) {
		if (primes[p] == true) {
			for (int i = p * p; i <= n; i += p) {
				primes[i] = false;
			}
		}
	}

	std::vector<int> result;
	for (int p = 2; p <= n; p++) {
		if (primes[p]) result.push_back(p);
	}

	return result;
}

int main() {

	std::cout << "Please enter a number to find primes until then: ";

	int MAX_LIMIT;

	std::cin >> MAX_LIMIT;

	std::vector<int> resultPrimes = isPrime(MAX_LIMIT);

	for (int prime : resultPrimes) {
		std::cout << prime << " is prime \n";
	}

	return 0;
}