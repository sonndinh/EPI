class Solution {
private:
    int str_to_int(string& a) {
        int ret = 0;
        for (int i = 0; i < a.size(); ++i) {
            ret *= 2;
            if (a[i] == '1') {
                ret += 1;
            }
        }
        return ret;
    }
    
    string int_to_str(int a) {
        string ret;
        if (a == 0)
            return "0";
        
        while (a > 0) {
            int digit = a % 2;
            ret = (digit == 1 ? '1' : '0') + ret;
            a = a / 2;
        }
        return ret;
    }
        
public:
    string addBinary2(string a, string b) {
        // Convert strings to integers.
        // Does not work for long strings (big integers).
        int sum = str_to_int(a) + str_to_int(b);
        return int_to_str(sum);
    }
    
    string addBinary(string a, string b) {
        string ret;
        char carry = '0';
        int i, j;
        for (i = a.size()-1, j = b.size()-1; i >= 0 && j >= 0; --i, --j) {
            if (a[i] == '0' && b[j] == '0') {
                ret = carry + ret;
                if (carry == '1') 
                    carry = '0';
            } else if ((a[i] == '0' && b[j] == '1') || (a[i] == '1' && b[j] == '0')) {
                if (carry == '0') {
                    ret = '1' + ret;
                } else {
                    ret = '0' + ret;
                    carry = '1';
                }
            } else { // both are '1's.
                if (carry == '0') {
                    ret = '0' + ret;
                    carry = '1';
                } else {
                    ret = '1' + ret;
                    carry = '1';
                }
            }
        }
        int k = -1;
        string *t;
        if (i >= 0) {
            k = i;
            t = &a;
        } else if (j >= 0) {
            k = j;
            t = &b;
        }
        if (k >= 0) {
            for (; k >= 0; --k) {
                if (carry == '0') {
                    if ((*t)[k] == '0') {
                        ret = '0' + ret;
                    } else {
                        ret = '1' + ret;
                    }
                } else {
                    if ((*t)[k] == '0') {
                        ret = '1' + ret;
                        carry = '0';
                    } else {
                        ret = '0' + ret;
                    }
                }
            }
        }
        if (carry == '1')
            ret = carry + ret;
        return ret;
    }
};
