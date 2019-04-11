#include <iostream>
#include <vector>
using namespace std;

// Return all ways to advance to the destination given that
// one can take 1 - k step at a time, and it takes n steps to reach destination.
int steps(int n, int k) {
	vector<int> dp(n+1);

	// Base case.
	dp[0] = 1;
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j <= k && i >= j; j++) {
			dp[i] += dp[i-j];
		}
	}
	return dp[n];
}

int main() {
	int n = 4, k = 2;
	cout << "Number of ways for n=" << n << ", k=" << k << ": " << steps(n, k) << endl;
	return 0;
}
