class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.size(), m = T.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[m][n] = 0;
        
        int min_length = numeric_limits<int>::max();
        int min_start = n;
        for (int j = m; j >= 0; --j) {
            for (int i = n; i >= 0; --i) {
                if (n - i < m - j) {
                    dp[j][i] = numeric_limits<int>::max();
                } else if (j == m) {
                    dp[j][i] = 0;
                } else {
                    if (S[i] == T[j]) {
                        dp[j][i] = dp[j+1][i+1] == numeric_limits<int>::max() ? dp[j+1][i+1] : 1 + dp[j+1][i+1];
                    } else {
                        dp[j][i] = dp[j][i+1] == numeric_limits<int>::max() ? dp[j][i+1] : 1 + dp[j][i+1];
                    }
                }
                
                // Update the minimum substring if possible.
                if (j == 0 && dp[j][i] < numeric_limits<int>::max() && dp[j][i] <= min_length) {
                    min_length = dp[j][i];
                    // We reduce i so when the program finishes we get 
                    // the smallest starting index if one exists.
                    min_start = i;
                }
            }
        }
        
        return S.substr(min_start, min_length);
    }
};
