#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Compute the maximum value of fish going from top-left to bottom-right.
int max_value(int n, int m, const vector<vector<int> >& A) {
	vector<vector<int> > val(n, vector<int>(m, 0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			val[i][j] = A[i][j] + max(i<1 ? 0:val[i-1][j], j<1 ? 0:val[i][j-1]);
		}
	}

	return val[n-1][m-1];
}

int main(int argc, char *argv[]) {
	vector<vector<int> > A{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	cout << "Max fish value:" << max_value(3, 3, A) << endl;
	return 0;
}
