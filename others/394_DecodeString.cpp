class Solution {
private:
    int toNum(string num) {
        int ret = 0;
        for (char c : num) {
            int digit = c - '0';
            ret = ret * 10 + digit;
        }
        return ret;
    }
    
    string concat(stack<string>& stk, string num, string txt) {
        int n = toNum(num);
        string tmp;
        while (n-- > 0) {
            tmp += txt;
        }
        while (!stk.empty() && stk.top() != "[" && stk.top() != "]") {
            tmp = stk.top() + tmp;
            stk.pop();
        }
        return tmp;
    }
    
public:
    string decodeString(string s) {
        stack<string> stk;
        for (int i = 0; i < s.size();) {
            if (s[i] == ']') {
                string txt;
                while (stk.top() != "[") {
                    txt = stk.top() + txt;
                    stk.pop();
                }
                // Pop the open bracket.
                stk.pop();
                string num = stk.top();
                stk.pop();
                string t = concat(stk, num, txt);
                stk.push(t);
                ++i;
            } else if (isdigit(s[i])) {
                string num;
                while (isdigit(s[i])) {
                    num += s[i];
                    ++i;
                }
                stk.push(num);
            } else if (isalpha(s[i])) {
                string txt;
                while (i < s.size() && isalpha(s[i])) {
                    txt += s[i];
                    ++i;
                }
                stk.push(txt);
            } else {
                stk.push("[");
                ++i;
            }
        }
        
        // Concatenate strings in the stack.
        string ret;
        while (!stk.empty()) {
            ret = stk.top() + ret;
            stk.pop();
        }
        
        return ret;
    }
};
