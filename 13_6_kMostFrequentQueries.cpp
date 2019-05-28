#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

struct CustomCompare {
	bool operator() (const pair<string, int>& a, const pair<string, int>& b) const {
		return (a.second > b.second);
	}
};

// Time O(n + mlgk). Space O(m), where m is the number of distinst strings.
vector<string> k_most_frequent(const vector<string>& arr, int k) {
	unordered_map<string, int> count;
	
	for (const string& s : arr) {
		count[s]++;
	}

	unordered_map<string, int>::iterator it = count.begin();
	priority_queue<pair<string, int>, vector<pair<string, int>>, CustomCompare> min_heap;
	for (int i = 0; i < k; ++i) {
		if (it != count.end()) {
			min_heap.emplace(*it);
			++it;
		}
	}

	for (; it != count.end(); ++it) {
		if (it->second > min_heap.top().second) {
			min_heap.pop();
			min_heap.emplace(*it);
		}
	}

	vector<string> ret;
	while (!min_heap.empty()) {
		ret.emplace_back(min_heap.top().first);
		min_heap.pop();
	}
	
	return ret;
}

int main() {
	vector<string> arr{"haha", "keke", "meomeo", "hihi", "haha", "hoho", "kiki", "hihi", "kaka", "kaka", "keke", "haha"};
	int k = 3;
	vector<string> ret = k_most_frequent(arr, k);
	cout << "Input: ";
	for (string& s : arr) {
		cout << s << " ";
	}
	cout << endl;

	cout << "Output: ";
	for (string& s : ret) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}
