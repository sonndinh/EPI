#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool threesum(vector<int>& arr, int t) {
	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < arr.size(); i++) {
		int remain = t - arr[i];
		int p = i, q = arr.size() - 1;
		for (; p <= q;) {
			if (arr[p] + arr[q] == remain) {
				return true;
			} else if (arr[p] + arr[q] < remain) {
				++p;
			} else {
				--q;
			}
		}
	}
	return false;
}

int main() {
	vector<int> arr{0,1,28,3,4,5,16,7,81,9,10,11,12,5};
	int t = 100;
	bool ret = threesum(arr, t);
	cout << "3-tuple " << (ret? "exist!" : "NOT exist!") << endl;
	return 0;
}
