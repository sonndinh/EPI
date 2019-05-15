#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int begin, end;
	Interval(int b, int e) : begin(b), end(e) {}
};

// Return the maximum number of concurrent events.
int max_concurrent_events(const vector<Interval>& events) {
	int n = events.size();
	vector<int> begins(n), ends(n);
	for (int i = 0; i < n; ++i) {
		begins[i] = events[i].begin;
		ends[i] = events[i].end;
	}
	
	// Sort the intervals by their start times and end times.
	sort(begins.begin(), begins.end());
	sort(ends.begin(), ends.end());

	int i = 0, j = 0;
	int ret = 0;
	for (int i = 0, j = 0; i < n && j < n; ) {
		if (begins[i] <= ends[j]) {
			++ret;
			++i;
		} else {
			--ret;
			++j;
		}
	}

	return ret;
}

int main() {
	vector<Interval> events{{1, 5}, {6, 10}, {11, 13}, {14, 15}, {2, 7}, {8, 9}, {12, 15}, {4, 5}, {9, 17}};
	int ret = max_concurrent_events(events);
	cout << "Max concurrent events: " << ret << endl;
	return 0;
}
