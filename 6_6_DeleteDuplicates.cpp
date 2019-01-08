#include <iostream>
#include <vector>

using namespace std;

// Delete duplicates from a sorted array.
// Return the number of elements left.
int del_dup(vector<int>& A) {
	int count = 0; // Total number of duplicates
	for (int i = 1; i < A.size(); i++) {
		if (A[i] == A[i-1]) {
			count++;
		} else {
			A[i-count] = A[i];
		}
	}

	return (A.size()-count);
}

int main(int argc, char *argv[]) {
	vector<int> A{1, 2, 3, 3, 4, 5, 6, 6, 6, 7, 8, 9};
	int elems = del_dup(A);
	cout << "Number of elements left: " << elems << ". Array: ";
	for (int i = 0; i < elems; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}
