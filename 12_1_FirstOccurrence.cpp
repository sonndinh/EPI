#include <iostream>
#include <vector>

using namespace std;

// A small modification of binary search.
int search_helper(vector<int>& arr, int p, int q, int target) {
	if (p > q) return -1;
	int mid = (p + q)/2;

	if (arr[mid] == target) {
		if (mid == 0 || arr[mid] > arr[mid-1]) return mid;
		return search_helper(arr, p, mid-1, target);
	} else if (arr[mid] > target) {
		return search_helper(arr, p, mid-1, target);
	} else {
		return search_helper(arr, mid+1, q, target);
	}
}

// Find the first occurrence of a number in a sorted array.
int search(vector<int>& arr, int target) {
	return search_helper(arr, 0, arr.size()-1, target);
}

int main() {
	vector<int> arr{1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 5, 5, 6, 108, 108, 108, 108};
	cout << "First occurence of 5: " << search(arr, 5) << endl;
	cout << "First occurence of 1: " << search(arr, 1) << endl;
	cout << "First occurence of 108: " << search(arr, 108) << endl;
	return 0;
}
