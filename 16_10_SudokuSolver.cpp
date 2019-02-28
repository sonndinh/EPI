#include <iostream>
#include <vector>

using namespace std;

void permu(vector<vector<int>>& permutations, vector<int> curr, vector<int> remain);
bool checker(const vector<vector<int>>& board);

bool solve(vector<vector<int>>& board, int row) {
	if (row == board.size()) return true;

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

void print_board(const vector<vector<int>>& board) {
	cout << "Solution: " << endl;
	for (const auto& row : board) {
		for (const int& i : row) {
			cout << row[i] << " ";
		}
		cout << endl;
	}
}

int main() {
	vector<vector<int>> board{{5,3,0,0,7,0,0,0,0}, {6,0,0,1,9,5,0,0,0}, {0,9,8,0,0,0,0,6,0},
							  {8,0,0,0,6,0,0,0,3}, {4,0,0,8,0,3,0,0,1}, {7,0,0,0,2,0,0,0,6},
							  {0,6,0,0,0,0,2,8,0}, {0,0,0,4,1,9,0,0,5}, {0,0,0,0,8,0,0,7,9}};
	bool ret = solve(board, 0);
	cout << "Solve " << (ret? "Successfully" : "Unsuccessfully") << endl;
	print_board(board);
	return 0;
}
