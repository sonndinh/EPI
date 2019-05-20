#include <iostream>
#include <vector>
using namespace std;

struct Interval {
	int left, right;
	Interval(int l, int r) : left(l), right(r) {}
};

// Time complexity and space complexity: O(n).
vector<Interval> join_intervals(vector<Interval>& A, Interval a) {
	vector<Interval> ret;
	if (A.empty()) {
		ret.emplace_back(a);
		return ret;
	}
	if (a.right < A[0].left) {
		A.emplace(A.begin(), a);
		return A;
	}
	if (a.left > A.back().right) {
		A.emplace(A.end(), a);
		return A;
	}

    vector<Interval>::iterator it = A.begin();
	// Find the first interval that may overlap with the new interval.
	while (it < A.end() && it->right < a.left) {
		ret.emplace_back(*it);
		++it;
	}

	if (it->left > a.right) {
		// No overlap.
		ret.emplace_back(a);
	} else {
		int l = min(a.left, it->left);
		int r = max(a.right, it->right);
		while (++it < A.end() && (it->left <= r)) {
			r = max(it->right, r);
		}
		ret.emplace_back(l, r);
	}
	// Insert the remaining intervals from the array.
	while (it < A.end()) {
		ret.emplace_back(*it);
		++it;
	}
	
	return ret;
}

int main() {
	vector<Interval> A{{-4,-1}, {0,2}, {3,6}, {7,9}, {11,12}, {14,17}};
	Interval a = {1, 8};
	auto ret = join_intervals(A, a);
	for (Interval i : ret) {
		cout << "[" << i.left << "," << i.right << "] ";
	}
	cout << endl;
	
	return 0;
}
