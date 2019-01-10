#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> lis(vector<int> A) {
	int low_final = 0;
	int high_final = 0;
	int low = 0;
	int high = 0;

	for (int i = 1; i < A.size(); i++) {
		if (A[i] <= A[high]) {
			if ((high - low) > (high_final - low_final)) {
				low_final = low;
				high_final = high;
			}
			low = i;
			high = i;
		} else {
			high++;
		}
	}

	if ((high - low) > (high_final - low_final)) {
		low_final = low;
		high_final = high;
	}

	return make_pair(low_final, high_final);
}

int main(int argc, char *argv[]) {
	vector<int> A{2, 11, 3, 5, 13, 7, 19, 17, 23, 24, 25};
	cout << "Input: [2, 11, 3, 5, 13, 7, 19, 17, 23, 24, 25]" << endl;
	pair<int, int> p = lis(A);
	cout << "Output: [" << p.first << ", " << p.second << "]" << endl;
	return 0;
}
