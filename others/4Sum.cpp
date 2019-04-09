#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// Return all unique quadruplets that sum to k.
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
