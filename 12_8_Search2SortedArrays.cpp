#include <iostream>
#include <vector>

using namespace std;

// Search the p-th smallest element from 2 sorted sub-arrays.
int search_helper(const vector<int>& A, int af, int al, const vector<int>& B, int bf, int bl, int p) {
	if (af > al) {
		return B.at(bf + p - 1);
	}
	if (bf > bl) {
		return A.at(af + p - 1);
	}
	if (p == 1) return (A.at(af) > B.at(bf)? B.at(bf) : A.at(af));

	int amid = (af + al)/2;
	int akey = A.at(amid);
	int bleft = bf, bright = bl;
	int bmid;
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
		bmid = bl + 1;
	}

	// Number of elements from the left partitions of the 2 arrays.
	int num_left_elems = amid - af + 1 + bmid - bf;
	if (num_left_elems == p) {
		return (A.at(amid) > B.at(bmid - 1)? A.at(amid) : B.at(bmid - 1));
	} else if (num_left_elems < p) {
		return search_helper(A, amid+1, al, B, bmid, bl, p - num_left_elems);
	} else {
		return search_helper(A, af, amid, B, bf, bmid - 1, p);
	}
}

// Search the k-th smallest element from 2 sorted arrays.
int search(const vector<int>& A, const vector<int>& B, int k) {
	if (A.size() + B.size() < k) return -1; // No such element

	return search_helper(A, 0, (A.size() >= k ? k-1 : A.size()-1), 
						 B, 0, (B.size() >= k ? k-1 : B.size()-1), k);
}

int main() {
	vector<int> A;//{1,2,3,4,5,6,7,8};
	vector<int> B{2,5,5,8,9,10,11,12};
	cout << "First array: ";
	for (int a : A) cout << a << " ";
	cout << endl;
	cout << "Second array: ";
	for (int b : B) cout << b << " ";
	cout << endl;

	cout << "3rd element is: " << search(A, B, 3) << endl;
	cout << "6th element is: " << search(A, B, 6) << endl;
	cout << "9th element is: " << search(A, B, 9) << endl;
	cout << "1st element is: " << search(A, B, 1) << endl;
	return 0;
}
