#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function operator for min-heap.
struct Compare {
	bool operator() (int a, int b) {
		return a > b;
	}
};

void sort(const vector<int>& in, vector<int>& out, int k) {
	priority_queue<int, vector<int>, Compare> queue;

	for (int i = 0; i <= min((size_t)k, in.size()-1); i++) {
		queue.emplace(in[i]);
	}

	int next_idx = k + 1;
	while(!queue.empty()) {
		const int& val = queue.top();
		out.push_back(val);
		queue.pop();
		if (next_idx < in.size()) {
			queue.emplace(in[next_idx]);
		}
		++next_idx;
	}
}

int main() {
	vector<int> input = {3, -1, 2, 6, 4, 5, 8};
	vector<int> output;
	sort(input, output, 2);
	cout << "Sorted array: ";
	for (auto x : output) {
		cout << x << " ";
	}
	cout << endl;
	
	return 0;
}
