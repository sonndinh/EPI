class Solution {
public:
    // Running time O(n^2m), space O(nm).
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int max_area = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = j == 0 ? 1 : 1 + dp[i][j-1];
                    
                    // Consider the maximum area with bottom right at this coordinate.
                    int width = dp[i][j]; // Running min width.
                    int height = 0; // Cumulative height.
                    for (int k = i; k >= 0; --k) {
                        width = min(width, dp[k][j]);
                        ++height;
                        max_area = max(max_area, width * height);
                    }
                }
            }
        }
        
        return max_area;
    }
};
