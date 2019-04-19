class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        int i = 0, end = s.size();
        // Trim front spaces
        while (s[i] == ' ') {++i;}
        
        // Trim trailing spaces.
        while (s[end-1] == ' ') {--end;}
        
        // First letter could be a sign.
        if (s[i] == '+' || s[i] == '-') {
            ++i;
        }
        
        // Next letter could be a digit or a dot '.'.
        if (s[i] >= '0' && s[i] <= '9') {
            while (i < end && s[i] >= '0' && s[i] <= '9') {++i;}
            if (i == end) return true;
            
            // Next letter must be 'e' or '.'.
            if (s[i] != 'e' && s[i] != '.') return false;
            if (s[i] == '.') {
                ++i;
                while (i < end && s[i] >= '0' && s[i] <= '9') {++i;}
            }
            if (i == end) return true;
        } else if (s[i] != '.') {
            return false;
        } else {
            // Next character must be a digit.
            if (++i == end || !(s[i] >= '0' && s[i] <= '9')) return false;
            while (i < end && s[i] >= '0' && s[i] <= '9') {++i;}
            if (i == end) return true;
        }
        
        if (s[i] != 'e' || (s[i] == 'e' && ++i == end)) return false;
        
        if (s[i] == '+' || s[i] == '-') ++i;
        if (i == end || !(s[i] >= '0' && s[i] <= '9')) return false;
        while (i < end && s[i] >= '0' && s[i] <= '9') {++i;}
        
        if (i < end) return false;
        return true;
    }
};
