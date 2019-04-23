class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        for (int i = 0, j = size-1; i < j; ++i, --j) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
    
    string reverse(string& s) {
        int size = s.size();
        string rev = s;
        for (int i = 0, j = size-1; i < j; ++i, --j) {
            swap(rev[i], rev[j]);
        }
        return rev;
    }

	// Time complexity O(n*m^2). Works better with large number of words,
	// and words have small length. Space complextiy O(n).
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> str_to_idx;
        vector<string> reverses(n);
        for (int i = 0; i < n; ++i) {
            str_to_idx[words[i]] = i;
            reverses[i] = reverse(words[i]);
        }
        
        vector<vector<int>> ret;
        for (int i = 0; i < n; ++i) {
            string rev_word = reverses[i];
            for (int j = -1; j < (int)rev_word.size(); ++j) {
                // Check if any of original words is a prefix of the reversed word.
                string prefix = rev_word.substr(0, j+1);
                if (str_to_idx.find(prefix) != str_to_idx.end()) {
                    if (str_to_idx[prefix] != i && isPalindrome(prefix + words[i])) {
                        ret.emplace_back(vector<int>{str_to_idx[prefix], i});
                        if (prefix.size() == rev_word.size())
                            // Abort duplicates.
                            continue;
                    }
                }
                
                // Check if any of original words is a suffix of the reversed word.
                string suffix = rev_word.substr(rev_word.size()-j-1, j+1);
                if (str_to_idx.find(suffix) != str_to_idx.end()) {
                    if (str_to_idx[suffix] != i && isPalindrome(words[i] + suffix))
                        ret.emplace_back(vector<int>{i, str_to_idx[suffix]});
                }
            }
        }
        
        return ret;
    }
    
    // Time complexity O(n^2*m), where n is the number of words,
    // m is the maximum length of a word. This works when n is small compared to m.
	// Space complexity O(1).
    vector<vector<int>> palindromePairs2(vector<string>& words) {
        vector<vector<int>> ret;
        int n = words.size();
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (isPalindrome(words[i] + words[j])) {
                    ret.emplace_back(vector<int>{i, j});
                }
                if (isPalindrome(words[j] + words[i])) {
                    ret.emplace_back(vector<int>{j, i});
                }
            }
        }
        return ret;
    }
};
