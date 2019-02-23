#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

// Return the kth largest element in an array. O(nlgn).
int k_largest(const vector<int>& A, int k) {
	priority_queue<int> queue(A.begin(), A.end());
	for (int i = 1; i < k; i++) {
		queue.pop();
	}

	return queue.top();
}

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(vector<int>& A, int p, int r) {
	// Pick a random pivot.
	srand(time(NULL));
	int q = (rand() % (r-p+1)) + p;
	swap(A[q], A[r]);

	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j] <= A[r]) {
			++i;
			swap(A[i], A[j]);
		}
	}
	swap(A[r], A[i+1]);
	return i+1;
}

// O(n). Return the ith smallest element. Recursive implementation.
int select(vector<int>& A, int p, int r, int i) {
	if (p == r) return A[p];
	int q = partition(A, p, r);
	int t = q - p + 1;
	if (i == t) {
		return A[q];
	} else if (i < t) {
		return select(A, p, q-1, i);
	} else {
		return select(A, q+1, r, i - t);
	}
}

// Return the kth largest element. Iterative implementation.
int select2(vector<int>& A, int k) {
	int p = 0, r = A.size() - 1;
	while (p <= r) {
		int q = partition(A, p, r);
		if (q == A.size() - k) return A[q];
		else if (q < A.size() - k) {
			p = q + 1;
		} else {
			r = q - 1;
		}
	}
	// Should never reach here.
	return numeric_limits<int>::min();
}

int main() {
	vector<int> arr{2, 5, 3, 12, 9, 8, 7, 10};
	cout << "Input: ";
	for (auto a : arr) {
		cout << a << " ";
	}
	cout << endl;
	/*
	int size = arr.size();
	cout << "First largest: " << select(arr, 0, size-1, size) << endl;
	cout << "Second largest: " << select(arr, 0, size-1, size-1) << endl;
	cout << "Third largest: " << select(arr, 0, size-1, size-2) << endl;
	cout << "Fourth largest: " << select(arr, 0, size-1, size-3) << endl;
	*/
	cout << "First largest: " << select2(arr, 1) << endl;
	cout << "Second largest: " << select2(arr, 2) << endl;
	cout << "Third largest: " << select2(arr, 3) << endl;
	cout << "Fourth largest: " << select2(arr, 4) << endl;
	cout << "Fifth largest: " << select2(arr, 5) << endl;
	return 0;
}
