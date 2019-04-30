class Solution {
private:
    double pow_helper(double x, long n) {
        if (n == 0) return 1.0;
        double half = pow_helper(x, n/2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
    
public:
    double myPow(double x, int n) {
        long n_long = n;
        if (n < 0) {
            x = 1/x;
            n_long = -n_long;
        }
        
        return pow_helper(x, n_long);
    }
};
