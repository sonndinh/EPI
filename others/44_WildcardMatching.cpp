class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty() && !s.empty()) return false;
        else if (p.empty() && s.empty()) return true;
        
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

        return dp[0][0];
    }
};
