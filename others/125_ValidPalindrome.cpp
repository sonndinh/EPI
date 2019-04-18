class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for (int i= 0, j = n-1; i < j;) {
            if (s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z') {
                ++i;
                continue;
            }
            if (s[j] < '0' || (s[j] > '9' && s[j] < 'A') || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z') {
                --j;
                continue;
            }
            
            if (s[i] >= '0' && s[i] <= '9') {
                if (s[i] != s[j]) {
                    return false;
                }
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                if (s[j] >= 'a' && s[j] <= 'z') {
                    if (s[i] != s[j] - 32) return false;
                } else if (s[i] != s[j]) {
                    return false;
                }
            } else { // 'a' to 'z'.
                if (s[j] >= 'A' && s[j] <= 'Z') {
                    if (s[i] - 32 != s[j]) return false;
                } else if (s[i] != s[j]) {
                    return false;
                }
            }
            ++i;
            --j;
        }
        
        return true;
    }
};
