class Solution {
public:
    // Brute force.
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        for (int i = 0; i <= (int)haystack.size() - (int)needle.size(); ++i) {
            int j;
            for (j = 0; j < needle.size(); ++j) {
                if (haystack[i] != needle[j]) {
                    i -= j;
                    break;
                } else {
                    ++i;
                }
            }
            if (j == needle.size()) 
                return i - needle.size();
        }
        
        return -1;
    }
};
