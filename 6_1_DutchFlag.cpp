#include <iostream>
#include <vector>

using namespace std;

// Partition a given array.
// [0, i]: smaller than pivot.
// [i+1, k]: equal to pivot.
// [k+1, j-1]: larger than pivot.
// [j, r-1]: unexplored.
void partition(vector<int>& A, int idx) {
	int x = A[idx];
	int p = 0;
	int r = A.size() - 1;
	swap(A[idx], A[r]);
	int i = p - 1;
	int k = p - 1;

	for (int j = p; j < r; j++) {
		if (A[j] < x) {
			if (k > p - 1) {
				swap(A[++i], A[j]);
				swap(A[++k], A[j]);
			} else {
				swap(A[++i], A[j]);
			}
		} else if (A[j] == x) {
			if (k > p - 1) {
				swap(A[++k], A[j]);
			} else {
				k = i + 1;
				swap(A[k], A[j]);
			}
		}
		// Otherwise A[j] > x and we just move to the next element.
	}
	if (k > p - 1)
		swap(A[++k], A[r]);
	else
		swap(A[i+1], A[r]);
}

// Different way to partition.
// [0, i]: smaller than pivot.
// [i+1, j-1]: equal to pivot.
// [j, k-1]: unexplored.
// [k, r]: larger than pivot.
void partition2(vector<int>& A, int idx) {
	int x = A[idx]; // pivot's value
	int i = -1, j = 0, k = A.size();

	while (j < k) {
		if (A[j] < x) {
			swap(A[++i], A[j]);
			j++;
		} else if (A[j] > x) {
			swap(A[--k], A[j]);
		} else {
			j++;
		}
	}
}

int main() {
	vector<int> A{5, 2, 8, 0, 5, 7, 10, 5, 5, 5, 4, 1, 6, 7};
	partition2(A, 0);
	//vector<int> A{6, 3, 2, 3, 5};
	//partition(A, 1);
	cout << "Output: ";
	for (auto x : A) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
