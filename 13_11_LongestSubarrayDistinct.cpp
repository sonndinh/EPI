#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Return the longest subarray with distinct entries. 
pair<int, int> subarray(const vector<char>& A) {
	if (A.size() == 0) return {0, 0};

	// Maintain a list of distinct entries in the current subarray.
	unordered_map<char, int> chr_to_idx;
	int max_start = 0, max_len = 0;
	int curr_start = 0;
	for (int i = 0; i < A.size(); i++) {
		if (chr_to_idx.find(A[i]) != chr_to_idx.cend()) {
			if (chr_to_idx.size() > max_len) {
				max_start = curr_start;
				max_len = chr_to_idx.size();
			}
			for (int j = curr_start; j < chr_to_idx[A[i]]; j++) {
				// Remove the entries belonging to the previous subarray.
				chr_to_idx.erase(A[j]);
			}
			curr_start = chr_to_idx[A[i]] + 1;
			chr_to_idx[A[i]] = i;
		} else if (i == A.size() - 1) {
			if (chr_to_idx.size() > max_len) {
				max_start = curr_start;
				max_len = chr_to_idx.size();
			}
		} else {
			chr_to_idx[A[i]] = i;
		}
	}

	return {max_start, max_len};
}

int main() {
	vector<char> A{'f', 's', 'f', 'e', 't', 'w', 'e', 'n', 'w', 'e'};
	pair<int, int> ret = subarray(A);
	cout << "Longest subarray with distinct entries: ";
	for (int i = ret.first; i < ret.first + ret.second; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
