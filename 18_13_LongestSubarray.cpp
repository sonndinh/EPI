#include <iostream>
#include <vector>
#include <numeric>
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

// EPI solution. Time complexity O(n), space complexity O(n).
pair<int, int> longest_subarray(const vector<int>& A, int k) {
	vector<int> prefix_sum;
	partial_sum(A.cbegin(), A.cend(), back_inserter(prefix_sum));

	if (prefix_sum.back() <= k) {
		return {0, A.size()-1};
	}

	vector<int> min_prefix_sum(A.size());
	min_prefix_sum.back() = prefix_sum.back();
	for(int i = min_prefix_sum.size()-2; i >= 0; i--) {
		min_prefix_sum[i] = min(prefix_sum[i], min_prefix_sum[i+1]);
	}

	int a = 0, b = 0, max_length = 0;
	pair<int, int> ret(-1, -1);
	while (a < A.size() && b < A.size()) {
		int min_curr_sum = a > 0 ? min_prefix_sum[b] - prefix_sum[a-1] : min_prefix_sum[b];
		if (min_curr_sum <= k) {
			int curr_length = b - a + 1;
			if (curr_length > max_length) {
				max_length = curr_length;
				ret = {a, b};
			}
			++b;
		} else {
			++a;
		}
	}

	return ret;
}


int main() {
	vector<int> A{431, -15, 639, 342, -14, 565, -924, 635, 167, -70};
	int k = 184;
	pair<int, int> p = longest_subarray(A, k);
	cout << "Longest subarray with sum <= " << k << ": " << p.first << ", " << p.second << endl;
	return 0;
}
