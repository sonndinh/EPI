#include <iostream>
#include <vector>
#include <array>

using namespace std;

// Visit all white cells that are reachable from the boundary and mark them.
void dfs_visit(vector<vector<char>>& matrix, int x, int y, vector<vector<bool>>& visited) {
	visited[x][y] = true;
	const array<array<int, 2>, 4> shift = {{{{-1, 0}}, {{1, 0}}, {{0, -1}}, {{0, 1}}}};

	for (auto& s : shift) {
		int p = x + s[0], q = y + s[1];
		if (p >= 0 && p < matrix.size() && q >= 0 && q < matrix[0].size()
			&& matrix[p][q] == 'W' && visited[p][q] == false) {
			dfs_visit(matrix, p, q, visited);
		}
	}
}

void region(vector<vector<char>>& matrix) {
	int n = matrix.size(), m = matrix[0].size();
	if (n == 0) return;
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	// Find all cells that are white and reachable from the boundary.
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == n-1) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == 'W') {
					dfs_visit(matrix, i, j, visited);
				}
			}
		} else {
			if (matrix[i][0] == 'W')
				dfs_visit(matrix, i, 0, visited);
			if (matrix[i][m-1] == 'W')
				dfs_visit(matrix, i, m-1, visited);
		}
	}

	// Flip all white cells that are not visited.
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			if (matrix[i][j] == 'W' && visited[i][j] == false)
				matrix[i][j] = 'B';
		}
	}
}

void print(const vector<vector<char>>& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}	
}

int main() {
	vector<vector<char>> matrix{{'B', 'B', 'B', 'B'}, {'W', 'B', 'W', 'B'}, {'B', 'W', 'W', 'B'}, {'B', 'B', 'B', 'B'}};
	cout << "Input:" << endl;
	print(matrix);
	region(matrix);
	cout << "Output:" << endl;
	print(matrix);
	return 0;
}
