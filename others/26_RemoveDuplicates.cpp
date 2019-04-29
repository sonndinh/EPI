class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int write_idx = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                nums[write_idx] = nums[i];
                ++write_idx;
            }
        }
        return write_idx;
    }
};
