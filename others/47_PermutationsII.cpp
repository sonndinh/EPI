class Solution {
public:
    void helper(unordered_map<int, int>& count, vector<int>& curr, int i, int n, vector<vector<int>>& ret) {
        if (i == n) {
            ret.emplace_back(curr);
            return;
        }
        
        for (auto& p : count) {
            if (p.second > 0) {
                curr[i] = p.first;
                p.second--;
                helper(count, curr, i+1, n, ret);
                p.second++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.empty())
            return ret;
        
        // Count number of duplicates of each unique number.
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++;
        }
        
        vector<int> tmp(nums.size());
        helper(count, tmp, 0, nums.size(), ret);
        return ret;
    }
};
