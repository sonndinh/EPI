#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Using DP. Time O(n^2), space O(n^2).
vector<int> lns(const vector<int>& A) {
	if (A.size() == 0) return {};
	
	// Map from each index to a longest nondecreasing subsequence ending at that index.
	unordered_map<int, vector<int>> idx_to_subseq;
	int largest_idx = -1; // Index corresponds to a longest nondecreasing subsequence so far.
	for (int i = 0; i < A.size(); ++i) {
		if (i == 0) {
			idx_to_subseq[i] = {i};
			largest_idx = i;
		} else {
			int max = 1, max_idx = -1;
			for (int j = i-1; j >= 0; --j) {
				if (A[i] >= A[j] && idx_to_subseq[j].size() + 1 > max) {
					max = idx_to_subseq[j].size() + 1;
					max_idx = j;
				}
			}
			if (max_idx == -1) {
				idx_to_subseq[i] = {i};
			} else {
				vector<int> tmp = idx_to_subseq[max_idx];
				tmp.push_back(i);
				idx_to_subseq[i] = tmp;
			}
			
			// Update the index of last entry of the current longest nondecreasing subsequence.
			if (idx_to_subseq[i].size() > idx_to_subseq[largest_idx].size()) {
				largest_idx = i;
			}
		}
	}

	return idx_to_subseq[largest_idx];
}

int main() {
	vector<int> A{0, 8, 4, 12, 2, 10, 6, 14, 1, 9};
	//	vector<int> A{0, 8, 2, 12, 4, 6, 10, 14, 1, 9};
	//	vector<int> A{0, 8, 2, 12, 10, 4, 6, 1, 14, 9};
	vector<int> ret = lns(A);
	cout << "Longest nondecreasing subsequence: ";
	for (int a : ret) {
		cout << a << " ";
	}
	cout << endl;
	return 0;
}
