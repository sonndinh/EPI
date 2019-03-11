#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> helper(const vector<int>& A, int k) {
	vector<int> ret;
	int curr = A[k];
	for (int i = k; i >= 0; i--) {
		if (A[i] <= curr) {
			ret.push_back(i);
			curr = A[i];
		}
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

// Return a longest nondecreasing subsequence.
vector<int> lns(const vector<int>& A) {
	vector<int> subseq;
	for (int i = 0; i < A.size(); i++) {
		if (subseq.size() == 0) {
			subseq.push_back(i);
		} else {
			if (A[subseq.back()] <= A[i]) {
				subseq.push_back(i);
			} else {
				// Compute a longest subsequence which contains A[i].
				vector<int> tmp = helper(A, i);
				if (tmp.size() > subseq.size())
					subseq = tmp;
			}
		}
	}
	return subseq;
}

int main() {
	//	vector<int> A{0, 8, 4, 12, 2, 10, 6, 14, 1, 9};
	//	vector<int> A{0, 8, 2, 12, 4, 6, 10, 14, 1, 9};
	vector<int> A{0, 8, 2, 12, 10, 4, 6, 1, 14, 9};
	vector<int> ret = lns(A);
	cout << "Longest nondecreasing subsequence: ";
	for (int a : ret) {
		cout << a << " ";
	}
	cout << endl;
	return 0;
}
