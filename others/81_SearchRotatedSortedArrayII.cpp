class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        
        int s = 0, e = nums.size() - 1;
        while (s < e && nums[s] <= nums[s+1]) {
            if (nums[s] == target)
                return true;
            ++s;
        }
        if (nums[s++] == target)
            return true;
        
        // nums[s:e] now is a sorted array (without rotated).
        // Do binary search on it to find target.
        while (s <= e) {
            int mid = s + (e - s)/2;
            if (nums[mid] == target)
                return true;
            
            if (nums[mid] > target)
                e = mid - 1;
            else 
                s = mid + 1;
        }
        return false;
    }
};
