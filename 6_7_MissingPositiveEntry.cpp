#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned missing_positive_entry(vector<int> A) {
	sort(A.begin(), A.end());
	int ret = 1;
	for (unsigned i = 0; i < A.size(); i++) {
		if (A[i] == ret) {
			ret++;
		} else if (A[i] > ret) {
			break; // found it, need no further searching
		}
	}

	return ret;
}

int main(int argc, char *argv[]) {
	vector<int> A{3, 5, 4, -1, 5, 1, -1};
	cout << "Input [3, 5, 4, -1, 5, 1, -1]. Smallest positive missing number: " 
		 << missing_positive_entry(A) << endl;
	return 0;
}
