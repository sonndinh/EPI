#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;

// Return all unique quadruplets that sum to k.
// O(n^3) implementation.
vector<vector<int>> quadruplet(vector<int>& arr, int k) {
	vector<vector<int>> ret;
	if (arr.size() < 4) return ret;
   
	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < arr.size() - 3; i++) {
		if (i > 0 && arr[i] == arr[i-1]) {
			continue;
		}
		for (int j = i + 1; j < arr.size() - 2; j++) {
			if (j > i + 1 && arr[j] == arr[j-1]) {
				continue;
			}

			int remain = k - arr[i] - arr[j];
			for (int s = j + 1, e = arr.size() - 1; s < e;) {
				if (arr[s] + arr[e] == remain) {
					ret.emplace_back(vector<int>{arr[i], arr[j], arr[s], arr[e]});
					while (++s < e && arr[s] == arr[s-1]);
				} else if (arr[s] + arr[e] > remain) {
					e--;
				} else {
					s++;
				}
			}
		}
	}
	
	return ret;
}

// Use a hashmap to store all sums of 2 numbers.
// Time complexity: O(n^2). Space complexity: O(n^2).
// NOTE: result containing duplicated elements in the input array,
// so it does NOT do exactly what this problem asks for.
vector<vector<int>> quadruplet2(vector<int>& arr, int k) {
	vector<vector<int>> ret;
	if (arr.size() < k) return ret;

	// Map a value to a list of pairs that sum to that value.
	unordered_map<int, vector<vector<int>>> table;
	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size()-1; i++) {
		if (i > 0 && arr[i] == arr[i-1]) continue;
		for (int j = i+1; j < arr.size(); j++) {
			if (j > i+1 && arr[j] == arr[j-1]) continue;
			int sum = arr[i] + arr[j];
			if (table.find(k - sum) != table.end()) {
				// Find pairs that sum to the complement of this pair.
				vector<vector<int>>& tmp = table[k-sum];
				for (vector<int>& p : tmp) {
					ret.emplace_back(vector<int>{p[0], p[1], arr[i], arr[j]});
				}
			}
			
			// Add the current pair to the list of pairs for the corresponding sum.
			table[sum].emplace_back(vector<int>{arr[i], arr[j]});
		}
	}

	return ret;
}

int main() {
	vector<int> arr{1, 0, -1, 0, -2, 2};
	int k = 0;
	auto ret = quadruplet(arr, k);
	for (auto& vec : ret) {
		cout << "[";
		for (int a : vec) {
			cout << a << ",";
		}
		cout << "]" << endl;
	}
	return 0;
}
