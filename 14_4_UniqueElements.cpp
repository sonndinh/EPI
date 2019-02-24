#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Remove duplicates from an array.
void remove_dup(vector<int>& A) {
	if (A.size() <= 1) return;
	sort(A.begin(), A.end());
	int cur = A[0];
	int write_idx = 1;
	for (int i = 1; i < A.size(); i++) {
		if (A[i] > cur) {
			A[write_idx] = A[i];
			cur = A[i];
			write_idx++;
		}
	}
	A.resize(write_idx);
}

int main() {
	vector<int> A{10, 4, 2, 8, 5, 6, 2, 8, 8, 6, 5, 5, 7};
	remove_dup(A);
	cout << "Output:";
	for (int i : A) {
		cout << " " << i;
	}
	cout << endl;
	
	return 0;
}
