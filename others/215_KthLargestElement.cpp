#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    // Return the correct index for the first element.
    int partition(vector<int>& nums, int s, int e) {
        int x = nums[s];
        swap(nums[s], nums[e]);
        int i = s-1; // Index of the last element <= x visited so far.
        for (int j = s; j < e; ++j) {
            if (nums[j] <= x) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[++i], nums[e]);
        return i;
    }

	void print(vector<int>& nums, int i, int j) {
		for (; i <= j; i++) {
			cout << nums[i] << " ";
		}
		cout << "|| ";
	}
	
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0, end = (int)nums.size() - 1;
        while (start < end) {
            int i = partition(nums, start, end);
			print(nums, start, i);
			print(nums, i+1, end); cout << endl;
			
            int count = end - i + 1;
            if (count == k) 
                return nums[i];
            if (count > k) {
                start = i + 1;
            } else {
				k -= count;
                end = i - 1;
            }
        }
        
        return nums[start];
    }
};

int main() {
	Solution sol;
	vector<int> nums{7,6,5,4,3,2,1,0};
	int ret = sol.findKthLargest(nums, 3);
	cout << ret << endl;
	return 0;
}
