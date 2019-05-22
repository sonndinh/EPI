#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Interval {
	int left, right;
};

struct EndPoint {
	int time;
	int id;
	bool isLeft;
	
	bool operator<(const EndPoint& that) const {
		return (time != that.time? time < that.time : isLeft);
	}
};

// Compute the minimum number of numbers that cover the intervals.
int min_cover(const vector<Interval>& A) {
	vector<EndPoint> points(2*A.size());
	for (int i = 0; i < A.size(); ++i) {
		points[2*i] = {A[i].left, i, true};
		points[2*i+1] = {A[i].right, i, false};
	}
	sort(points.begin(), points.end());
	
	unordered_set<int> bag;
	int ret = 0;
	for (EndPoint& p : points) {
		if (p.isLeft) {
			bag.insert(p.id);
		} else if (bag.count(p.id) > 0){
			++ret;
			bag.clear();
		}
	}

	return ret;
}

int main() {
	//	vector<Interval> A{{0, 3}, {2, 6}, {3, 4}, {6, 9}};
	vector<Interval> A{{1,2}, {2,3}, {3,4}, {2,3}, {3,4}, {4,5}};
	cout << "Minimum interval covering: " << min_cover(A) << endl;
	return 0;
}
