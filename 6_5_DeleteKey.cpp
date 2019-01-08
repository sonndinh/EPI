#include <iostream>
#include <vector>

using namespace std;

// Delete all occurences of the given key in an array.
// Return the number of elements left.
int del_key(int key, vector<int>& vect) {
	int count = 0; // Number of occurences of the key
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i] == key) {
			count++;
		} else if (count > 0) {
			vect[i-count] = vect[i];
		}
	}

	return (vect.size() - count);
}

int main(int argc, char *argv[]) {
	//	vector<int> arr{1, 2, 3, 4, 5, 2, 6, 7, 8, 9};
	vector<int> arr{2, 2, 2, 2};
	int elems = del_key(2, arr);
	cout << "Delete 2: " << elems << " elements left." << endl;
	cout << "Elements: ";
	for (int i = 0; i < elems; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
