class Solution {
private:
    void sum(string& ret, string& tmp) {
        string small = ret.size() < tmp.size()? ret : tmp;
        string large = ret.size() >= tmp.size()? ret : tmp;
        string sum;
        int carry = 0;
        
        for (int i = (int)large.size()-1, j = (int)small.size()-1; i >= 0; --i, --j) {
            int val;
            if (j >= 0) {
                val = (large[i] - '0') + (small[j] - '0') + carry;
            } else {
                val = (large[i] - '0') + carry;
            }
            carry = val / 10;
            sum = char(val % 10 + '0') + sum;
        }
        if (carry > 0) {
            sum = char(carry + '0') + sum;
        }
        ret = sum;
    }
    
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty() || num1[0] == '0' || num2[0] == '0') return "0";
        
        string ret;
        for (int i = 0; i < num2.size(); ++i) {
            int digit = num2[i] - '0';
            string tmp; int carry = 0;
            for (int j = num1.size()-1; j >= 0; --j) {
                int digit1 = num1[j] - '0';
                int prod = digit1 * digit + carry;
                carry = prod / 10;
                tmp = char(prod % 10 + '0') + tmp;
            }
            if (carry > 0) {
                tmp = char(carry + '0') + tmp;
            }
            if (!ret.empty()) {
                ret += '0';
                sum(ret, tmp);
            } else {
                ret = tmp;
            }
        }
        
        // Remove prepending zeros.
        size_t idx = ret.find_first_not_of('0');
        return idx == ret.size() ? "0" : ret.substr(idx);
    }
};
