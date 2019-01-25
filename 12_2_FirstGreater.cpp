#include <iostream>
#include <vector>

using namespace std;

int search_helper(vector<int>& arr, int p, int q, int target) {
	if (p > q) return -1;

	int mid = (p + q)/2;
	if (arr[mid] > arr[mid-1] && arr[mid-1] == target) return mid;

	if (arr[mid] > target) {
		return search_helper(arr, p, mid-1, target);
	} else {
		return search_helper(arr, mid+1, q, target);
	}
}

// Return index of the first element that is greater than target.
int search(vector<int>& arr, int target) {
	return search_helper(arr, 0, arr.size()-1, target);
}

int main() {
	vector<int> arr{1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 5, 5, 6, 108, 108, 108, 108};
	cout << "Array: ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "First greater of 1: " << search(arr, 1) << endl;
	cout << "First greater of 5: " << search(arr, 5) << endl;
	cout << "First greater of 108: " << search(arr, 108) << endl;
	return 0;

}
