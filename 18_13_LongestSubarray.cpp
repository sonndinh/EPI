#include <iostream>
#include <vector>
using namespace std;

// Return a longest subarray with sum less than or equal to k.
// Brute force: O(n^2).
pair<int, int> subarray(const vector<int>& A, int k) {
	int sum = 0;
	for (int a : A) {
		sum += a;
	}
	
	int max_len = 0;
	int start = -1, end = A.size();
	for (int i = 0; i < A.size()-1; i++) {
		if (i > 0) sum -= A[i-1];
		int inner_sum = sum;
		for (int j = A.size()-1; j >= i; j--) {
			if (j < A.size()-1)
				inner_sum -= A[j+1];
			if (inner_sum <= k && j - i + 1 > max_len) {
				max_len = j - i + 1;
				start = i;
				end = j;
			}
		}
	}

	return {start, end};
}

int main() {
	vector<int> A{431, -15, 639, 342, -14, 565, -924, 635, 167, -70};
	int k = 184;
	pair<int, int> p = subarray(A, k);
	cout << "Longest subarray with sum <= " << k << ": " << p.first << ", " << p.second << endl;
	return 0;
}
