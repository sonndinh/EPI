class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x;
        while (start <= end) {
            long mid = (end + start)/2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end;
    }
};
