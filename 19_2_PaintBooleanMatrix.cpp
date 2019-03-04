#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

void dfs_visit(vector<vector<bool>>& matrix, int x, int y) {
	bool val = matrix[x][y];
	matrix[x][y] = !val; // Flip the current pixel's color.
	const array<array<int, 2>, 4> shift = {{{{-1, 0}}, {{1, 0}}, {{0, -1}}, {{0, 1}}}};
	
	for (const array<int, 2>& s : shift) {
		int p = x + s[0], q = y + s[1];
		if (p >= 0 && p < matrix.size() && q >= 0 && q < matrix[0].size() && matrix[p][q] == val) {
			dfs_visit(matrix, p, q);
		}
	}
}

void bfs_visit(vector<vector<bool>>& matrix, int x, int y) {
	queue<pair<int, int>> q; // Queue of neighnors.
	q.push(make_pair(x, y));
	const array<array<int, 2>, 4> shift = {{{{-1, 0}}, {{1, 0}}, {{0, -1}}, {{0, 1}}}};

	while (!q.empty()) {
		pair<int, int> n = q.front();
		bool val = matrix[n.first][n.second];
		matrix[n.first][n.second] = !val;
		q.pop();
		
		for (const array<int, 2>& s : shift) {
			int r = n.first + s[0], t = n.second + s[1];
			if (r >= 0 && r < matrix.size() && t >= 0 && t < matrix[0].size() && matrix[r][t] == val) {
				q.push(make_pair(r, t));
			}
		}
	}
}

// Flip the color at a given coordinate of the input matrix.
void flip(vector<vector<bool>>& matrix, int x, int y) {
	if (matrix.size() == 0) return;
	//	dfs_visit(matrix, x, y);
	bfs_visit(matrix, x, y);
}

int main() {
	vector<vector<bool>> matrix{{0, 1, 0, 1}, {0, 0, 1, 0}, {1, 0, 1, 0}, {0, 1, 0, 1}};
	cout << "Input:" << endl;
	for (auto& r : matrix) {
		for (bool b : r) {
			cout << b << " ";
		}
		cout << endl;
	}
	flip(matrix, 0, 0);
	cout << "Output:" << endl;
	for (auto& r : matrix) {
		for (bool b : r) {
			cout << b << " ";
		}
		cout << endl;
	}	
	
	return 0;
}
