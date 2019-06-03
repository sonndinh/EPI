#include <iostream>
#include <unordered_set>
using namespace std;


// Test Collatz conjecture for a positive number.
bool Collatz_test(int n, unordered_set<long>& checked) {
	// Store the sequence of this input number.
	unordered_set<long> sequence;

	long test_n = n;
	// When we test for n, all numbers smaller than n have already been verified.
	while (test_n >= n) {
		if (checked.count(test_n) > 0) {
			// Reuse the verified numbers.
			checked.insert(n);
			return true;
		}
		// It is safe to add test_n to the set of verified numbers here since
		// if n converges to 1, test_n also converges to 1. If n does not converge to 1,
		// then the algorithm guarantees to return false, which terminates the program.
		checked.insert(test_n);

		if (sequence.count(test_n) > 0) {
			// Infinite loop detected.
			return false;
		}
		sequence.insert(test_n);
		
		if (test_n % 2 == 0) {
			test_n /= 2;
		} else {
			long temp = test_n * 3 + 1;
			if (temp <= test_n) {
				throw overflow_error("Collatz conjecture failed at number " + to_string(n));
			}
		}
	}

	// test_n becomes less than n, which means it converges to 1.
	return true;
}

// Test the Collatz conjecture for the first n positive integers.
bool Collatz_conjecture(int n) {
	// Set of confirmed positive integers.
	unordered_set<long> checked;
	
	for (int i = 2; i <= n; ++i) {
		if (Collatz_test(i, checked) == false)
			return false;
	}

	return true;
}

int main() {
	int n = 100000;
	bool ret = Collatz_conjecture(n);
	cout << "Collatz conjecture for " << n << " integers is " << (ret? "TRUE" : "FALSE") << endl;
	return 0;
}
