#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <utility>
using namespace std;

// Decompose a string using minimum number of palindromic substrings.
vector<string> decompose(string s) {
	int n = s.size();
	vector<vector<bool>> palin(n, vector<bool>(n, false));
	vector<pair<int, int>> dp(n, {numeric_limits<int>::max(), -1});

	for (int i = n-1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (i == j || (s[i] == s[j] && (i+1 > j-1 || palin[i+1][j-1] == true))) {
				// Substring s[i:j] is palindromic.
				palin[i][j] = true;
				int tmp = 1 + (j == n-1 ? 0 : dp[j+1].first);
				if (tmp < dp[i].first) {
					dp[i].first = tmp;
					dp[i].second = j; // Store index of the last character.
				}
			}
		}
	}

	// Get the palindromic substrings.
	vector<string> ret;
	int i = 0;
	while (i < n) {
		int j = dp[i].second;
		ret.emplace_back(s.substr(i, j-i+1));
		i = j+1;
	}
	return ret;
}

int main() {
	string s = "020418812922351";
	auto ret = decompose(s);
	cout << "Minimum number of palindromic substrings " << ret.size() << endl;
	cout << "Substrings: ";
	for (string& str : ret) {
		cout << str << " ";
	}
	cout << endl;
	return 0;
}
