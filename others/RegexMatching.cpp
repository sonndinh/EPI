#include <iostream>
#include <vector>
using namespace std;

// Return whether a string matches a pattern.
// A '.' matches any single character. A '*' matches zero or more
// preceding character in the pattern.
// Compute the DP table going forward is harder to implement than going backward.
bool is_match(string txt, string pat) {
	int n = txt.size();
	int m = pat.size();
	// Entry (i, j) in the table indicates whether text[0:i-1] matches pattern[0:j-1].
	vector<vector<bool>> dp(n+1, vector<bool>(m+1));
	dp[0][0] = true;

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			bool last_match = i > 0 && (pat[j-1] == '.' || txt[i-1] == pat[j-1]);
			
			if (j < m && pat[j] == '*') {
				if (!last_match) {
					if (j >= 2 && pat[j-2] == '*')
						dp[i][j] = dp[i][j-2];
					else
						dp[i][j] = dp[i][j-1];
				} else {
					if (j >= 2 && pat[j-2] == '*')
						dp[i][j] = dp[i][j-2] || dp[i-1][j];
					else
						dp[i][j] = dp[i][j-1] || dp[i-1][j];
				}
			} else {
				if (j >= 2 && pat[j-2] == '*')
					dp[i][j] = last_match && dp[i-1][j-2];
				else
					dp[i][j] = last_match && dp[i-1][j-1];
			}
		}
	}
	return dp[n][m];
}

// Computing the DP table going backward.
bool is_match2(string txt, string pat) {
	int n = txt.size();
	int m = pat.size();
	// Entry (i, j) in the table indicates whether text[i:n-1] matches pattern[j:m-1].
	vector<vector<bool>> dp(n+1, vector<bool>(m+1));
	dp[n][m] = true;

	for (int i = n; i >= 0; i--) {
		for (int j = m-1; j >= 0; j--) {
			bool first_match = i < n && (pat[j] == '.' || txt[i] == pat[j]);
			if (j < m - 1 && pat[j+1] == '*') {
				if (!first_match)
					dp[i][j] = dp[i][j+2];
				else
					dp[i][j] = dp[i][j+2] || dp[i+1][j];
			} else {
				dp[i][j] = first_match && dp[i+1][j+1];
			}
		}
	}

	return dp[0][0];
}

// Recursive implementation.
bool is_match_recur(string txt, string pat) {
	if (pat.empty()) return txt.empty();
	bool first_match = !txt.empty() && (pat[0] == '.' || txt[0] == pat[0]);
	
	if (pat.size() > 1 && pat[1] == '*') {
		if (!first_match)
			return is_match_recur(txt, pat.substr(2));
		else
			return is_match_recur(txt.substr(1), pat) || is_match_recur(txt, pat.substr(2));
	} else {
		return first_match && is_match_recur(txt.substr(1), pat.substr(1));
	}
}

int main() {
	string text = "accdd";
	string pattern = "a*c.d*";
	// is_match() does not work correctly.
	bool ret = is_match2(text, pattern);
	//	bool ret = is_match_recur(text, pattern);
	cout << "String: \"" << text << "\" and pattern: \"" << pattern << (ret? "\" match!" : "\" not match!") << endl;
	return 0;
}
