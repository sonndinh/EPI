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

// O(n). Return the (n - k + 1)th smallest element.
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

int main() {
	vector<int> arr{2, 5, 3, 12, 9, 8, 7, 10};
	cout << "Input: ";
	for (auto a : arr) {
		cout << a << " ";
	}
	cout << endl;
	/*
	cout << "First largest: " << k_largest(arr, 1) << endl;
	cout << "Second largest: " << k_largest(arr, 2) << endl;
	cout << "Third largest: " << k_largest(arr, 3) << endl;
	cout << "Fourth largest: " << k_largest(arr, 4) << endl;
	*/
	int size = arr.size();
	cout << "First largest: " << select(arr, 0, size-1, size) << endl;
	cout << "Second largest: " << select(arr, 0, size-1, size-1) << endl;
	cout << "Third largest: " << select(arr, 0, size-1, size-2) << endl;
	cout << "Fourth largest: " << select(arr, 0, size-1, size-3) << endl;
	
	return 0;
}
