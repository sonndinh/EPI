class Solution {
private:
    void gen_helper(vector<string>& ret, string digits, int i, string curr, unordered_map<char, string>& keys) {
        if (i == digits.size()) {
            ret.emplace_back(curr);
            return;
        }
        
        // Map for the next digit.
        string key = keys[digits[i]];
        for (int j = 0; j < key.size(); ++j) {
            gen_helper(ret, digits, i+1, curr + key[j], keys);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> keys{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                                         {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> ret;
        if (digits.empty()) return ret;
        
        gen_helper(ret, digits, 0, "", keys);
        return ret;
    }
};
