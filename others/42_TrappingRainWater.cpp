class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) 
            return 0;
        
        int max_idx = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[max_idx] < height[i]) 
                max_idx = i;
        }
        
        int sum = 0, left = height.front();
        for (int i = 1; i < max_idx; ++i) {
            if (height[i] < left) {
                sum += left - height[i];
            } else {
                left = height[i];
            }
        }
        
        int right = height.back();
        for (int i = height.size()-1; i > max_idx; --i) {
            if (height[i] < right) {
                sum += right - height[i];
            } else {
                right = height[i];
            }
        }
        
        return sum;
    }
};
