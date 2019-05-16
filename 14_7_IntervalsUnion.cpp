#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int begin, end;
	bool l_closed, r_closed; // Is it closed on left or right end.
	
	bool operator< (const Interval& that) const {
		// For equal begin times, closed begin time is considered smaller than open one.
		return begin != that.begin ? begin < that.begin : l_closed;
	}
};

vector<Interval> intervals_union(vector<Interval>& intervals) {
	vector<Interval> ret;
	sort(intervals.begin(), intervals.end());
	
	Interval curr = intervals[0];
	for (int i = 1; i < intervals.size(); ++i) {
		Interval& temp = intervals[i];
		//		if (temp.begin < curr.end || (temp.begin == curr.end && curr.r_closed && temp.l_closed)) {
		if (temp.begin <= curr.end) {
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
	vector<Interval> intervals{{0, 3, false, false}, {5, 7, true, false}, {9, 11, false, true}, {12, 14, true, true},
							   {1, 1, true, true}, {3, 4, true, false}, {7, 8, true, false}, {12, 16, false, true},
							   {2, 4, true, true}, {8, 11, true, false}, {13, 15, false, false}, {16, 17, false, false}};
	vector<Interval> ret = intervals_union(intervals);
	for (Interval& i : ret) {
		cout << (i.l_closed? "[" : "(") << i.begin << ", " << i.end << (i.r_closed? "]" : ")") << endl;
	}
	
	return 0;
}
