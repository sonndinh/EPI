class Solution {
public:
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
