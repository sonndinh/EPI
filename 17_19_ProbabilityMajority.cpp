#include <iostream>
#include <vector>
using namespace std;

// Each element in the input array is the probability that
// an candidate wins its corresponding election.
// The number of elements is odd. 
double prob(const vector<double>& arr, int k) {
	int n = arr.size();
	vector<vector<double>> table(n+1, vector<double>(n+1));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 && j == 0) {
				table[i][j] = 1;
			} else if (i > j) {
				table[i][j] = 0;
			} else {
				double p_i_1_j_1 = (i < 1 || j < 1) ? 0 : table[i-1][j-1];
				double p_i_j_1 = j < 1 ? 0 : table[i][j-1];
				table[i][j] = arr[j] * p_i_1_j_1 + (1-arr[j]) * p_i_j_1;
			}
		}
	}

	double ret = 0;
	for (int i = k; i <= n; i++) {
		ret += table[i][n];
	}
	
	return ret;
}

int main() {
	int k = 3;
	vector<double> arr{.6, .7, .5, .6, .5};
	double ret = prob(arr, k);
	cout << "Probability of winning: " << ret << endl;
	return 0;
}
