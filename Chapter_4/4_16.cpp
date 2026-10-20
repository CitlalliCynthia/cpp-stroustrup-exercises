#include <iostream>
#include <vector>

/*
11. Create a program to find all the prime numbers between 1 and 100. One way to do this is to write a function that will
check if a number is prime (i.e., see if the number can be divided by a prime number smaller than itself) using a vector
of primes in order (so that if the vector is called primes, primes[0]==2, primes[1]==3, primes[2]==5, etc.). Then
write a loop that goes from 1 to 100, checks each number to see if it is a prime, and stores each prime found in a vector.
Write another loop that lists the primes you found. You might check your result by comparing your vector of prime
numbers with primes. Consider 2 the first prime.
12. Modify the program described in the previous exercise to take an input value max and then find all prime numbers from
1 to max.
*/

std::vector<int> primes;

bool isPrime(int n) {

	if (n < 2) return false;

	for (int prime : primes) {
		if (n % prime == 0) return false;
	}

	return true;
}

int main() {

	std::cout << "Please enter a number to find primes until then: ";

	int MAX_LIMIT;

	std::cin >> MAX_LIMIT;

	for (int counter = 1; counter <= MAX_LIMIT; counter++) {
		
		if (isPrime(counter)) {
			primes.push_back(counter);
			std::cout << counter <<" is prime \n";
		}
	}

	return 0;
}