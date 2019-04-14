class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Next position for zero.
        int next_pos = (int)nums.size() - 1;
        for (int i = nums.size()-1; i >= 0; --i) {
            if (nums[i] == 0) {
                if (i < next_pos) {
                    // Move this zero to the correct position.
                    int k = i;
                    for (int j = i+1; j <= next_pos; ++j, ++k) {
                        int tmp = nums[j];
                        nums[j] = 0;
                        nums[k] = tmp;
                    }
                }
                --next_pos;
            }
        }
    }
    
    void moveZeroes2(vector<int>& nums) {
        // Time complexity O(n^2).
        for (int i = 0; i < (int)nums.size()-1; ++i) {
            if (nums[i] == 0) {
                int k = i;
                for (int j = k+1; j < nums.size(); ++j, ++k) {
                    // Swap entry k with entry j.
                    int tmp = nums[j];
                    nums[j] = 0;
                    nums[k] = tmp;
                }
            }
        }
    }
};
