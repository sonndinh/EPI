class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int min_len = nums.size()+1, len = 1, sum = nums[0];
        for (int i = 0, j = 0; i < nums.size() && j < nums.size() && i <= j;) {
            if (sum >= s) {
                if (len < min_len) {
                    min_len = len;
                }
                sum -= nums[i];
                ++i;
                --len;
            } else if (sum < s) {
                ++j;
                if (j < nums.size()) {
                    sum += nums[j];
                    ++len;
                }
            }
        }
        return min_len == nums.size()+1 ? 0 : min_len;
    }
};
