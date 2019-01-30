#include <iostream>
#include <vector>

using namespace std;

// Search a sorted array with unknown length.
int search(int target, const vector<int>& arr ) {
	int left = 0;
	int right = 1000; // some random upper bound
	int mid = (left + right)/2;
	while (left <= right) {
		try {
			// simulate that the length of the array is not known.
			int size = arr.size();
			if (mid >= size) throw mid;

			if (arr[mid] == target) {
				return mid;
			} else if (arr[mid] < target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
			mid = (left + right)/2;
		} catch(int x) {
			right = x - 1;
			mid = (left + right)/2;
		}
	}
	return -1;
}

int main() {
	vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	cout << "Index of 11: " << search(11, arr) << endl;
	cout << "Index of 100: " << search(100, arr) << endl;
	cout << "Index of -7: " << search(-7, arr) << endl;
	return 0;
}
