class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> my_map;
        for (int i = 0; i < strs.size(); ++i) {
            string& s = strs[i];
            int count[26] = {0};
            for (int j = 0; j < s.size(); ++j) {
                count[s[j] - 'a']++;
            }
            string code;
            for (int j = 0; j < 26; ++j) {
                code += to_string(count[j]) + (char)(j + 'a');
                code += "#";
            }
            my_map[code].emplace_back(s);
        }
        
        vector<vector<string>> ret;
        for (auto& p : my_map) {
            ret.emplace_back(p.second);
        }
        return ret;
    }
};
