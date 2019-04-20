class Solution {
public:
    struct Compare {
        vector<vector<int>>& nums;
        Compare(vector<vector<int>>& _nums) : nums(_nums) {}
        
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
            return nums[a.first][a.second] > nums[b.first][b.second];
        }
    };
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Number of elements for each array in the current range.
        unordered_map<int, int> count;
        vector<unordered_set<int>> nums_set(nums.size());
        
        // Find the next smallest number among all lists. Each pair contains 
        // index of a list and index of its next element.
        // This heap basically contains all element in the current considered range.
        Compare comp(nums);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> next_element(comp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> curr_heap(comp);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                next_element.push({i, j});
                nums_set[i].insert(nums[i][j]);
            }
        }

        // Track the smallest range and its corresponding gap.
        vector<int> min_range{0, numeric_limits<int>::max()};
        int min_diff = numeric_limits<int>::max();
        int curr_max = numeric_limits<int>::min();
        
        while (!next_element.empty()) {            
            if (count.size() == nums.size()) {
                int curr_min = nums[curr_heap.top().first][curr_heap.top().second];
                if (curr_max - curr_min < min_diff) {
                    min_diff = curr_max - curr_min;
                    min_range[0] = curr_min;
                    min_range[1] = curr_max;
                }
                // Remove the smallest element.
                pair<int, int> min_pair = curr_heap.top();
                curr_heap.pop();
                // Update the counts for all arrays that are affected.
                int num = nums[min_pair.first][min_pair.second];
                for (int i = 0; i < nums.size(); ++i) {
                    if (nums_set[i].find(num) != nums_set[i].end())
                        count[i]--;
                    if (count[i] == 0)
                        count.erase(i);
                }
            } else {
                // Add a new element to the current range.
                pair<int, int> next_pair = next_element.top();
                next_element.pop();
                curr_heap.push(next_pair);
                // Update the counts for all arrays that are affected.
                int num = nums[next_pair.first][next_pair.second];
                for (int i = 0; i < nums.size(); ++i) {
                    if (nums_set[i].find(num) != nums_set[i].end())
                        count[i]++;
                }
                int next_num = nums[next_pair.first][next_pair.second];
                if (curr_max < next_num) {
                    curr_max = next_num;
                }
            }
        }
        
        // Remove elements on the left to get smaller ranges.
        while (count.size() == nums.size()) {
                int curr_min = nums[curr_heap.top().first][curr_heap.top().second];
                if (curr_max - curr_min < min_diff) {
                    min_diff = curr_max - curr_min;
                    min_range[0] = curr_min;
                    min_range[1] = curr_max;
                }
                // Remove the smallest element.
                pair<int, int> min_pair = curr_heap.top();
                curr_heap.pop();
                // Update the counts for all arrays that are affected.
                int num = nums[min_pair.first][min_pair.second];
                for (int i = 0; i < nums.size(); ++i) {
                    if (nums_set[i].find(num) != nums_set[i].end())
                        count[i]--;
                    if (count[i] == 0)
                        count.erase(i);
                }
        }
        
        return min_range;
    }
};
