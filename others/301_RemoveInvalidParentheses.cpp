class Solution {
private:
    void helper(unordered_set<string>& ret, string& s, int i, int open_count, int close_count, string curr, int curr_open, int curr_close) {
        if (i == s.size()) {
            if (open_count == 0 && close_count == 0) {
                ret.emplace(curr);
            }
            return;
        } else if (curr_close > curr_open) { 
            // Backtrack.
            return;
        }
    
        if (s[i] == '(') {
            if (open_count > 0) {
                // Choose not to remove this one first.
                helper(ret, s, i+1, open_count, close_count, curr+'(', curr_open+1, curr_close);
                
                // Then choose to remove it.
                helper(ret, s, i+1, open_count-1, close_count, curr, curr_open, curr_close);
            } else { 
                // No unmatched open paren left, must take this one.
                helper(ret, s, i+1, open_count, close_count, curr+'(', curr_open+1, curr_close);
            }
        } else if (s[i] == ')') {
            if (close_count > 0) {
                // Not removing this close paren first.
                helper(ret, s, i+1, open_count, close_count, curr+')', curr_open, curr_close+1);
                
                // Then remove it.
                helper(ret, s, i+1, open_count, close_count-1, curr, curr_open, curr_close);
            } else {
                helper(ret, s, i+1, open_count, close_count, curr+')', curr_open, curr_close+1);
            }
        } else {
            // Include other characters.
            helper(ret, s, i+1, open_count, close_count, curr+s[i], curr_open, curr_close);
        }
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        // Count the number of unmatched close and open parentheses.
        int open_paren = 0, close_paren = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++open_paren;
            } else if (s[i] == ')' && open_paren > 0) {
                // Match this close paren with a previous open paren.
                --open_paren;
            } else if (s[i] == ')') {
                // This close paren is unmatched.
                ++close_paren;
            }
        }
        
        vector<string> ret;
        if (open_paren == 0 && close_paren == 0) {
            ret.emplace_back(s);
        } else {
            unordered_set<string> my_set;
            helper(my_set, s, 0, open_paren, close_paren, "", 0, 0);
            ret.insert(ret.begin(), my_set.begin(), my_set.end());
        }
        
        return ret;
    }
};
