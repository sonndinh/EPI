class Solution {
public:
    int longestConsecutive2(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        int max = 0, count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1])
                continue;
            if (nums[i] == nums[i-1]+1) {
                ++count;
            } else {
                if (count > max) {
                    max = count;
                }
                count = 1;
            }
        }
        if (count > max)
            max = count;
        
        return max;
    }
	
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> my_set(nums.begin(), nums.end());
        
        int max = 0;
        while (!my_set.empty()) {
            int a = *my_set.begin();
            if (my_set.count(a) > 0) {
                my_set.erase(a);
                int count = 1;
                int tmp = a;
                while (my_set.count(--tmp) > 0) {
                    ++count;
                    my_set.erase(tmp);
                }
                tmp = a;
                while (my_set.count(++tmp) > 0) {
                    ++count;
                    my_set.erase(tmp);
                }
                if (count > max) {
                    max = count;
                }
            }
        }
        
        return max;
    }
};
