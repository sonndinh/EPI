#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool helper(const string& t, int i, const string& s1, int i1, const string& s2, int i2) {
	if (i == t.size() || i1 == s1.size() || i2 == s2.size())
		return true;
		
	if (t[i] == s1[i1] && t[i] == s2[i2])
		return helper(t, i+1, s1, i1+1, s2, i2) || helper(t, i+1, s1, i1, s2, i2+1);
	else if (t[i] == s1[i1])
		return helper(t, i+1, s1, i1+1, s2, i2);
	else if (t[i] == s2[i2])
		return helper(t, i+1, s1, i1, s2, i2+1);
	else
		return false;
}

// Return whether string t is formed by interleaving s1 and s2.
bool is_interleaved(const string& t, const string& s1, const string& s2) {
	if (t.size() != s1.size() + s2.size())
		return false;

	return helper(t, 0, s1, 0, s2, 0);
}


bool is_interleaved2(const string& t, const string& s1, const string& s2) {
	if (t.size() != s1.size() + s2.size())
		return false;

	int n = t.size(), n1 = s1.size(), n2 = s2.size();
	vector<vector<int>> dp(n1+1, vector<int>(n2+1));
	dp[n1][n2] = true;
	for (int i = n1-1; i >= 0; i--) {
		dp[i][n2] = dp[i+1][n2] && s1[i] == t[i+n2];
	}
	for (int j = n2-1; j >= 0; j--) {
		dp[n1][j] = dp[n1][j+1] && s2[j] == t[j+n1];
	}
	
	for (int i = n1-1; i >= 0; i--) {
		for (int j  = n2-1; j >= 0; j--) {
			if (s1[i] == t[i+j] && s2[j] == t[i+j]) {
				dp[i][j] = dp[i+1][j] || dp[i][j+1];
			} else if (s1[i] == t[i+j]) {
				dp[i][j] = dp[i+1][j];
			} else if (s2[j] == t[i+j]) {
				dp[i][j] = dp[i][j+1];
			} else {
				dp[i][j] = false;
			}
		}
	}

	return dp[0][0];
}

int main() {
	string t = "gattaca", s1 = "gtaa", s2 = "atc";
	string t1 = "gtataac", t2 = "gatacta";
	cout << t << (is_interleaved2(t, s1, s2)? " Is an interleaving" : " Is NOT an interleaving") << endl;
	cout << t1 << (is_interleaved2(t1, s1, s2)? " Is an interleaving" : " Is NOT an interleaving") << endl;
	cout << t2 << (is_interleaved2(t2, s1, s2)? " Is an interleaving" : " Is NOT an interleaving") << endl;
	return 0;
}
