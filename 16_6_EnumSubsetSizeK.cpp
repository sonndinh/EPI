#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>>& ret, vector<int> tmp, int start, int n, int k) {
	if (k == 0) {
		ret.push_back(tmp);
		return;
	}

	for (int i = start; i <= n; i++) {
		tmp.push_back(i);
		helper(ret, tmp, i+1, n, k-1);
		tmp.pop_back();
	}
}

// Find all subsets of size k for set {1, 2, ..., n}
vector<vector<int>> find_subset_size_k(int n, int k) {
	vector<vector<int>> ret;
	helper(ret, vector<int>(), 1, n, k);
	return ret;
}

int main() {
	int n = 5, k = 3;
	auto ret = find_subset_size_k(n, k);
	
	for (int i = 0; i < ret.size(); i++) {
		cout << "<";
		for (int j = 0; j < k; j++) {
			if (j < k-1)
				cout << ret[i][j] << ",";
			else
				cout << ret[i][j];
		}
		if (i < ret.size()-1)
			cout << ">, ";
		else
			cout << ">";
	}
	cout << endl;
	return 0;
}
