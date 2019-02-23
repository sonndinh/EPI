#include <iostream>
#include <vector>

using namespace std;

// Input: 2 sorted arrays.
// Output: a combined sorted array written to the first array
// assuming it has enough empty at the end.
void merge_sort(vector<int>& A, const vector<int>& B) {
	int len_a = A.size(), len_b = B.size();
	int total_size = len_a + len_b;
	A.resize(total_size);
	int i = len_a - 1, j = len_b - 1, write_idx = total_size - 1;

	// Traverse from the end up.
	for (; i >= 0 && j >= 0; write_idx--) {
		if (A[i] < B[j]) {
			A[write_idx] = B[j--];
		} else {
			A[write_idx] = A[i--];
		}
	}

	// Write the remaining elements.
	if (i < 0 && j >= 0) {
		for (; j >= 0; write_idx--) {
			A[write_idx] = B[j--];
		}
	} else if (i >= 0 && j < 0) {
		for (; i >= 0; write_idx--) {
			A[write_idx] = A[i--];
		}
	}
}

int main() {
	vector<int> A{0, 1, 3, 4, 7, 9, 10};
	vector<int> B{0, 1, 2, 5, 6, 8, 11};
	merge_sort(A, B);
	cout << "Output:";
	for (int x : A) {
		cout << " " << x;
	}
	cout << endl;
	return 0;
}
