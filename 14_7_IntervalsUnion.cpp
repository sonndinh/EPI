#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int begin, end;
	bool l_closed, r_closed; // Is it closed on left or right end.
	
	bool operator< (const Interval& that) const {
		// For equal begin times, closed begin time is considered smaller than open one.
		return begin != that.begin ? begin < that.begin : (begin.l_closed);
	}
};

vector<Interval> intervals_union(vector<Interval>& intervals) {
	vector<Interval> ret;
	sort(intervals.begin(), intervals.end());
	
	Interval curr = intervals[0];
	for (int i = 1; i < intervals.size(); ++i) {
		Interval& temp = intervals[i];
		if (temp.begin < curr.end || (temp.begin == curr.end && curr.r_closed && temp.l_closed)) {
			// Merge this interval to the current union of intervals.
			if (curr.end < temp.end) {
				curr.end = temp.end;
				curr.r_closed = temp.r_closed;
			} else if (curr.end == temp.end && temp.r_closed) {
				curr.r_closed = temp.r_closed;
			}
		} else {
			// We need a new union of intervals.
			ret.push_back(curr);
			curr = temp;
		}

		if (i == intervals.size()-1)
			ret.push_back(curr);
	}
	
	return ret;
}

int main() {
	return 0;
}
