#include <iostream>
#include <vector>
using namespace std;

// Return whether a string matches a pattern.
// A '.' matches any single character. A '*' matches zero or more
// preceding character in the pattern. 
bool is_match(string txt, string pat) {
	int n = txt.size();
	int m = pat.size();
	vector<vector<bool>> dp(n+1, vector<bool>(m+1));
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j == 0) {
				// Empty pattern.
				dp[i][j] = true;
			} else if (i == 0) {
				// Empty text, non-empty pattern.
				if (j < m && pat[j] == '*') {
					if (j > 1 && pat[j-2] != '*')
						dp[i][j] = dp[i][j-1];
					else if (j > 1 && pat[j-2] == '*')
						dp[i][j] = dp[i][j-2];
					else
						dp[i][j] = true;
				} else {
					dp[i][j] = false;
				}
			} else {
				bool first_match = pat[j-1] == '.' || pat[j-1] == txt[i-1];
				if (j < m && pat[j] == '*') {
					if (first_match && j > 1 && pat[j-2] == '*') {
						dp[i][j] = dp[i][j-2] || dp[i-1][j];
					} else if (first_match && j > 1 && pat[j-2] != '*') {
						dp[i][j] = dp[i][j-1] || dp[i-1][j];
					} else if (!first_match && j > 1 && pat[j-2] == '*') {
						dp[i][j] = dp[i][j-2];
					} else {
						dp[i][j] = dp[i][j-1];
					}
				} else if (j < m && pat[j] != '*'){
					if (j > 1 && pat[j-2] == '*') {
						dp[i][j] = first_match && dp[i-1][j-2];
					} else {
						dp[i][j] = first_match && dp[i-1][j-1];
					}
				} else {
					if (j > 1 && pat[j-2] == '*') {
						dp[i][j] = first_match && dp[i-1][j-2];
					} else {
						dp[i][j] = first_match && dp[i-1][j-1];
					}
				}
			}
		}
	}
	return dp[n][m];
}

int main() {
	string text = "a";
	string pattern = "a*";
	bool ret = is_match(text, pattern);
	cout << "String: " << text << " and pattern: " << pattern << (ret? " match!" : " not match!") << endl;
	return 0;
}
