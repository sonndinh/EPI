#include <iostream>
#include <unordered_set>
using namespace std;


// Test Collatz conjecture for a positive number.
bool Collatz_test(int n, unordered_set<int>& checked) {
	int num = n;
	
	while (n > 1) {
		if (checked.count(n) > 0) {
			// Reuse the verified numbers.
			checked.insert(num);
			return true;
		}
		
		if (n % 2 == 0) {
			n /= 2;
		} else {
			n *= 3;
			n += 1;
		}
	}

	if (n == 1) {
		checked.insert(num);
		return true;
	}
	return false;
}

// Test the Collatz conjecture for the first n positive integers.
bool Collatz_conjecture(int n) {
	// Set of confirmed positive integers.
	unordered_set<int> checked;
	
	for (int i = 1; i <= n; ++i) {
		if (Collatz_test(i, checked) == false)
			return false;
	}

	return true;
}

int main() {
	int n = 100;
	bool ret = Collatz_conjecture(n);
	cout << "Collatz conjecture for " << n << " integers is " << (ret? "TRUE" : "FALSE") << endl;
	return 0;
}
