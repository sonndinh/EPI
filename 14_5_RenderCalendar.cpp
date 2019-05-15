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
	int curr_concurrent_events = 0, max_concurrent_events = 0;
	for (int i = 0, j = 0; i < n && j < n; ) {
		if (begins[i] <= ends[j]) {
			++curr_concurrent_events;
			max_concurrent_events = max(curr_concurrent_events, max_concurrent_events);
			++i;
		} else {
			--curr_concurrent_events;
			++j;
		}
	}

	return curr_concurrent_events;
}

int main() {
	vector<Interval> events{{1, 5}, {6, 10}, {11, 13}, {14, 15}, {2, 7}, {8, 9}, {12, 15}, {4, 5}, {9, 17}};
	int ret = max_concurrent_events(events);
	cout << "Max concurrent events: " << ret << endl;
	return 0;
}
