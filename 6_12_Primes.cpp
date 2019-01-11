#include <iostream>
#include <vector>

using namespace std;

// Return all primes between 1 and n
vector<unsigned> primes(unsigned n) {
	vector<unsigned> ret; // contains the primes
	vector<unsigned> arr(n+1, 0);

	// Go through array arr, indices with value of 0 are primes
	for (unsigned i = 2; i <= n; i++) {
		if (arr[i] == 0) {
			// Found a prime
			ret.push_back(i);
			// Mark numbers which are not prime
			unsigned j = i + i;
			while (j <= n) {
				arr[j] = 1;
				j += i;
			}
		}
	}

	return ret;
}

int main(int argc, char *argv[]) {
	vector<unsigned> ret = primes(1000);
	cout << ret.size() <<  " primes between 1 and 1000 are: " << endl;

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
	cout << endl;
	return 0;
}
