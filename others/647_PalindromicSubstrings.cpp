class Solution {
public:
    // Both time and space complexity is O(n^2).
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        int count = 0;
        
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n-len; ++i) {
                int j = i + len - 1;
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (i + 1 > j - 1) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if (dp[i][j])
                    ++count;
            }
        }
        return count;
    }
};
