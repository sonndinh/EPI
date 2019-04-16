class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3) 
            return ret;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < (int)nums.size()-2; ++i) {
            if (i == 0 || nums[i] != nums[i-1]) {
                int needed_sum = -nums[i];
                for (int j = i+1, k = nums.size()-1; j < k;) {
                    if (j == i+1 || nums[j] != nums[j-1]) {
                        if (nums[j] + nums[k] == needed_sum) {
                            ret.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                            ++j;
                        } else if (nums[j] + nums[k] > needed_sum) {
                            --k;
                        } else {
                            ++j;
                        }
                    } else {
                        j++;
                    }
                }
            }
        }
        return ret;
    }
};
