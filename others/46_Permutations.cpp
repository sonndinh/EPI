#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void permute_helper(vector<vector<int>>& ret, vector<int>& nums, int i) {
		// NOTE: if we don't cast nums.size() to int, when nums.size() is 0 and i == 0,
		// the code inside this if will not run and cause stack overflow.
        if (i >= (int)nums.size()-1) {
            ret.emplace_back(nums);
            return;
        }
		
		permute_helper(ret, nums, i+1);
        for (int j = i+1; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            permute_helper(ret, nums, i+1);
            swap(nums[i], nums[j]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        permute_helper(ret, nums, 0);
        return ret;
    }
};

int main() {
	vector<int> nums{1,2,3};
	Solution sol;
	auto ret = sol.permute(nums);

	for (auto& arr : ret) {
		cout << "(";
		for (int i : arr) {
			cout << i << " ";
		}
		cout << "), ";
	}
	cout << endl;
	return 0;
}
