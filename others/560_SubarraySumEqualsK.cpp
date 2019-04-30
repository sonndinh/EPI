class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> val_to_count;
        // Empty prefix subarray sums up to 0.
        val_to_count[0] = 1;
        int ret = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0)
                nums[i] += nums[i-1];
            if (val_to_count.count(nums[i] - k) > 0) {
                ret += val_to_count[nums[i] - k];
            }
            val_to_count[nums[i]]++;
        }
        
        return ret;
    }
};
