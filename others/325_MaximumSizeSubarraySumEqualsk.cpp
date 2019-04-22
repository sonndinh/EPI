class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        unordered_map<int, int> val_to_idx;
        // An entry for empty sum.
        val_to_idx[0] = -1;
        int max_len = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0)
                nums[i] += nums[i-1];
            int needed_sum = nums[i] - k;
            if (val_to_idx.count(needed_sum) > 0 && i - val_to_idx[needed_sum] > max_len) {
                max_len = i - val_to_idx[needed_sum];
            }
            
            if (val_to_idx.count(nums[i]) == 0) {
                val_to_idx[nums[i]] = i;
            }
        }
        
        return max_len;
    }
};
