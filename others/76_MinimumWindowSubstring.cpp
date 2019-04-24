class Solution {
public:
    string minWindow(string s, string c) {
        if (s.empty() || c.empty())
            return "";
        
        unordered_map<char, int> char_map;
        for (int i = 0; i < c.size(); ++i) {
            char_map[c[i]]++;
        }
        
        string ret;
        // Characters needed.
        unordered_map<char, int> need_char = char_map;
        unordered_map<char, int> count;
        
        for (int i = 0, j = -1; j < (int)s.size();) {
            if (!need_char.empty()) {
                // Increase j.
                int old_j = j;
                while (++j < s.size() && char_map.find(s[j]) == char_map.end());
                if (old_j == -1) {
                    i = j;
                }
                if (j < s.size()) {
                    count[s[j]]++;
                    if (need_char.find(s[j]) != need_char.end()) {
                        need_char[s[j]]--;
                        if (need_char[s[j]] == 0) 
                            need_char.erase(s[j]);
                                                
                        if (need_char.empty()) {
                            if (ret.empty() || ret.size() > (j-i+1) || 
                                (ret.size() == j-i+1 && ret > s.substr(i, j-i+1))) {
                                ret = s.substr(i, j-i+1);
                            }
                        }
                    }
                }
            } else {
                if (i == j) {
                    // Increase j.
                    while (++j < s.size() && char_map.find(s[j]) == char_map.end());
                    if (j < s.size()) {
                        count[s[j]]++;
                        if (need_char.find(s[j]) != need_char.end()) {
                            need_char[s[j]]--;
                            if (need_char[s[j]] == 0) 
                                need_char.erase(s[j]);
                        }
                    }
                } else {
                    // Increase i.
                    count[s[i]]--;
                    if (count[s[i]] < char_map[s[i]])
                        need_char[s[i]]++;
                    while (char_map.find(s[++i]) == char_map.end() && i <= j);
                    // See if we can update the result.
                    if (i <= j) {
                        if (need_char.empty()) {
                            if (ret.empty() || ret.size() > (j-i+1) || 
                                (ret.size() == j-i+1 && ret > s.substr(i, j-i+1))) {
                        ret = s.substr(i, j-i+1);
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
    
    
    string minWindow2(string s, string c) {
        unordered_map<char, int> c_map;
        for (char ch : c) {
            c_map[ch]++;
        }
        // Store the appearances of the characters in the input string.
        vector<pair<int, char>> pos;
        for (int i = 0; i < s.size(); i++) {
            if (c_map.find(s[i]) != c_map.end()) {
                pos.emplace_back(make_pair(i, s[i]));
            }
        }

        // Not all characters found.
        if (pos.size() < c.size()) return string();

        int length = 0;
        string ret = "";
        unordered_map<char, int> count;
        for (int i = 0, j = 0; i < pos.size()-c.size()+1 && j < pos.size();) {
            if (j == 0) {
                count[pos[j].second]++;
            }

            if (is_satisfied(c_map, count)) {
                int cur_len = pos[j].first - pos[i].first + 1;
                string cur_str = s.substr(pos[i].first, cur_len);
                if (ret.empty() || cur_len < length || (cur_len == length && cur_str.compare(ret) < 0)) {
                    length = cur_len;
                    ret = cur_str;
                }
                count[pos[i].second]--;
                if (count[pos[i].second] == 0) {
                    count.erase(pos[i].second);
                }
                
                // Advance the pointers.
                if (i < j) {
                    i++;
                } else {
                    j++;
                }
            } else {
                j++;
                if (j < pos.size()) {
                    count[pos[j].second]++;
                }
            }
        }

        return ret;
    }
    
    private:
    bool is_satisfied(const unordered_map<char, int>& c_map, const unordered_map<char, int>& count) {
        for (const pair<char, int>& p : c_map) {
            if (count.find(p.first) == count.end() || count.at(p.first) < p.second) {
                return false;
            }
        }
        return true;
    }

};
