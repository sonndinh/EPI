#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <utility>
using namespace std;

class Solution {
public:
    struct Compare {
        vector<vector<int>>& nums;
        Compare(vector<vector<int>>& _nums) : nums(_nums) {}
        
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
            return nums[a.first][a.second] > nums[b.first][b.second];
        }
    };

	// This implementation exceeded time limit.
	// Time O(n(lgn + k)) where n is the total number of elements, k is the number of arrays.
	// Space O(n) since we need a priority queue that contains all numbers and k hash sets for k arrays.
    vector<int> smallestRange2(vector<vector<int>>& nums) {
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

	// Time O(nlgk) where n is the total number of numbers, k is the number of arrays.
	// Space O(k) since we only maintain a priority queue with k numbers, one from each array.
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // A min heap containing 1 element from each array. 
        // A top element is add to the considered range.
        Compare comp(nums);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> min_heap(comp);
        // Track the maximum element of the range.
        int max = numeric_limits<int>::min();
        int min = numeric_limits<int>::max();
        
        // Insert the first element from each array to the min heap.
        for (int i = 0; i < nums.size(); ++i) {
            if (!nums[i].empty()) {
                min_heap.push({i, 0});
                if (nums[i][0] > max) {
                    max = nums[i][0];
                }
                if (nums[i][0] < min) {
                    min = nums[i][0];
                }
            }
        }
        vector<int> range{min, max};
        int diff = max - min;
        
        while (!min_heap.empty()) {
            // Pop the smallest element and push the next element from the same array.
            pair<int, int> top_elem = min_heap.top();
            min_heap.pop();
            int arr_idx = top_elem.first; // Index of the array.
            int elm_idx = top_elem.second; // Index of the element in that array.
            
            if (elm_idx < nums[arr_idx].size() - 1) {
                min_heap.push({arr_idx, ++elm_idx});
                if (nums[arr_idx][elm_idx] > max) {
                    max = nums[arr_idx][elm_idx];
                }
                
                // Update range if it is smaller.
                int tmp = nums[min_heap.top().first][min_heap.top().second];
                if (max - tmp < diff) {
					diff = max - tmp;
                    range[0] = tmp;
                    range[1] = max;
                }
            } else {
                // Run out of range of this array.
                break;
            }
        }
        
        return range;
    }

};

int main() {
	vector<vector<int>> nums{{-5,-4,-3,-2,-1,1},{1,2,3,4,5}};
	Solution sol;
	auto ret = sol.smallestRange(nums);
	cout << "Smallest range: [" << ret[0] << ", " << ret[1] << "]" << endl;
	return 0;
}
