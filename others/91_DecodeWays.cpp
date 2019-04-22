class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;

        int n = s.size();
        vector<int> dp(n+1);
        dp[n] = 1;
        if (s[n-1] == '0')
            dp[n-1] = 0;
        else
            dp[n-1] = 1;

        for (int i = n-2; i >= 0; i--) {
            int x = s[i] - '0';
            if (x == 0) {
                if (i == 0 || (s[i-1] - '0' > 2 || s[i-1] - '0' == 0))
                    return 0;
                continue;
            }
            int y = s[i+1] - '0';
            int a = x*10 + y;

            if (a == 10 || a == 20) {
                dp[i] = dp[i+2];
            } else if (a > 26) {
                dp[i] = dp[i+1];
            } else { // a <= 26 and different than 10 and 20.
                dp[i] = dp[i+1] + dp[i+2];
            }
        }
        return dp[0];
    }
};
