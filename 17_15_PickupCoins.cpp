#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Compute the maximum margin of victory for the first player.
// Input is a line of even number of coins.
int margin(vector<int>& coins) {
	int n = coins.size();
	// Only accept even number of coins.
	if (n % 2 != 0) return -1;

	// Entry [i, j] in this table contains the maximum profit of the
	// first player for a line of coins from i to j inclusive, given
	// the first player goes first.
	// Note that the second player always pick coins so as to maximize
	// his profit.
	vector<vector<int>> table(n, vector<int>(n, 0));
	for (int i = n-1; i >= 0; i--) {
		for (int j = i+1; j <= n-1; j++) {				
			if ((j - i + 1) % 2 == 0) {
				int t_i2_j = i+2 > j || i+2 > n-1 ? 0 : table[i+2][j];
				int t_i1_j_1 = i+1 > j-1 || i+1 > n-1 ? 0 : table[i+1][j-1];
				int t_i_j_2 = i > j-2 ? 0 : table[i][j-2];				
				table[i][j] = max(coins[i] + min(t_i2_j, t_i1_j_1),
								  coins[j] + min(t_i1_j_1, t_i_j_2));
			}
		}
	}

	return table[0][n-1];
}

int main() {
	vector<int> coins{25, 5, 10, 5, 10, 5, 10, 25, 1, 25, 1, 25, 1, 25, 5, 10};
	cout << "Max profit for the first player: " << margin(coins) << endl;
	return 0;
}
