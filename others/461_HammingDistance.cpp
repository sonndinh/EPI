class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;

        int ret = 0, count = 0;
        while (count++ < 31) {
            if (tmp & 1) {
                ret++;
            }
            tmp = tmp >> 1;
        }
        
        return ret;
    }
};
