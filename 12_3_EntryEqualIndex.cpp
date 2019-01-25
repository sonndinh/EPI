#include <iostream>
#include <vector>

using namespace std;

int search_helper(vector<int>& arr, int p, int q) {
	if (p > q) return -1;
	int mid = p + (q - p)/2;

	if (arr[mid] == mid) return mid;

	if (arr[mid] > mid)
		// All elements from mid going forward must be larger than its index.
		return search_helper(arr, p, mid-1);
	else
		// All elements from mid going backward must be smaller than its index.
		return search_helper(arr, mid+1, q);
}

// Find an entry which is equal to its index in a sorted array of distinct elements.
int search(vector<int>& arr) {
	return search_helper(arr, 0, arr.size()-1);
}

int main() {
	vector<int> arr{-5, -3, -1, 0, 1, 5, 6, 8, 10, 11, 20, 21, 23, 30, 41, 45, 50, 108};
	cout << "Array: ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Index " << search(arr) << endl;

	vector<int> arr2{-5, -3, -1, 0, 1, 6, 7, 8, 10, 11, 20, 21, 23, 30, 41, 45, 50, 108};
	cout << "Array: ";
	for (int i = 0; i < arr2.size(); i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;
	cout << "Index " << search(arr2) << endl;

	return 0;
}
