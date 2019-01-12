#include <iostream>
#include <vector>

using namespace std;

int max_diff(vector<int> A) {
	if (A.size() <= 1) return 0;

	int min = A[0];
	int diff = A[1] - min;
	for (int i = 2; i < A.size(); i++) {
		if (A[i-1] < min) {
			min = A[i-1];
		}

		if (diff < (A[i] - min)) {
			diff = A[i] - min;
		}
	}

	return diff;
}

int main(int argc, char *argv[]) {
	vector<int> A{5, 4, 8, 2, 1, 3, 10, 0};
	cout << "{5, 4, 8, 2, 1, 3, 10, 0} ==> Diff: " << max_diff(A) << endl;
	return 0;
}
