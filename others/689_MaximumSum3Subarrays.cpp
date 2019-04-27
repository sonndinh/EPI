class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> ret(3);
        int n = nums.size();
        
        // Compute prefix sum.
        for (int i = 1; i < n; ++i) {
            nums[i] += nums[i-1];
        }
        for (int i = n-1; i >= k; --i) {
            nums[i] -= nums[i-k];
        }

        vector<int> tmp2 = nums;
        for (int i = n-2; i >= 3*k-1; --i) {
            tmp2[i] = max(tmp2[i], tmp2[i+1]);
        }
        
        for (int i = 2*k-1; i <= n-1-k; ++i) {
            tmp2[i] = nums[i] + tmp2[i+k];
        }

        vector<int> tmp1 = tmp2;
        for (int i = n-1-k; i >= 2*k-1; --i) {
            tmp1[i] = max(tmp1[i], tmp1[i+1]);
        }
        
        for (int i = k-1; i <= n-1-2*k; ++i) {
            tmp1[i] = nums[i] + tmp1[i+k];
        }

        // Get the indexes of the subarrays.
        int max_idx = k - 1;
        int max_val = tmp1[max_idx];
        for (int i = max_idx; i <= n-1-2*k; ++i) {
            if (tmp1[i] > max_val) {
                max_val = tmp1[i];
                max_idx = i;
            }
        }
        ret[0] = max_idx - k + 1;
        
        max_val -= nums[max_idx];
        max_idx += k;
        for (int i = max_idx; i <= n-1-k; ++i) {
            if (tmp2[i] == max_val) {
                max_idx = i;
                break;
            }
        }
        ret[1] = max_idx - k + 1;
        
        max_val -= nums[max_idx];
        max_idx += k;
        for (int i = max_idx; i <= n-1; ++i) {
            if (nums[i] == max_val) {
                max_idx = i;
                break;
            }
        }
        ret[2] = max_idx - k + 1;
        
        return ret;
    }
};
