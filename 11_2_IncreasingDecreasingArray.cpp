#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function object for min-heap.
struct Compare {
	bool operator() (const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
		return get<1>(a) > get<1>(b);
	}
};

// Sort a k-increasing-decreasing array.
void sort(const vector<vector<int>>& in, vector<int>& out) {
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> queue;
	for (int i = 0; i < in.size(); i++) {
		// Initialize the min-heap with the first elements from each sorted array.
		if (in[i].size() > 0) {
			queue.emplace(i, in[i][0], 1);
		}
	}

	while (!queue.empty()) {
		const tuple<int, int, int>& elem = queue.top();
		int arr = get<0> (elem);
		int val = get<1> (elem);
		int next_idx = get<2> (elem);
		queue.pop();
		out.push_back(val);

		// Insert next number from the obtained array.
		if (next_idx < in[arr].size()) {
			queue.emplace(arr, in[arr][next_idx], next_idx+1);
		}
	}
}

int main() {
	vector<vector<int>> input = {{57, 131, 493}, {221, 294}, {339, 418, 452}, {190, 442}};
	vector<int> output;
	sort(input, output);
	cout << "Sorted array: ";
	for (auto x : output) {
		cout << x << " ";
	}
	cout << endl;
	
	return 0;
}
