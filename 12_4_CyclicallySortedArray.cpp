#include <iostream>
#include <vector>

using namespace std;

// O(logn) function.
int search_helper(vector<int>& arr, int p, int q) {
	if (p == q) return p;
	int mid = p + (q - p)/2;
	
	if (arr[mid] < arr[p]) {
		if (arr[mid] < arr[mid-1]) return mid;
		return search_helper(arr, p, mid-1);
	} else {
		if (mid == p && arr[mid] < arr[mid+1]) return mid;
		if (arr[mid] > arr[q])
			return search_helper(arr, mid+1, q);
		else 
			return search_helper(arr, p, mid-1);
	}
}

// Cleaner search function but could be O(n).
int search_helper2(vector<int>& arr, int p, int q) {
	if (p == q) return p;
	int mid = p + (q - p)/2;
	
	if (arr[mid] < arr[p]) {
		return search_helper(arr, p, mid);
	} else if (arr[mid] > arr[p]) {
		int i = search_helper(arr, mid+1, q);
		int j = search_helper(arr, p, mid-1);
		return (arr[i] < arr[j]? i : j);
	} else {
		return (arr[p] < arr[q]? p : q);
	}
}

// Return index of the smallest element in a cyclically sorted array.
// All elements are distinct.
int search(vector<int>& arr) {
	return search_helper(arr, 0, arr.size()-1);
}

int main() {
	vector<int> arr{30, 40, 50, 60, 70, 80, 1, 2, 3, 4, 5, 6, 7, 8};
	cout << "Array: ";
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << endl;
	cout << "Smallest element is at index " << search(arr) << endl;

	vector<int> arr2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 30};
	cout << "Array: ";
	for (auto i : arr2) {
		cout << i << " ";
	}
	cout << endl;
	cout << "Smallest element is at index " << search(arr2) << endl;

	return 0;
}
