class Solution {
public:
    int divide(int dividend, int divisor) {
        // Cast to long since abs(-2^31) cannot be stored in int.
        long abs_dividend = abs((long)dividend);
        
        long ret = 0;
        while (1) {
            long abs_divisor = abs((long)divisor);
            int double_count = 1;
            while (abs_dividend >= abs_divisor) {
                abs_dividend -= abs_divisor;
                ret += double_count;
                
                // Double the absolute divisor.
                abs_divisor += abs_divisor;
                double_count <<= 1;
            }
            if (abs_dividend < abs((long)divisor))
                break;
        }
        
        if ((dividend >= 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            if (ret > numeric_limits<int>::max())
                return numeric_limits<int>::max();
            return (int)ret;
        } else {
            return (int)-ret;
        }
    }
};
