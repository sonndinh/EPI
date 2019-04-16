class Solution {
private:
    void helper(vector<vector<int>>& ret, vector<int>& input, int i, vector<int>& arr) {
        if (i == input.size()) {
            ret.emplace_back(arr);
            return;
        }
        
        // Exclude the current element.
        helper(ret, input, i+1, arr);
        
        // Include the current element.
        arr.push_back(input[i]);
        helper(ret, input, i+1, arr);
        arr.pop_back();
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        helper(ret, nums, 0, tmp);
        return ret;
    }
};
