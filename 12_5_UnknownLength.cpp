#include <iostream>
#include <vector>

using namespace std;

// Search a sorted array with unknown length.
int search(int target, const vector<int>& arr ) {
	int p = 0;
	while (true) {
		int i = (1 << p) - 1;
		try {
			if (arr.at(i) == target) return i;
			if (arr.at(i) > target) break;
		}
		catch(const exception& e) {
			break;
		}
		p++;
	}

	int left = p == 0? 0 : 1 << (p - 1);
	int right = p == 0? 0 : (1 << p) - 2;
	while (left <= right) {
		int mid = left + (right - left)/2;
		try {
			if (arr.at(mid) == target) {
				return mid;
			} else if (arr.at(mid) < target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		} catch(const exception& ex) {
			right = mid - 1;
		}
	}

	return -1;
}

int main() {
	vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	cout << "Index of 11: " << search(11, arr) << endl;
	cout << "Index of 100: " << search(100, arr) << endl;
	cout << "Index of -7: " << search(-7, arr) << endl;

	vector<int> arr2;
	for (int i = 0; i < 200; i++) {
		arr2.push_back(i);
	}
	cout << "Index of 150: " << search(150, arr2) << endl;

	cout << "Index of 10 in an empty array: " << search(10, vector<int>()) << endl;
	return 0;
}
