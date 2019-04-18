class Solution {
public:
    bool isValid(string s) {
        stack<char> my_stack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                my_stack.push(s[i]);
            } else if (my_stack.empty() || (s[i] == ')' && my_stack.top() != '(') || 
                       (s[i] == '}' && my_stack.top() != '{') || (s[i] == ']' && my_stack.top() != '[')) {
                return false;
            } else {
                my_stack.pop();
            }
        }

        return my_stack.empty();
    }
};
