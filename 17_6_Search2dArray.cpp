#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <functional>
#include <unordered_set>

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

// Compute hash for tuple
struct Hash {
	size_t operator()(const tuple<int, int, int>& t) {
		return hash<int>()(get<0>(t)) | hash<int>()(get<1>(t)) | hash<int>()(get<2>(t));
	}
};

bool traverse_helper(const vector<vector<int> >& A, int i, int j, const vector<int>& S, int k, 
					 unordered_set<tuple<int, int, int>, Hash>& cache) {
	if (cache.find(tuple<int, int, int>(i, j, k)) != cache.cend()) return false;
	
	int n = A.size();
	int m = A[0].size();
	vector<pair<int, int> > neighbors = get_neighbors(n, m, i, j);

	for (pair<int, int> p : neighbors) {
		if (A[p.first][p.second] == S[k]) {
			if (S.size()-1 == k) return true;
			if (traverse_helper(A, p.first, p.second, S, k+1, cache) == true) return true;
		}
	}

	cache.emplace(i, j, k);
	return false;
}

bool traverse(const vector<vector<int> >& A, const vector<int>& S) {
	int n = A.size(); // number of rows
	if (n == 0) return false;
	int m = A[0].size(); // number of columns
	if (m == 0) return false;

	// Store tuples corresponding to failed combinations.
	// Tuple requires a specific hash function.
	unordered_set<tuple<int, int, int>, Hash> cache;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == S[0]) {
				if (traverse_helper(A, i, j, S, 1, cache) == true) return true;
			}
		}
	}

	return false;
}

void print_matrix(const vector<vector<int> >& matrix) {
	cout << "MATRIX: " << endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	vector<vector<int> > A{{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
	vector<int> S1{1, 3, 4, 6};
	vector<int> S2{1, 2, 3, 4};

	print_matrix(A);
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

	vector<vector<int> > B{{7, 2, 5, 0, 2, 6}, {2, 1, 2, 9, 1, 2}, {8, 2, 4, 9, 2, 3}};
	vector<int> S3{1, 2, 1, 2, 1, 2, 3};
	print_matrix(B);
	cout << "Sequence <";
	for (int n : S3) {
		cout << n << " ";
	}
	cout << "> " << (traverse(B, S3) == true ? "Found!" : "Not Found!") << endl;
	

	return 0;
}
