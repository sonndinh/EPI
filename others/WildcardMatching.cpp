#include <iostream>
#include <string>
#include <vector>
using namespace std;


// Recursive implementation.
bool is_match_helper(const string& s, int i, const string& p, int j) {
	// Some characters in the text do not match.
	if (j >= p.size() && i < s.size())
		return false;

	// Some characters left in the pattern.
	if (j < p.size() && i >= s.size()) {
		if (p[j] == '*')
			return is_match_helper(s, i, p, j+1);
		else
			return false;
	}

	// All characters match.
	if (j >= p.size() && i >= s.size())
		return true;
		
	if (p[j] == '*') {
		return is_match_helper(s, i, p, j+1) || is_match_helper(s, i+1, p, j+1)
			|| is_match_helper(s, i+1, p, j);
	}

	if (p[j] == '?' || p[j] == s[i]) {
		return is_match_helper(s, i+1, p, j+1);
	}
	
	return false;
}

// Implement wildcard pattern matching.
// '?' matches any single character.
// '*' matches any sequence of characters, including empty.
// E.g., ("aab", "c*a*b") -> 0 (not match).
int is_match(const string& s, const string& p) {
	return (is_match_helper(s, 0, p, 0)? 1 : 0);
}

// Using DP. Time and space complexity O(mn).
int is_match2(const string& s, const string& p) {
	int n = s.size(), m = p.size();
	vector<vector<bool>> dp(m+1, vector<bool>(n+1));

	// Initialize the edge values.
	dp[m][n] = true;
	for (int i = 0; i < n; i++) {
		dp[m][i] = false;
	}

	for (int j = m-1; j >= 0; j--) {
		if (p[j] == '*') {
			dp[j][n] = dp[j+1][n];
		} else {
			dp[j][n] = false;
		}
	}

	// Compute the DP table.
	for (int j = m-1; j >= 0; j--) {
		for (int i = n-1; i >= 0; i--) {
			if (p[j] == '*') {
				dp[j][i] = dp[j+1][i+1] || dp[j][i+1] || dp[j+1][i];
			} else if (p[j] == '?' || p[j] == s[i]) {
				dp[j][i] = dp[j+1][i+1];
			} else {
				dp[j][i] = false;
			}
		}
	}

	return (dp[0][0]? 1 : 0);
}

int main() {
	string s = "aa", s2 = "aab", s3 = "ab", s4 = "bb", s5 = "abcd";
	string p = "aa*", p2 = "aaa", p3 = "?*", p4 = "*", p5 = "*??**";
	cout << "String: " << s << ", pattern: " << p << ": " << (is_match2(s, p)? "Match" : "Not match") << endl;
	cout << "String: " << s2 << ", pattern: " << p2 << ": " << (is_match2(s2, p2)? "Match" : "Not match") << endl;
	cout << "String: " << s3 << ", pattern: " << p3 << ": " << (is_match2(s3, p3)? "Match" : "Not match") << endl;
	cout << "String: " << s4 << ", pattern: " << p4 << ": " << (is_match2(s4, p4)? "Match" : "Not match") << endl;
	cout << "String: " << s5 << ", pattern: " << p5 << ": " << (is_match2(s5, p5)? "Match" : "Not match") << endl;
	return 0;
}
