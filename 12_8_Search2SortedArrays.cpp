#include <iostream>
#include <vector>

using namespace std;

// Search the p-th smallest element from 2 sorted sub-arrays.
int search_helper(const vector<int>& A, int af, int al, const vector<int>& B, int bf, int bl, int p) {
	if (af > al) {
		// Return the k-th smallest element from the B's sub-array.
		return B.at(bf + p - 1);
	}
	if (bf > bl) {
		return A.at(af + p - 1);
	}

	int amid = (af + al)/2;
	int akey = A.at(amid);
	int bleft = bf, bright = bl;
	int bmid = (bleft + bright)/2;
	// Find first element in the B's sub-array that is larger than the middle element of A.
	while (bleft <= bright) {
		bmid = (bleft + bright)/2;
		if (B.at(bmid) > akey && B.at(bmid-1) <= akey) {
			break;
		} else if (B.at(bmid) > akey && B.at(bmid-1) > akey) {
			bright = bmid - 1;
		} else if (B.at(bmid) <= akey) {
			bleft = bmid + 1;
		}
	}
	if (bleft > bright) {
		// All elements in the B's sub-array is smaller than or equal to the key from A.
		return search_helper(A, af, amid, B, bf, bl, p);
	}
	return search_helper(A, amid+1, al, B, bmid, bl, p-(amid-af+1)-(bmid-bf));
}

// Search the k-th smallest element from 2 sorted arrays.
int search(const vector<int>& A, const vector<int>& B, int k) {
	return search_helper(A, 0, k-1, B, 0, k-1, k);
}

int main() {
	vector<int> A{1,2,3,4,5,6,7,8};
	vector<int> B{2,5,5,8,9,10,11,12};
	cout << "3th element is: " << search(A, B, 3) << endl;
	return 0;
}
