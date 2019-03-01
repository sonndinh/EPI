#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#if defined PERMUTATION
// Use solution of problem 16.4 for computing all permutations.
void permu(vector<vector<int>>& permutations, vector<int> curr, vector<int> remain);
// Use solution of problem 6.21 for a Sukodu checker.
bool checker(const vector<vector<int>>& board);

// Naive implementation: try all permutations on each row. 
bool solve(vector<vector<int>>& board, int row) {
	if (row == board.size()) return true;

	// Find all numbers needed to fill for this row.
	vector<int> remain{1,2,3,4,5,6,7,8,9};
	for (const int& i : board[row]) {
		if (i != 0) {
			vector<int>::iterator it = find(remain.begin(), remain.end(), i);
			remain.erase(it);
		}
	}

	vector<vector<int>> permutations;
	vector<int> curr;
	permu(permutations, curr, remain);
	vector<int> stored_row = board[row];
	for (vector<int>& p : permutations) {
		vector<int>::iterator it = p.begin();
		for (int i = 0; i < board.size(); i++) {
			if (board[row][i] == 0) {
				board[row][i] = *it;
				it++;
			}
		}

		if (checker(board) && solve(board, row+1)) 
			return true;
		board[row] = stored_row;
	}
	return false;
}

#elif defined SEARCH
// Check if the current value at a given cell conflicts with any number 
// from the same column and the same mini-grid.
bool check(const vector<vector<int>>& board, int row, int col) {
	for (int i = row-1; i >= 0; i--) {
		if (board[row][col] == board[i][col])
			return false;
	}

	int m = sqrt(board.size());
	int rlo = (row/m)*m, rhi = (row/m)*m + m - 1;
	int clo = (col/m)*m, chi = (col/m)*m + m - 1;
	for (int i = rlo; i <= rhi; i++) {
		for (int j = clo; j <= chi; j++) {
			if (!(i == row && j == col) && (board[row][col] == board[i][j]))
				return false;
		}
	}
	
	return true;
}

// Fill numbers one cell at a time and test if it satisfies the constraints.
// This takes roughly 1/3 of the time of the naive implementation.
// It also has less code.
bool solve2(vector<vector<int>>& board, int row, int col, vector<int> remain) {
	if (row == board.size()) return true;
	
	if (col == 0) {
		// If this is the first cell of the row, find all numbers to be filled.
		remain = {1,2,3,4,5,6,7,8,9};
		for (const int& i : board[row]) {
			if (i != 0) {
				vector<int>::iterator it = find(remain.begin(), remain.end(), i);
				remain.erase(it);
			}
		}
	}

	if (board[row][col] != 0) {
		if (col < board.size() - 1)
			return solve2(board, row, col + 1, remain);
		else
			return solve2(board, row+1, 0, remain);
	}

	for (int i : remain) {
		vector<int> tmp = remain;
		board[row][col] = i;
		if (check(board, row, col)) {
			vector<int>::iterator it = find(tmp.begin(), tmp.end(), i);
			tmp.erase(it);
		    bool ret = ((col < board.size()-1) ? solve2(board, row, col+1, tmp) : solve2(board, row+1, 0, tmp));
			if (ret) return true;
		}
		board[row][col] = 0; // Remember to reset the unfinished cell.
	}
	return false;
}
#endif

void print_board(const vector<vector<int>>& board) {
	for (const auto& row : board) {
		for (const int& i : row) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	vector<vector<int>> board{{5,3,0,0,7,0,0,0,0}, {6,0,0,1,9,5,0,0,0}, {0,9,8,0,0,0,0,6,0},
							  {8,0,0,0,6,0,0,0,3}, {4,0,0,8,0,3,0,0,1}, {7,0,0,0,2,0,0,0,6},
							  {0,6,0,0,0,0,2,8,0}, {0,0,0,4,1,9,0,0,5}, {0,0,0,0,8,0,0,7,9}};
	cout << "Input board:" << endl;
	print_board(board);
	bool ret;
#if defined PERMUTATION
	ret = solve(board, 0);
#elif defined SEARCH
	ret = solve2(board, 0, 0, vector<int>());
#endif
	cout << (ret? "Solution:" : "No Solution Found!") << endl;
	print_board(board);
	return 0;
}
