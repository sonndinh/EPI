class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> count;
        vector<int>& small = (nums1.size() < nums2.size() ? nums1 : nums2);
        vector<int>& large = (nums1.size() >= nums2.size() ? nums1 : nums2);
        
        for(int i = 0; i < small.size(); ++i) {
            count[small[i]]++;
        }
        
        for (int i = 0; i < large.size(); i++) {
            int num = large[i];
            if (count.find(num) != count.end() && count[num] > 0) {
                ret.push_back(num);
                count[num]--;
            }
        }
        return ret;
    }
};
