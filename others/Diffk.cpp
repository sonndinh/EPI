#include <vector>
#include <iostream>
using namespace std;

// Return indices if there exists 2 elements with different indices
// such that their difference equals to a given number.
// Input array is sorted.
pair<int, int> diffk(const vector<int>& A, int k) {
	// Start both indices from the beginning.
	for (int i = 0, j = 1; j < A.size();) {
		if (k >= 0) {
			if (A[j] - A[i] == k) {
				return {j, i};
			} else if (A[j] - A[i] > k) {
				i++;
			} else {
				j++;
			}
		} else {
			if (A[i] - A[j] == k) {
				return {i, j};
			} else if (A[i] - A[j] > k) {
				j++;
			} else {
				i++;
			}
		}
	}
	return {-1, -1};
}

int main() {
	vector<int> A{1, 3, 5};
	int k = -4;
	pair<int, int> ret = diffk(A, k);
	if (ret.first == -1)
		cout << "Not Found!" << endl;
	else
		cout << "Found elements at indices: " << ret.first << ", " << ret.second << endl;
	return 0;
}
