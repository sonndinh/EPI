#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Return the kth largest element in an array.
int k_largest(const vector<int>& A, int k) {
	priority_queue<int> queue(A.begin(), A.end());
	for (int i = 1; i < k; i++) {
		queue.pop();
	}

	return queue.top();
}

int main() {
	vector<int> arr{2, 5, 3, 12, 9, 8, 7, 10};
	cout << "Input: ";
	for (auto a : arr) {
		cout << a << " ";
	}
	cout << endl;
	cout << "First largest: " << k_largest(arr, 1) << endl;
	cout << "Second largest: " << k_largest(arr, 2) << endl;
	cout << "Third largest: " << k_largest(arr, 3) << endl;
	cout << "Fourth largest: " << k_largest(arr, 4) << endl;
	return 0;
}
