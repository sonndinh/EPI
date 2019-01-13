#include <iostream>
#include <vector>

using namespace std;

void increase(vector<int>& A) {
	int carry = 1;
	for (int i = A.size()-1; i >= 0; i--) {
		if (A[i] < 9) {
			A[i]++;
			carry = 0;
			break;
		} else if (A[i] == 9) {
			A[i] = 0;
		}
	}
	
	if (carry == 1) {
		// Insert 1 as the first element of the array
		A.insert(A.begin(), 1);
	}
}

int main(int argc, char *argv[]) {
	vector<int> A{9, 9, 9, 9};
	cout << "A = {9, 9, 9, 9} ==> A+1 = {";
	increase(A);

	for (int i = 0; i < A.size(); i++) {
		if (i == A.size() - 1) {
			cout << A[i] << "}" << endl;
		} else {
			cout << A[i] << ", ";
		}
	}

	return 0;
}
