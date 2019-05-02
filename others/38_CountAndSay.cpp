class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 2; i <= n; ++i) {
            string tmp; int count = 0;
            for (int j = 0; j < s.size(); ++j) {
                if (j == 0 || s[j] == s[j-1]) {
                    ++count;
                } else {
                    tmp += to_string(count) + s[j-1];
                    count = 1;
                }
            }
            tmp += to_string(count) + s[s.size()-1];
            s = move(tmp);
        }
        return s;
    }
};
