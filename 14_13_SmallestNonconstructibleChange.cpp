#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Return smallest value that is not equal to a sum of subset of A.
unsigned smallest_change(vector<unsigned>& A) {
	unsigned sum = 0;
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); ++i) {
		if (sum + 1 < A[i]) {
			return (sum + 1);
		} else {
			sum += A[i];
		}
	}

	return ++sum;
}

int main() {
	//	vector<unsigned> A{1,1,3,4};
	//vector<unsigned> A{1, 2, 5, 10, 20, 40};
	vector<unsigned> A{1,2,3,4,5,6};
	cout << "Smallest non-constructible change is: " << smallest_change(A) << endl;
	return 0;
}
