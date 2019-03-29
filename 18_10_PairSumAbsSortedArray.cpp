#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Return indices when both numbers are non-negative.
pair<int, int> both_positive(const vector<int>& A, int k) {
	for (int i = 0, j = A.size()-1; i < j;) {
		if (A[i] < 0) {
			i++; // Skip negative entries.
		} else if (A[j] < 0) {
			j--; // Skip negative entries.
		} else if (A[i] + A[j] == k) {
			return make_pair(i, j);
		} else if (A[i] + A[j] > k) {
			j--;
		} else {
			i++;
		}
	}
	return make_pair(-1, -1);
}

// Return indices when both numbers are negative.
pair<int, int> both_negative(const vector<int>& A, int k) {
	for (int i = A.size()-1, j = 0; i > j;) {
		if (A[i] >= 0) {
			i--;
		} else if (A[j] >= 0) {
			j++;
		} else if (A[i] + A[j] == k) {
			return make_pair(j, i);
		} else if (A[i] + A[j] < k) {
			i--;
		} else {
			j++;
		}
	}
	return make_pair(-1, -1);
}

// Return indices when one is non-negative and the other is negative.
pair<int, int> positive_and_negative(const vector<int>& A, int k) {
	for (int i = A.size()-1, j = A.size()-1; i >= 0 && j >= 0;) {
		if (A[i] < 0) {
			i--; // i is an index for the non-negative number.
		} else if (A[j] >= 0) {
			j--; // j is an index for the negative number.
		} else if (A[i] + A[j] == k) {
			return make_pair(i, j);
		} else if (A[i] + A[j] < k) {
			j--;
		} else {
			i--;
		}
	}
	return make_pair(-1, -1);
}

// Return indices of pair of numbers whose absolute values sum up to k.
// The input array is abs-sorted.
pair<int, int> find_pair(const vector<int>& A, int k) {
	if (k >= 0) {
		auto indices = both_positive(A, k);
		if (indices.first >= 0 && indices.second >= 0)
			return indices;
	} else {
		auto indices = both_negative(A, k);
		if (indices.first >= 0 && indices.second >= 0)
			return indices;
	}
	return positive_and_negative(A, k);
}

int main() {
	vector<int> A{-49, 75, 103, -147, 164, -197, -238, 314, 348, -422};
	int k = -94;
	auto p = find_pair(A, k);
	cout << "Two numbers at: " << p.first << ", " << p.second << endl;
	return 0;
}
