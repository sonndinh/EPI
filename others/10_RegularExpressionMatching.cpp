class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true;
        
        for (int j = m-1; j >= 0; --j) {
            for (int i = n; i >= 0; --i) {
                bool match = i < n && (p[j] == '.' || p[j] == s[i]);
                if (match) {
                    if (j < m-1 && p[j+1] == '*') {
                        dp[j][i] = dp[j+2][i] || dp[j][i+1];
                    } else {
                        dp[j][i] = dp[j+1][i+1];
                    }
                } else {
                    if (j < m-1 && p[j+1] == '*') {
                        dp[j][i] = dp[j+2][i];
                    } else {
                        dp[j][i] = false;
                    }
                }
            }
        }
        
        return dp[0][0];
    }
};
