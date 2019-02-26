#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Check if a placement at a given row and column is a nonattacking placement.
bool check(vector<string>& board, int row, int col, int n) {
	for (int i = 0; i < board.size() - 1; i++) {
		int j = board[i].find('Q');
		// Check row and column conflict.
		if (i == row || j == col) return false;
		// Check diagonal conflict.
		for (int p = i + 1, q = j + 1; p < n && q < n; p++, q++) {
			// Check right side.
			if (p == row && q == col) return false;
		}
		for (int p = i + 1, q = j - 1; p < n && q >= 0; p++, q--) {
			// Check left side.
			if (p == row && q == col) return false;
		}
	}
	return true;
}

void helper(vector<vector<string>>& sols, vector<string> board, int row, int col, int n) {
	bool valid = check(board, row, col, n);
	if (!valid) {
		return;
	} else if (row == n - 1) {
		sols.push_back(board);
		return;
	} else {
		for (int i = 0; i < n; i++) {
			string s(n, '.');
			s[i] = 'Q';
			board.push_back(s);
			helper(sols, board, row+1, i, n);
			board.pop_back();
		}
	}
}

// Return a list of nonattacking placements for n queens in a nxn chessboard.
vector<vector<string>> nqueens(unsigned n) {
	vector<vector<string>> sols;
	for (int col = 0; col < n; col++) {
		vector<string> board;
		string s(n, '.');
		s[col] = 'Q';
		board.push_back(s);
		helper(sols, board, 0, col, n);
		board.pop_back();
	}
	return sols;
}

void print_sol(vector<vector<string>> solutions) {
	for (auto& sol : solutions) {
		cout << "[" << endl;
		for (string& row : sol) {
			cout << row << endl;
		}
		cout << "]" << endl;
	}

}

int main() {
	int n;
	cout << "Input chessboard size: ";
	cin >> n;
	vector<vector<string>> ret = nqueens(n);
	cout << "Number of solutions: " << ret.size() << endl;
	//	print_sol(ret);
	return 0;
}
