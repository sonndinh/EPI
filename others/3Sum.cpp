#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <limits>
using namespace std;

// Given an array of integers, find 3 elements such that their sum is closest to
// a given number. Return the sum of the 3 integers, assuming that there will be only 1 solution.
tuple<int, int, int> closest_3sum(vector<int>& A, int t) {
	sort(A.begin(), A.end());
	tuple<int, int, int> ret;
	// Keep track the indices of the best triplet.
	int idx1 = -1, idx2 = -1, idx3 = -1;
	int diff = numeric_limits<int>::max();
	
	for (int i = 0; i < A.size()-2; i++) {
		// Skip duplicates.
		if (i == 0 || (i > 0 && A[i] != A[i-1])) {
			int first_elem = A[i];
			int sum = t - first_elem; // Expected sum of the other 2 elements.
			
			// Find the other 2 elements.
			for (int k = i+1, l = A.size()-1; k < l;) {
				if (k == i+1 || (k > i+1 && A[k] != A[k-1])) {
					if (A[k] + A[l] == sum) {
						return make_tuple(first_elem, A[k], A[l]);
					} else if (A[k] + A[l] > sum) {
						// Find a closer tuple, update result.
						if (abs(A[k] + A[l] - sum) < diff) {
							idx1 = i; idx2 = k; idx3 = l;
							diff = abs(A[k] + A[l] - sum);
						}
						l--;
					} else {
						if (abs(A[k] + A[l] - sum) < diff) {
							idx1 = i; idx2 = k; idx3 = l;
							diff = abs(A[k] + A[l] - sum);
						}
						k++;
					}
				} else {
					// Skip duplicates.
					k++;
				}
			}
		}
	}
	
	return make_tuple(A[idx1], A[idx2], A[idx3]);
}

int main() {
	vector<int> A{-1, 2, 1, -4};
	int target = 1;
	auto ret = closest_3sum(A, target);
	cout << "Closest tuple: (" << get<0>(ret) << ", " << get<1>(ret) << ", " << get<2>(ret) << ")" << endl;
	return 0;
}
