#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// EPI's solution. Time complexity is O(nk), space is O(k).
unsigned epi_solution(unsigned n, unsigned k) {
	vector<unsigned> table(k + 1, 0);
	table[0] = 1;

	for (unsigned i = 0; i <= n; ++i) {
		for (unsigned j = min(i, k); j >= 1; --j) {
			table[j] = table[j] + table[j - 1];
		}
		table[0] = 1;
	}
	return table[k];
}

// This is even better than EPI's solution. Time complexity if O(k), space is O(k).
// When n is large, this is much faster. 
unsigned binomial_coeff(unsigned k, unsigned n) {
	unsigned arr[k+1];
	arr[0] = 1;
	for (unsigned i = 1; i <= k; i++) {
		// Divide first to avoid overflow
		if (arr[i-1] % i == 0) {
			arr[i] = (arr[i-1]/i) * (n-i+1);
		} else {
			arr[i] = arr[i-1] * ((n-i+1)/i);
		}
	}

	return arr[k];
}

int main(int argc, char *argv[]) {
	cout << "k = 6, n = 100 ==> " << binomial_coeff(6, 100) 
		 << ". EPI ==> " << epi_solution(100, 6) << endl;
	cout << "k = 1, n = 10e9 ==> " << binomial_coeff(1, 1000000000); cout.flush();
	cout << ". EPI ==> " << epi_solution(1000000000, 1) << endl;

	return 0;
}
