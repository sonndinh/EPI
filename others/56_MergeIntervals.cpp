class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if (intervals.empty()) return ret;
        // Sort input in ascending start times.
        sort(intervals.begin(), intervals.end(), 
            [] (const vector<int>& a, const vector<int>& b) -> bool {
                return a[0] < b[0];
            });
        
        vector<int>& range = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int>& curr = intervals[i];
            // If overlap, merge them together.
            if (curr[0] <= range[1]) {
                range[0] = min(range[0], curr[0]);
                range[1] = max(range[1], curr[1]);
            } else {
                ret.emplace_back(range);
                range = intervals[i];
            }
        }
        ret.emplace_back(range);
        
        return ret;
    }
};
