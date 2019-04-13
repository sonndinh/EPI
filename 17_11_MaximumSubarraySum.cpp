#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Return the subarray with maximum sum from a circular array.
pair<int, int> max_sum(const vector<int>& arr) {
	// The idea is to find the subarrays with minimum and maximum sum
	// assuming the array is not circular. The maximum subarray in the
	// circular array is then the maximum among the obtained maximum
	// subarray and the complement of the minimum subarray from the previous step.
	int sum = 0, min_sum = 0, max_sum = 0;
	int min_sum_wrap = 0, max_sum_wrap = 0;
	int min_idx = -1, max_idx = -1;
	pair<int, int> range(0, 0), range_wrap(0, 0);
	
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
		if (sum < min_sum) {
			min_sum = sum;
			min_idx = i;
		}
		if (sum - min_sum > max_sum) {
			max_sum = sum - min_sum;
			range = {min_idx + 1, i + 1};
		}

		if (sum > max_sum_wrap) {
			max_sum_wrap = sum;
			max_idx = i;
		}
		if (sum - max_sum_wrap < min_sum_wrap) {
			min_sum_wrap = sum - max_sum_wrap;
			range_wrap = {(i + 1)%arr.size(), max_idx + 1};
		}
	}

	if (max_sum > sum - min_sum_wrap) {
		return range;
	} else {
		return range_wrap;
	}
}

int main() {
	vector<int> arr{904, 40, 523, 12, -335, -385, -124, 481, -31};
	pair<int, int> ret = max_sum(arr);
	cout << "Maximum subarray in a circular array: [" << ret.first << ", " << ret.second-1 << "]" << endl;
	return 0;
}
