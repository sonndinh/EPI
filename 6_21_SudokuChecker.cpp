#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

// Check if a 9x9 sudoku board is valid.
bool checker(const vector<vector<int>>& board) {
	int n = board.size();
	// Check rows.
	for (int i = 0; i < n; i++) {
		unordered_set<int> curr;
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0 && curr.find(board[i][j]) != curr.end())
				return false;
			curr.insert(board[i][j]);
		}
	}

	// Check columns.
	for (int j = 0; j < n; j++) {
		unordered_set<int> curr;
		for (int i = 0; i < n; i++) {
			if (board[i][j] != 0 && curr.find(board[i][j]) != curr.end())
				return false;
			curr.insert(board[i][j]);
		}
	}

	// Check mini-grids.
	int m = sqrt(n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			unordered_set<int> curr;
			int rlo = i*m, rhi = i*m + m - 1;
			int clo = j*m, chi = j*m + m - 1;
			for (int p = rlo; p <= rhi; p++) {
				for (int q  = clo; q <= chi; q++) {
					if (board[p][q] != 0 && curr.find(board[p][q]) != curr.end())
						return false;
					curr.insert(board[p][q]);
				}
			}
		}
	}
	return true;
}

int __main__() {
	vector<vector<int>> board{{5,3,0,0,7,0,0,0,0}, {6,0,0,1,9,5,0,0,0}, {0,9,8,0,0,0,0,6,0},
							  {8,0,0,0,6,0,0,0,3}, {4,0,0,8,0,3,0,0,1}, {7,0,0,0,2,0,0,0,2},
							  {0,6,0,0,0,0,2,8,0}, {0,0,0,4,1,9,0,0,5}, {0,0,0,0,8,0,0,7,9}};
	cout << "Partial solution is " << (checker(board)? "Valid" : "Invalid") << endl;
	return 0;
}
