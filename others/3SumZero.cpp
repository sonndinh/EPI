#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

// Find all unique triplets in an unsorted array that sum to 0.
// Elements in triplets must be in non-decreasing order.
vector<tuple<int, int, int>> threesum_zero(vector<int>& A) {
	sort(A.begin(), A.end());
	vector<tuple<int, int, int>> ret;
	for (int i = 0; i < A.size()-2; i++) {
		// Skip duplicates.
		if (i == 0 || (i > 0 && A[i] != A[i-1])) {
			int first_elem = A[i];
			int sum = -first_elem;
			// Find the other 2 elements.
			for (int k = i+1, l = A.size()-1; k < l;) {
				if (k == i+1 || (k > i+1 && A[k] != A[k-1])) {
					if (A[k] + A[l] == sum) {
						ret.emplace_back(make_tuple(first_elem, A[k], A[l]));
						cout << first_elem << "," << A[k] << "," << A[l] << endl;
						k++;
					} else if (A[k] + A[l] > sum) {
						l--;
					} else {
						k++;
					}
				} else {
					// Skip duplicates.
					k++;
				}
			}
		}
	}
	
	return ret;
}

int main() {
	vector<int> A{-1, 0, 1, 2, -1, -4};
	auto ret = threesum_zero(A);
	cout << "Triplets that sum to 0: ";
	for (auto t : ret) {
		cout << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ") ";
	}
	cout << endl;
	return 0;
}
