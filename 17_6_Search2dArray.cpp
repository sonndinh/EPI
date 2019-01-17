#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int> > get_neighbors(int n, int m, int i, int j) {
	vector<pair<int, int> > ret;
	if (i == 0) {
		ret.push_back(pair<int, int>(i+1, j));
		if (j == 0) {
			ret.push_back(pair<int, int>(i, j+1));
		} else if (j == m-1) {
			ret.push_back(pair<int, int>(i, j-1));
		} else {
			ret.push_back(pair<int, int>(i, j-1));
			ret.push_back(pair<int, int>(i, j+1));
		}
	} else if (i == n-1) {
		ret.push_back(pair<int, int>(i-1, j));
		if (j == 0) {
			ret.push_back(pair<int, int>(i, j+1));
		} else if (j == m-1) {
			ret.push_back(pair<int, int>(i, j-1));
		} else {
			ret.push_back(pair<int, int>(i, j-1));
			ret.push_back(pair<int, int>(i, j+1));
		}
	} else {
		ret.push_back(pair<int, int>(i-1, j));
		ret.push_back(pair<int, int>(i+1, j));
		if (j == 0) {
			ret.push_back(pair<int, int>(i, j+1));
		} else if (j == m-1) {
			ret.push_back(pair<int, int>(i, j-1));
		} else {
			ret.push_back(pair<int, int>(i, j-1));
			ret.push_back(pair<int, int>(i, j+1));
		}
	}

	return ret;
}

bool traverse_helper(const vector<vector<int> >& A, int i, int j, const vector<int>& S, int k) {	
	int n = A.size();
	int m = A[0].size();
	vector<pair<int, int> > neighbors = get_neighbors(n, m, i, j);
	for (pair<int, int> p : neighbors) {
		if (A[p.first][p.second] == S[k]) {
			if (S.size()-1 == k) return true;
			if (traverse_helper(A, p.first, p.second, S, k+1) == true) return true;
		}
	}

	return false;
}

bool traverse(const vector<vector<int> >& A, const vector<int>& S) {
	int n = A.size(); // number of rows
	int m = A[0].size(); // number of columns

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == S[0]) {
				if (traverse_helper(A, i, j, S, 1) == true) return true;
			}
		}
	}

	return false;
}

int main(int argc, char *argv[]) {
	vector<vector<int> > A{{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
	vector<int> S1{1, 3, 4, 6};
	vector<int> S2{1, 2, 3, 4};

	cout << "Sequence <";
	for (int n : S1) {
		cout << n << " ";
	}
	cout << "> " << (traverse(A, S1) == true ? "Found!" : "Not Found!") << endl;

	cout << "Sequence <";
	for (int n : S2) {
		cout << n << " ";
	}
	cout << "> " << (traverse(A, S2) == true ? "Found!" : "Not Found!") << endl;

	return 0;
}
